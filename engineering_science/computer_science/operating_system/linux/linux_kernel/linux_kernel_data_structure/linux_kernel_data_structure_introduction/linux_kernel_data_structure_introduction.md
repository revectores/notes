# Linux Kernel Data Structure Introduction

Linux kernel implements some general-purpose data structures for kernel development:

- Linked List (doubly cycle linked list).
- Queue (FIFO).
- Map
- Red-black tree.
- Radix tree.

Most of them are defined in [`/include/linux`](https://github.com/torvalds/linux/tree/master/include/linux).

These data structures can be considered as the extracted pointer field(s) of their container. For instance, we extract the pointers in `counter` struct to dependent `list_node` struct:

```c
struct counter {
	int val;
	struct counter *prev;
	struct counter *next;
}
```

```c
struct list_node {
	struct list_node *prev;
	struct list_node *next;

}

struct counter {
	int val;
	struct list_node* list_node;
}
```

This approach make the data structure (with its operations) only need to be implemented once and can be included by any containers. We move among containers by moving among their sub-field, for instance, `list_node` in this example.

The address of container can be easily computed by substracting offset from `list_node`, `offsetof` and `container_of` macros are defined ==mutiple times(why?)== in Linux kernel:

The typical definition `offsetof` is in `/include/linux/stddef.h`:

```{.c .numberLines startFrom="22" filename="linux-5.12.1/include/linux/stddef.h"}
#undef offsetof
#ifdef __compiler_offsetof
#define offsetof(TYPE, MEMBER) __compiler_offsetof(TYPE, MEMBER)
#else
#define offsetof(TYPE, MEMBER) ((size_t)&((TYPE *)0)->MEMBER)
#endif
```

Note the "zero pointer dereference":

```c
&((TYPE *)0)->MEMBER
```

The fact is there is no any zero pointer dereference here. The compiler simply "expand the struct macro", that is, find the offset of `MEMBER` in `struct TYPE` and add it to the address of struct, which is 0 here. Now you find this approach is actually somehow brute to force the compiler to tell its knowledge by an extra meaningless addition operation(though it can absolutely be optimized). As you may notice, the `__compiler_offsetof` macro supported by compiler is a far more elegant solution.

Based on `offsetof` macro now we can define `container_of`:

```{.c .numberLines startFrom="700" filename="linux-5.12.1/include/linux/kernel.h"}
/**
 * container_of - cast a member of a structure out to the containing structure
 * @ptr:	the pointer to the member.
 * @type:	the type of the container struct this is embedded in.
 * @member:	the name of the member within the struct.
 *
 */
#define container_of(ptr, type, member) ({				\
	void *__mptr = (void *)(ptr);					\
	BUILD_BUG_ON_MSG(!__same_type(*(ptr), ((type *)0)->member) &&	\
			 !__same_type(*(ptr), void),			\
			 "pointer type mismatch in container_of()");	\
	((type *)(__mptr - offsetof(type, member))); })
```

It is not hard to imagine that `container_of` is a danger operation just like `free(3)`. Hence type check is made here to provide security in some degree.

