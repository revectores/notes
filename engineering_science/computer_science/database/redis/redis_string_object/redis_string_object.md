# Redis String Object

### 1. Redis String Object Encoding Types

##### # Encoding methods of String Object

There are three internal encoding for `string` object:

- `int` for numerical string within range of C `long `.
- `embstr` for short string. More precisely, those strings less or equal than 44 characters after Redis 3.2, less or equal than 39 characters before Redis 3.2. This modification is caused by the optimization of SDS data structure introduced in Redis 3.2. Refer to the section [3. Simple Dynamic String After Redis 3.2](#simple-dynamic-string-after-redis-3.2) for the details.
- `raw` for long string.

Use the `object encoding` command to check the encoding of an object (more precisely, the value object corresponding the given key):

```redis
> set count 1
> set name "Robert"
> set story "Redis is an open source (BSD licensed), in-memory data structure store, used as a database, cache and message broker."

> object encoding count
"int"
> object encoding name
"embstr"
> object encoding story
"raw"
```



##### # Encoding Conversion

If some operations we made which convert the `int`-encoded string object into a string, that string object will be automatically convert to `raw`-encoded, for example, any append operation, even if you append a number, will make the string object `raw`:

```redis
> set count 1
> append count 0
> object encoding count
"raw"
```

The `embstr` is desigend to be constant. i.e. no modification operation is supported to `embstr`. When we try to modify a string object eocded in `embstr`, Redis first convert it into `raw`, then exectue required operations:

```redis
> set str "abc"
> append str d
> object encoding str
"raw"
```

That is, both `int` and `embstr` could both be converted to `raw`, and other conversions among will not occur.







### 2. Simple Dynamic String in Redis 3.0

##### # Simple Dynamic String: Data Structure

The string representation in Redis is simply a refined `char*`:

```{.c .numberLines startFrom="39" filename="redis-3.0.0/src/sds.h"}
typedef char *sds;
```

Before Redis 3.2, a straightforward struct `sdshdr` is constructed as the header of SDS:

```{.c .numberLines startFrom="41" filename="redis-3.0.0/src/sds.h"}
struct sdshdr {
    unsigned int len;
    unsigned int free;
    char buf[];
};
```

That is, a `sdshdr` is constructed by three components: `len` for the length of string, and `free` for the number of unused bytes, and`char buf[]` for pointer to the string. Note that `sds` kept the tailing `\0` in `buf` to kept the compatibility with C string. Although `strlen()` is provided in `<string.h>`, the time complexity $O(n)$ by interating the entire string to find the `\0` are too high to accept. Similar to the implementation of object in Python, since the length information are considered as a frequently-queried property, it is just recorded as a struct member.

The `sdshdr` is placed right before the string `buf`, to retrive the string length from `sds`, we substract the header size from the pointer to get the start of header struct: (which is a common programming pattern in C)

```{.c .numberLines startFrom="47" filename="redis-3.0.0/src/sds.h"}
static inline size_t sdslen(const sds s) {
    struct sdshdr *sh = (void*)(s-(sizeof(struct sdshdr)));
    return sh->len;
}
```



##### # Simple Dynamic String: Memory Management

Since Redis is a database, where the data can be modified frequently, the design of memory allocation must be as efficient as possible, **preallocation** and **lazy-free** mechanism are introduced for that propose, similar to the design of container in C++ STL, the core idea is the spatial locality: data that has been modified might be modified again soon, so we preallocate and defer free operation to reduce the further malloc:

```{.c .numberLines startFrom="34" filename="redis-3.0.0/src/sds.h"}
#define SDS_MAX_PREALLOC (1024*1024)
```


```{.c .numberLines startFrom="123" filename="redis-3.0.0/src/sds.c"}
/* Enlarge the free space at the end of the sds string so that the caller
 * is sure that after calling thi function can overwrite up to addlen
 * bytes after the end of the string, plus one more byte for nul term.
 *
 * Note: this does not change the *length* of the sds string as returned
 * by sdslen(), but only the free buffer space we have. */
sds sdsMakeRoomFor(sds s, size_t addlen) {
    struct sdshdr *sh, *newsh;
    size_t free = sdsavail(s);
    size_t len, newlen;

    if (free >= addlen) return s;
    len = sdslen(s);
    sh = (void*) (s-(sizeof(struct sdshdr)));
    newlen = (len+addlen);
    if (newlen < SDS_MAX_PREALLOC)
        newlen *= 2;
    else
        newlen += SDS_MAX_PREALLOC;
    newsh = zrealloc(sh, sizeof(struct sdshdr)+newlen+1);
    if (newsh == NULL) return NULL;

    newsh->free = newlen - len;
    return newsh->buf;
}
```

More precisely, the maximum space prelocation `SDS_MAX_PREALLOC` is set to 1MB, if the size of space needed for new string is less than 1MB, we double it, otherwise add 1MB. The appended `1` is used for tailing `\0`.

For instance, for the following operations:

```redis
> set str "Hello"
> append str " World!"
```

At first the string contains only 5 chars (5 Bytes), then we requires to add 7 chars, the `newlen` now should be 12, and since it has not exceeded 1MB, we double the newlen, hence after the preallocation and string concatenation the members have values `len = 24` and `free=12`.



##### # Simple Dynamic String: Library Reuse

The `sds` is no more than a `char*`, hence all the string operations can be reuse in sds (theorectially), excpet those might cause performance problems such as `strlen`.







### 3. Simple Dynamic String in Redis 6.0

This section use Redis 6.0.9 as the example. (the newest version of Redis up to 2020.10.31)



##### # Simple Dynamic String: Data Structure Optimization

After Redis 3.2, The optimization of `sds` space usage is introduced, now there are multiple version of header struct for different size of `sds`:


```{.c .numberLines startFrom="47" filename="redis-6.0.9/src/sds.h"}
/* Note: sdshdr5 is never used, we just access the flags byte directly.
 * However is here to document the layout of type 5 SDS strings. */
struct __attribute__ ((__packed__)) sdshdr5 {
    unsigned char flags; /* 3 lsb of type, and 5 msb of string length */
    char buf[];
};
struct __attribute__ ((__packed__)) sdshdr8 {
    uint8_t len; /* used */
    uint8_t alloc; /* excluding the header and null terminator */
    unsigned char flags; /* 3 lsb of type, 5 unused bits */
    char buf[];
};
struct __attribute__ ((__packed__)) sdshdr16 {
    uint16_t len; /* used */
    uint16_t alloc; /* excluding the header and null terminator */
    unsigned char flags; /* 3 lsb of type, 5 unused bits */
    char buf[];
};
struct __attribute__ ((__packed__)) sdshdr32 {
    uint32_t len; /* used */
    uint32_t alloc; /* excluding the header and null terminator */
    unsigned char flags; /* 3 lsb of type, 5 unused bits */
    char buf[];
};
struct __attribute__ ((__packed__)) sdshdr64 {
    uint64_t len; /* used */
    uint64_t alloc; /* excluding the header and null terminator */
    unsigned char flags; /* 3 lsb of type, 5 unused bits */
    char buf[];
};
```

Now for those `sds` whose length is less than $2^{8}$, the header save `2 * (sizeof(unsigned int) - sizeof(unit8_t)) + sizeof(unsigned char) ` = 2 * (4 - 1) + 1 = 5 Bytes, note that all the `embstr` must has length less than $2^8$, those bytes saved becomes the addition of boundary between `embstr` and `raw`.

This design optimized the space usage when there are amounts of small strings.

To support these various headers, some C meta-programming techniques must be applied, for instance, to get the member `len` in the header, we have to compute the start address of the header case by case:

```{.c .numberLines startFrom="84" filename="redis-6.0.9/src/sds.h"}
#define SDS_HDR(T,s) ((struct sdshdr##T *)((s)-(sizeof(struct sdshdr##T))))
#define SDS_TYPE_5_LEN(f) ((f)>>SDS_TYPE_BITS)

static inline size_t sdslen(const sds s) {
    unsigned char flags = s[-1];
    switch(flags&SDS_TYPE_MASK) {
        case SDS_TYPE_5:
            return SDS_TYPE_5_LEN(flags);
        case SDS_TYPE_8:
            return SDS_HDR(8,s)->len;
        case SDS_TYPE_16:
            return SDS_HDR(16,s)->len;
        case SDS_TYPE_32:
            return SDS_HDR(32,s)->len;
        case SDS_TYPE_64:
            return SDS_HDR(64,s)->len;
    }
    return 0;
}
```

