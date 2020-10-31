# Redis

### 1. Redis Introduction

##### # What is Redis

**Redis** is one of the key-value database (formally classfied as NoSQL database). That is, you store the key-value pair in the database, and use the key to retrieve value in the future:

```redis
> set person:name "robert"
(OK)
> get person:name
"robert"
```

Redis provides bulit-in support for complex data structure.

All the Redis operations are **atomic**.



##### # Redis Object Types

Redis supports five types of objects:

- String object.
- List object.
- Hash object.
- Set object.
- Ordered set object.

The distinguishment of objects provide the ability to check whether a given command is valid on that key.

Note that the object interfaces are not the real data structure of the internal implementation:

- Different values in the same object might be stored as different data structure internally to improve efficiency. For instance, there are no explicit integer object in Redis, but if a string is a numerical string in range of `long`, that string object will be stored as integer type. Refer to [redis_string_object](/Users/rex/Library/Mobile Documents/com~apple~CloudDocs/skill/notes/engineering_science/computer_science/database/redis/redis_string_object/redis_string_object.md) for more details about implementation of string object.
- Values in different object types might share the same data structure, reusing the general design.

Another benefit raises for the backward compatibility. The implementation of object might be modified but the interface kept. For example, before Redis 3.2 the list object is implemented by `ziplist` or `linkedlist`, depending on the values in list, but Redis 3.2 create a general data structure `quicklist` in place of both. Refer to [redis_list_object](/Users/rex/Library/Mobile Documents/com~apple~CloudDocs/skill/notes/engineering_science/computer_science/database/redis/redis_list_object/redis_list_object.md) for more details about implementation of list object.

The naming of commands are based on the type, except the most basic object type `string`(which can be the members of other objects), for the `list`, `hash`, `set` and `oredered set`, a leading `l`, `h`, `s`, and `z` is prepended to (most of) the name to distinguish the operation target object.







### 2. Redis String

##### # Redis Numerical String Increment and Decrement

Use `incr <key>` and `decr <key>` to increase/decrease the value by 1. The returned value is the new value in the key after increment/decrement:

```redis
> set connections 10
> incr connections
(integer) 11
> decr connections
(integer) 10
```

It can be applied to unexists key, in this case a new key will be created:

```redis
> exists counts
(integer) 0
> incr coutns
(integer) 1
```

Generally, use `incrby <key> <value>` and `decrby <key> <value>` to increase/decrease the key by given values.

Note that the stored value itself is always a string object, not integer, since there is no integer object in Redis. you can check this by `type`:

```
> get connections
"10"
> type connections
string
```

Float Increment is also supported, by `incrbyfloat`:

```redis
> set pi 3.14
> incrbyfloat pi 0.001
"3.141"
```

You won't need `decrbyfloat`, since you can set the addend as negative.



##### # Redis String Operation

Some string operation is also supported by Redis, the most useful two are `append` and `strlen`:

```redis
> set greeting "Hello"
> strlen greeting
(integer) 5
> append greeting " World!"
(integer) 12
```

The append operation returns the length of new string.



##### # Redis String Internal Implementation

Refer to [redis_string_object](/Users/rex/Library/Mobile Documents/com~apple~CloudDocs/skill/notes/engineering_science/computer_science/database/redis/redis_string_object/redis_string_object.md) for the implementation of Redis string object.







### 3. Redis List

We create a list by push items from left/right directly:

```
> rpush editors sublime clion
(integer) 2
> lpush editors vim
(integer) 3
```

and we list the items by `lrange` or `lrange`, get the length of list by `llen`:

```redis
> lrange editors 0 -1
1) "vim"
2) "sublime"
3) "clion"

> lrange editors 0 1
1) "vim"
2) "sublime"

> llen editors
(integer) 3
```

Note that the range does includes the last index.

Correspondingly, use `lpop` or `rpop` to pop item from the left/right and return it:

```redis
> lpop editors
"vim"
> rpop editros
"clion"
> llen editors
(integer) 1
```

Refer to [redis_list_object](/Users/rex/Library/Mobile Documents/com~apple~CloudDocs/skill/notes/engineering_science/computer_science/database/redis/redis_list_object/redis_list_object.md) for the implementation of Redis list object.







### 4. Redis Hash

Hash is associative list.

```redis
> hset user:1000 name "robert"
(integer) 1
> hmset user:1000 pwd "password" email "robert@gmail.com"
(integer) 1

> hget user:1000 name
"robert"
> hgetall user:1000
1) "name"
2) "robert"
3) "pwd"
4) "password"
5) "email"
6) "robert@gmail.com"
```

To increase/decrease the number in hash value, use `hincrby`. There is no `hincr`/`hdecr`/`hdecrby`, and you do not need them.

```redis
> hset user:1000 visits 10
(integer) 1
> hincrby user:1000 visits 1
(integer) 11
```







### 5. Redis Set

Use `SADD` to add elements to set (since it is set, duplicated iterms will be automatically removed), and list the members by `SMEMBERS`, check whether value is a member by `SISMEMBER`:

```redis
> sadd langs c c++
(integer) 2
> sadd langs c go
(integer) 1
> smembers langs
1) "go"
2) "c"
3) "c++"
> sismember langs java
(integer) 0
```

remove elements by `SREM`, the return value indicates whether the value is in the set:

```redis
> srem langs go
(integer) 1
> srem langs java
(integer) 0
```

We can union two set by `SUNION`:

```redis
> sadd alphabet a b c
> sunion langs alphabet
1) "a"
2) "c"
3) "go"
4) "c++"
5) "b"
```

Since the set is unordered data structure, no direction can be specified by `SPOP`, so random element will be popped and returned. The difference to list pop is, we can specify how many elements should be popped:

```redis
> spop langs
"c"
> spop alphabet 2
1) "a"
2) "b"
> spop alphabet 3
1) "c"
> spop alphabet 3
(empty array)
```

As shown, if the number is larger than the elements in the set, no error will raise and the set only returnes all it can.

There is another method returns the random elements in set but not delete them, called `SRANDMEMBER`, the interesting part of this command is, a negative number can be used to accept duplicated items:

```redis
> sadd alphabet a b c
> srandmember alphabet
1) "b"
> srandmember alphabet -5
1) "a"
2) "c"
3) "c"
4) "b"
5) "c"
```







### 6. Redis Ordered Set

The set structure would be handy in some cases if its ordered, that's why Redis 1.2 introduced the sorted sets. A ordered set is ordered by the associated score:

```redis
> zadd tasks 0 homework
(integer) 1
> zadd tasks 10 running
(integer) 1
> zadd tasks -5 sleep
(integer) 1
> zrange tasks 0 -1
1) "sleep"
2) "homework"
3) "running"
```

 





### 7. Redis Expire Mechanism

We can set the expire time of a key-value pair use `expire` (in seconds) and `pexpire` (in milliseconds), or by the additional argument in `set`:

```redis
set resource:temp "Temporary value"
expire resource:temp 10
set resource:temp2 "Another temporary value" ex 100
```

Use `ttl` (in seconds) or `pttl` (in milliseconds) to check the left avaliable:

```redis
ttl resource:temp => 2
// after 2 seconds
ttl resource:temp => -2
exists resource:temp => 0

set resource:permanent "Permanent value"
ttl resource:permanent => -1
```

The `-2` indicates that the key no longer exists, as if it is never created, and `-1` indicates the value is permanent (when no expire time is assigned).

Command `persist` makes the key permanent:

```redis
persist resource:temp2
ttl resource:temp2 => -1
```

The `set` operation will override the expire time set before (make it persist by default or based on the `ex` in set).

