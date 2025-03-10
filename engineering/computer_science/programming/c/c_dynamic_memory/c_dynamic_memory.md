# C Dynamic Memory 

### 1. Introduction

Any variables can be stored in two types of memory: normal variable declaration and function parameters passing will be stored in **stack memory**, the allocation and deallocation of which will be automatically handled by the complier implicitly based on variable scopes. On the contrary, for the **heap memory**, all of these management must be done explicitly by the programmer. `malloc` and `free`, are the two library functions designed for this purpose.

However, since these `glibc` memory management library are designed for general-purpose, indicating it is highly possible for them to be inefficient in specific task. Many of the applications that require high performace like [Redis](/Users/rex/Library/Mobile Documents/com~apple~CloudDocs/skill/notes/engineering_science/computer_science/database/redis/redis_mm/redis_mm.md) and [Firefox]() use the nonstandard implementation `malloc(3)` such as `jemalloc`, or implement their own memory management libraries.

Refer to []() for the implementation of `malloc` in `glibc` and []() for the nonstandard implementations.

As we'll shown, the manual memory management is absolutely the source of errors. Most of modern languages do not trust the programmers to deal with memory by themselves but garbage collection mechanism, see [python_garbage_collection]() and [java_garbage_collection]() for GC implementation in Python and Java respectively. C++11 introduces [smart pointer](/Users/rex/Library/Mobile Documents/com~apple~CloudDocs/skill/notes/engineering_science/computer_science/programming/c++/stl/stl_memory/c++_smart_pointer/c++_smart_pointer.md) to partically manage the memory by standard library. As a practice to get better understanding about memory management, we've implement our own memory management library rrmalloc, refer to []() for the source code and []() for design consideration.







### 2. Dynamic Memory Library Function

##### # `malloc` and `free`

`malloc` takes `size` as the parameter and returns a pointer to the allocated space, with enough adequate memory after, the prototype is

```c
void* malloc(size_t size); 
```

As a typical instance, consider allocating memory for a node in a linked-list:

```c
typedef struct __node {
    int val;
    struct __node* next;
} node;

node* head = (node*) malloc(sizeof(node));
```

The size will be inferred by complier by computing the size of node, which is 8 for 32-bit machine or 16 Bytes for 64-bit machine. The returned `void*` is then converted to `node*` explictly and assigend to a pointer with type `node*`. Note that as the variable assignment, the variable `head` itself is stored in the stack, but its content is an address on the heap!

When we're done with those allocated memory, we must give them back to the operating system using `free`:

```c
void* free(void *ptr);
```

to free the node we've allocated, simply `free(head)`.



##### # Common Errors About C Memory Management

Although the API interfaces are simple, complexity arised when components interact. The most common errors when dealing with the memory are listed here:

1. **Forget to allocate memory**. For instance,

    ```c
    char *src = "hello";
    char *dst;
    strcpy(dst, src);
    ```

    where the `det` has not been allocated by used.

2. **Allocate inadequate memory**.

    ```c
    char *src = "hello";
    char *dst = (char *) malloc(strlen(src));
    strcpy(dst, src);
    ```

    which is incorrect since there is an implicit `\0` in end of the C string tail, hence you must allocate one more space for that. The program above might override the byte in adjacent address, which cause undetectable error.

3. **Forget to initialize the memory**. The memory returned by `malloc` is not initialized, you must filling it with zero values manually if you wish.

4. **Forget to free memory**. This is what we called **memory leak**. It may not a big deal if the program runs just for a short time since the operating system will recall memory when the process is terminated, while for those programs running for a long time (for instances, operating system or the web server), the memory leak would eventually run out the memory in system.

    It is very difficult to gurantee all the memory are free properly, consider such a situation:

    ```c
    void foo(){
    	int* intp = (int*) malloc(sizeof(int));
        // program with error
        free(intp);
        return;
    }
    ```

    

5. **Freeing Improperly**. This includes

    - Freeing memory before done with it.
    - Freeing memory repeatedly.
    - Freeing memory not allocated by `malloc`.



