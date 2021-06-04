# C++ Allocator

As we've introduced in [C++ Dynamic Memory](/Users/rex/Library/Mobile Documents/com~apple~CloudDocs/skill/notes/engineering_science/computer_science/programming/c++/c++_core/c++_dynamic_memory/c++_dynamic_memory.md), C++ support `new/delete` pair to manage the memory in free store, which automatically invoke the contructor/destructor when allocate/deallocate the space, which can be a resource waste when allocate dynamic array. To avoid the invocation of constructor, use `allocator` to allocate the memory manually:

```c++
std::allocator<std::string> alloc;
auto const p = alloc.allocate(n);
```

At first we need to construct an allocator to particular type, which can only used to allocate the space of that type, then we invoke the `allocate` method of that allocator, here we allocated `n` uninitialized `std::string`.

The memory allocated by `allocator` is **unconstructed**, method `construct` can be used to construct element in given address:

```c++
auto q = p;
alloc.construct(q++);
alloc.construct(q++, 10, 'c');
alloc.construct(q++, "hi");
```

Once we're done with some objects (but not the entire allocated space), we use the `destroy` method, which inovke the destructor of object, to destroy them:

```c++
while (q != p) alloc.destroy(--q);
```

We can reuse those destroyed space for new elements.

Finally if the allocated space can be free, we use `deallocate` method:

```c
alloc.deallocate(p, n);
```

Three conditions must meet to use `deallocate`:

1. As all of the memory management pair, the pointer passed to `deallocate` must be returned by `allocate` previously
2. `n` must be exactly the size when we allocate
3. All of the contructed objects must be destroyed.




