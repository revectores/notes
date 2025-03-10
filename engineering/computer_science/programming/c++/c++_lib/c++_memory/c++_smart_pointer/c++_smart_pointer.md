# C++ Smart Pointer

C++11 introduces **smart pointer**, which applying **reference counting** as mechanism to implement GC.



### 1. Smart Pointer Basic Usage

##### # Smart Pointer Initialization

Standard library introduces two types of smart pointers template: `shared_ptr` and `unique_ptr`. `shared_ptr` permits multiple pointers point to the same address while `unique_ptr` does not. To initialize the smart pointer, use

```c++
shared_ptr<string> strp;
```

By which the `strp` is a new smart pointer with empty value.

There are multiple approaches to assign a smart pointer. The safest one is using `make_shared`:

```c++
shared_ptr<string> strp = make_shared<string> (5, '0');
shared_ptr<int> intp = make_shared<int>();
```

For class instance such as `string`, the parameters must match one of constructor of  `string`. For the built-in type `int`, the parameter must can be used to initialize an `int`. The object is value initialized if no parameters given. 

Since the type can be easily inferred when using `make_shared ` to create smart pointer, `auto` can be used as type.



##### # Reference Counting For Smart Pointer

As most of the garbage collection mechanism, smart pointer use reference counting to be informed of addresses which will not be used in the future.

Duplicating a `shared_ptr` increases the reference count:

- Use one `shared_ptr` to initialize another `shared_ptr`

    ```c++
    auto intp = make_shared<int>(42);
    auto intp_cpy(intp);
    ```

- Pass the `shared_ptr` to function argument.

- Return `shared_ptr` as a returned value.

Destroying a `shared_ptr` decrease the reference count:

- A `shared_ptr` variable leaves the scope.

Once the counter decrease to zero, the pointed object will be destroyed automatically by the smart pointer. More specifically, the destructor of pointed object will be invoked, and then the addresses will be free.

For instance, consider the the following scenario:

```c++
auto r = make_shared<int>(42);
r = q;
```

The `r = q` trigger three events:

- It increases the reference count of object pointed by `q`.
- It decreases the reference count of object pointed by `r`.
- Since `r` is just created, the reference count is 1, the decrement makes the reference count be zero, hence the object pointed by `r` will be destroyed.

The details about the data structure using by smart pointer is implementation-dependent.







### 2. Smart Pointer and Built-in Pointer

##### # Use Built-in Pointer to Initialize Smart Pointer

We can use the built-in pointer (returned by [`new`](/Users/rex/Library/Mobile Documents/com~apple~CloudDocs/skill/notes/engineering_science/computer_science/programming/c++/c++_core/c++_dynamic_memory/c++_dynamic_memory.md) operator) to initialize smart pointer. Note that the smart pointer constructors that take pointers are `explicit`. Hence we cannot implicitly convert a built-in pointer to a smart pointer, the direct form of initialization must be applied:

```c++
share_ptr<int> p = new int(42);	// error
share_ptr<int> p(new int(42));		// ok

share_ptr<int> clone(int p){
    return new int(p);					// error
}
share_ptr<int> clone(int p){
    return shared_ptr<int>(new int(p));	// ok
}
```



##### # Common Errors When Mixing Built-in and Smart Pointer

The `share_ptr` can only detect the reference from the copying of `share_ptr`. Hence there are multiple ways to make this mechanism void:

(1) The reference from built-in pointer could not be noticed. If we use the built-in pointer to initialize smart pointer, the former one should not be used anymore in case of the object it points to is deleted:

```c++
void process(share_ptr<int> ptr){}
int *x(new_int(42));
process(shared_ptr<int> x);
int y = *x;		// x is now a dangling pointer.
```

In this example above, the parameter passing into `process` is a temporary `share_ptr`, when the `process` returns the reference count reduced to 0 hence `x` is deleted. We must pass a persisted variable to `process` in this case.

(2) The reference from independent smart pointers (instead of from copying) could not be noticed, for example, use a built-in pointer to initialize two `share_ptr` respectively:

```c++
int i = new int(42);
auto x = share_ptr<int> i;
auto y = share_ptr<int> i;
```

or use the built-in pointer returned by `get` to initialize another smart pointer:

```c++
share_ptr<int> p(42);
int *q = p.get();
auto r = share_ptr<int> q;
```



##### # Deleter

A pointer used to initialize a smart pointer must point to the dynamic since the `delete` is the default operation when the reference counting reduced to zero. Nevertheless we can also overload the **deleter**, the operation to release resource, instead of `delete`:

```c++
void end_connection(connection *p){
    disconnect(*p);
}

connection.c = connect(&d);
share_ptr<connection> p(&c, end_connection);
```

In this example the function `end_connection` is used as the deleter when the complier decides to delete the object. This approach gurantees the object will always be deleted, no matter any exception throwed in any time.



##### # Smart Pointer and Dynamic Array

`unique_ptr` supports the management of dynamic array:

```c++
unique_ptr<int[]> ips(new int[10]);
ips.release();
```

where we use `int[]` to specify that `ips` points an array of `int`, when the recourse get released, the `unique_ptr` will invoke `delete []` to delete the dynamic array.

STL `shared_ptr` does not support management of dynamic array, but we can provide self-defined deleter to implement this manually:

```c++
shared_ptr<int> p(new int[10], [](int *p){delete[] p;});
p.reset();
```

where a [lambda function](/Users/rex/Library/Mobile Documents/com~apple~CloudDocs/skill/notes/engineering_science/computer_science/programming/c++/c++_core/c++_lambda_function/c++_lambda_function.md) is used as the deleter, hence when the pointer `p` get released, it invokes the `delete []` to delete dynamic array.








