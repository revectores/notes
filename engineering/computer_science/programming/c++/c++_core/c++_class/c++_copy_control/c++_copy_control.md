# C++ Copy Control

We can control the behaviours of class instances when copying, moving, assignment and destroying through five special member functions:

- **Copy constructor**
- **Copy-assignment operator**
- **Move constructor**
- **Move-assignment operator**
- **Destructor**

The copy constructor and move constructor define what to do when an object is **initialized** from another object of the same class. The copy-assignment operator and move-assignment operator define what to do when we assign an object of a class type to another object of the same class type. The destructor define what to do when we destroy the object. All of the five special functions are called **copy control**.







### 1. Copy Constructor and Copy-Assignment Operator

##### # Copy Constructor

A copy constructor is a member function with reference of its type as the first argument, and all other parameters have default values:

```c++
class Person {
public:
    Person();				// constructor
    Person(const Person&);	// copy constructor
};
```

Since the copy process should not change the copied object, the first parameter almost always set to be `const`. (You can image some counterexamples when the copied object want to track the copying action, for example `shared_ptr` need to increase the reference count when copied.)

The following four scenarios invoke copy constructor:

- Initialize a object using `=` or `()` from the object of the same type.
- Pass an object as an argument to a parameter of nonreference type.
- Return an object from a function that has a nonreference return type.
- Brace initialize the elements in an array or the members of an aggregate class.

Some class types use the copy constructor to initialize the objects they allocated, for example `insert ` and `push` method of containers invoke the copy constructor to do the copy initialization, on the contrary, `emplace` method use direct initialization.

If the copy constructor is not defined, the complier generates **synthesized copy constructor** automatically: It simply copying each non-static member to the new object.

- For class object member, use the copy constructor to copy.
- For built-in type member, copy directly.
- For array member, copy repeatedly with the above two rules applied.



##### # Copy-Assignment Operator

The copy-assignment operator specifies what happen when assigning an class object, we overload the `operator=` to define it. It should return the reference of the left operand.

If the copy-assignment operator is not defined explicitly, the complier generates **synthesized copy-assignment operator**, the default rules are the same as copy constructor.



##### # Explictly Synthesization

Define the copying control methods as `=default`(this can be also used for constructor) to require the complier to generate the synthesized version of any copying control methods. Same as other member functions, when we use `=default` inside the class definition, the synthesized method will be inline.



##### # Preventing Copies

There are some cases when copies are meaningless or error-prone. We can use `=delete` to prevent any invocation of a member functions, this can be used for almost all the member functions, including all copying control methods.

Note that although there is no syntax error, the destructor should not be deleted in most cases. If the destructor is deleted, we cannot destroy any object of this type, which leads to:

- The class using instance with deleted destructor as it member also cannot be destroyed.
- The complier will forbid any creation of instance variables of this class.

For some cases like this, the complier generate deleted synthesized copy control methods:

- If the destructor of some member is deleted or inaccessible (private, for instance), the synthesized destructor, copy constructor, and constructor will all be defined as deleted.

- If the copy constructor of some member is deleted or inaccessible, the synthesized copy constructor will be defined deleted.

- If the copy assignment operator is deleted or inaccessible, the synthesized copy assignment operator will be defined deleted.

- If some of the members are const or references:

    (1) The synthesized copy assignment operator will be defined deleted.

    (2) If they are not initialized inside class, and for the const, the type does not define constructor explicitly, then the construtor will be defined deleted.



##### # The Rule of Three/Five

None of the five member functions for copy control are dependent syntactically, but there are some semantic dependencies indeed:

- If some class need a destructor, it also need copy constructor and copy assignment operator.

    When a class need a destructor, which usually indicates that there are some resource handled by pointers and need to be release explicitly, which cannot be automatically handled by the synthesized version, in such case, the snythesized version of copy constructor and copy assignment operator simply copy the pointer

- If some class need a copy contructor, it also need a copy assignment operator, or vice versa.







### 2. Move Constructor and Move-Assignment Operator

##### # Rvalue Reference

To support the move operation, C++11 introduces a new type of reference - **rvalue reference**, a reference which must be assigned by a **rvalue**, a value that is going to be destroyed soon.

```c++
int i = 42;
int &r = i;				// correct
int &&rr = i;			// error
int &r2 = i * 42;		// error
const int &r3 = i * 42;	// correct
int &&rr2 = i * 42;		// correct
```

We can explicit convert the lvalue into rvalue by `std::move` function:

```c++
int &&r3 = std::move(rr1);
```

The usage of `move` implies, we wish to process a lvalue as if it is a rvalue, that is, we promise to not use `rr1` anymore except assign it with a new value or destroy it.



##### # Move Constructor

Move a object instead of copying it reduce the resource cost to duplidate memory when we intended to delete the source object right after the copying operation.

Normally no exception will be thrown during moving, since it does not allocate resource but simply stealing it from source, a `noexcept` declaration should be added after the function headline to specify this fact, and reduce the work of complier about the error handling.



##### # Move-Assignment Operator









