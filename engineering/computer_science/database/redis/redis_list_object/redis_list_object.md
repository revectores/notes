# Redis List Object

### 1. Redis List Object Encoding Types

Before Redis 3.2, the list object is implemented by `ziplist` or `linkedlist`, depending on the values in list, but Redis 3.2 create a general data structure - the combination of `ziplist` and `linkedlist`, called `quicklist`, in place of using them individually.







### 2. Redis Ziplist

In Redis 3.0, a small list that constructs by small strings is encoded by `ziplist`:

```redis
> rpush lst 1 2 3 "hello" "world"
(integer) 5
> object encoding lst
"ziplist"
```







### 3. Redis Linkedlist







### 4. Redis Quicklist



