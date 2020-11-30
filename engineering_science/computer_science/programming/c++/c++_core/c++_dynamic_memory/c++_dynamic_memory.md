# C++ Dynamic Memory

As we've introduced in [c_dynamic_memory](/Users/rex/Library/Mobile Documents/com~apple~CloudDocs/skill/notes/engineering_science/computer_science/programming/c/c_dynamic_memory/c_dynamic_memory.md), the dynamic memory management in C use the `malloc/free` pair, which can be inconvenient in C++ due to the introduction of OOP mechanism (and the simplicity of `malloc`), thus a new pair `new/delete` is introduced in C++.

The concept **free store** in C++ context represents those storage space managed by `new/delete` operator, where the storage located on the process memory model is implementation-dependent. For most of the standard library implementation which relys on `malloc`, the free memory is on the heap.



### 1. Operator `new` and `delete`

##### # `new`

We can use `new` operator to allocate space for built-in type or class object:

```c++
int *pi = new int;					// uninitialized int
std::string *ps = new std::string;	// empty string
```

without the initializer given, objects intialized by `new` are **default initialized**, that is, for built-in type or compound type have undefined value, objects of class type are initialized by their default constructor. That is, in this example above `intp` points to uninitialized int, but `strp` points to an empty string. Use empty bracket to apply value initialization:

```c++
int *pi = new int();					// 0
std::string *ps = new std::string();	// empty string
```

Note that for the class types that define their own constructors, requesting value initialization is of no consequence; regardless of form, the object initialized by the default constructor.

Use traditional construction or C++11 list initialization to initialize with explicit values:

```c++
int *pi = new int(42);
std::string *ps = new std::string(5, '0');
vector<int> *pv = new vector<int> {0, 1, 2, 3, 4};
```

We can allocate `const` object using `new`:

```c++
const int *pci = new const int(42);
const std::string *pcs = new const string;
```



##### # Exception When Memory Exhaustion

Different from `malloc`, which returns `NULL` if there is no adequate memory for the request, `new` opeartor throws `bad_alloc` exception. We can use **placement new** to let the `new` operator return a `NULL` instead:

```c
int *pi = new (nothrow) int;
```



##### # `delete`

After we've done with the object created by `new`, we delete them use `delete`. The pointer passed to `delete` must be those returned by `new`.



##### # Common Errors About C++ Memory Management

As the encapsulation of `malloc/free`, programmers face the same problems and common errors when using `new/delete`, refer to [c_dynamic_memory](/Users/rex/Library/Mobile Documents/com~apple~CloudDocs/skill/notes/engineering_science/computer_science/programming/c/c_dynamic_memory/c_dynamic_memory.md) for those common errors.







### 2. Dynamic Array

##### # `new[]`

To allocate a continuous space for multiple variables of specific type (that is, an array), use `new []` operator:

```c++
int *pia = new int[10];
```

The size must be integer but not do not has to be constant, and the object are **default initialized**, and empty bracket `()` make value initialized, same as in the `new` operator.

C++11 permits to provide an initializer:

```c++
int *pia = new int[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
std::string *psa = new std::string[10]{"1", "2", "3", std::string(3, 'x')};
```

Same as the initialization fin built-in array, the initializer will be used to initialize elements from the start. If the elements in initializer is less than the length of initialized object, other elements will be value initialized, on the contrary, if the elements in initializer exceeds the length, the `new ` operator will fail, no space get allocated, and exception `bad_array_new_length` will be thrown.

It is valid to allocate zero-length array:

```c++
int *pia = new int[0];
```

This returns a valid pointer equipped with all pointer operation except the most important one: dereference.



##### # `delete[]`

Use `delete[]` to delete the dynamic array:

```c++
int *pia = new int[10];
delete [] pia;
```

The delete process proceeds in reversed order, that is, the last element get deleted first, then the second to last, and on.

If we delete the dynamic array using `delete` without `[]`, or delete a single object pointer using `delete []`, the behaviour of program is undefined.





