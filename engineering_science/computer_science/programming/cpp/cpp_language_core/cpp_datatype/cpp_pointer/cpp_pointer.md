# Pointer

A pointer is a variable which stores the address of another variable. Although addresses are the same for different data types, the normal pointer can only point to one type of data, which indicates the type of the pointer itself.







### 1. Initialization

##### # Address and Value Achieve

Here is the simplist example of pointer declaration & assignment:

```c++
int a = 5;
int* p = &a;
```

Where the operator `&` achieves the address of int variable `a`, which is then be assigned to the newly constructed pointer `p`. Here we're able to see that `p` stores the address of an integer. We can print it to see the memory in actual:

```c++
std::cout << p; // 0x7ffee77e09f8 (This will differ in mechine and time)
```

Usually we don't do this because there's almost no meaning. The important thing is the difference between the pointers' address (for example, to construct an array) instead of the absoluate address.

To get the value of an pointer, we use the **Dereference** sign `*` :

```c++
std::cout << *p;  // 5
```

That concludes the basic usage of pointer.



##### # Two style of declaration

There's two style of declaring a pointer:

```c++
int* p;
int *p;
```

The interpreter doesn't care about the space here, you can even write it as `int * p`, but few people do this. The difference between these two styles are basically like whether the braces should be in the new line. While there's some different meaning for these two styles.

`int* p ` emphases the **type**, which try to express that the type of `p` is "a pointer to the variable whose type is `int`" . While `int *p` emphases the value of expression, which means "the expression `*p` is an integer".

Besides, each style can be easily misunderstand in some context. For example, if we rewrite the declaration and assigning code above as the second style:

```c++
int *p = &a;
```

It's quite easy to misunderstand because the expression `*p` should be an `int` instead of the address of it. `*p` should not be considered as a single notation here. 

What the first style short of exposes when multiple variable are decleared:

```c++
int* p1, p2, p3;
typeid(p1).name		// Pi
typeid(p2).name		// i
```

Here we can check further how the interpreter work: acutally it works more likely the second style, the `*` is combined with the variable name instead of the pointed type `int`, as the result if you aim to construct serval pointer it's required to write an `*` in front of every name:

```c++
int *p1, *p2, *p3;
typeid(p2).name		// Pi
```



##### # Pointer to Pointer

We can create the pointer to pointer by adding the `*` signed:

```c++
int **pp, *p, a;
p = &a;
pp = &p;
std::cout << pp;   // the address of p
std::cout << *pp;  // the value of p, which is the address of a
std::cout << **pp; // the value of a
```

As will be mentioned in [Array](Array), in the two-dimensional array, the name of array is a pointer to pointer, which points to the first element of "row dimension":

```c++
int a[10][10];
typeid(a).name;					// PPi
cout << a;              // the address of a[0]
cout << a[0] << *a;     // the address of a[0][0]
cout << a[0][0] << **a; // the value of a[0][0]
```



##### # Generic Pointer

==TODO==

```c++
void* p;
```







### 2. Pointer Calculation

It's allowed for pointer to move across the memory by the addition manipulation:

```c++
int* p;
```

==TODO==







### 3. Function Pointer

Similar to normal variable pointer, function pointer is the pointer which stores a function's address, and we can call a function by the function pointer just like what we've done to variables.

##### # Declaration

There're concepts of types for functions also. The type of a function is the combination of type of return value and type of parameters, which both require in the function declaration:

```c++
int add(int n);
```

The decleration of pointer also requires the pointed object's type, which can be written as

```c++
int (*addp)(int n);
/* Notice that the brackets around *name is necessary: Otherwise it will be recognize as (int*) add(int n), a function gets int and return int*; 
```

##### # Assignment

now, this function pointer can point to any function got the corresponding type:

```c++
int add1(int n){
  	return n + 1;
}

int add2(int n){
  	return n + 2;
}

int (*addp)(int n) = &add1;
cout << (*addp)(1);		// 2

addp = &add2;
cout << (*addp)(1);		// 3
```

Now here is the funny thing: in the modern interpreter, the name of the function and the address of it is actually the same thing. Which means we can rewrite the programs above as:

```c++
int (*addp)(int n) = add1;
cout << addp(1);		// 2

addp = add2;
cout << add2(2);		// 3
```

So the fact is we're encouraged to recognize the pointer name and function name as **almost** the same thing (well, still with slightly difference). Basicly, a funtion is the same as a **const function pointer**: `int (*const add)(int n) <=> int add(int n){}`.







### 4. Application

Why pointer is so important to learn? There're several reasons for this and more are expected to add in the list:

1. It can be nearly considered equal to the pointed element and with much smaller size. How dose this feature helps? For example, if we want to sort some data, we just need to sort their pointers, and then use the sequence of pointers to represent the sequence of raw elements. By doing so, we can avoid the costs caused by the copy and move operations of elements, which might be huge.

2. The size of it is fixed. The size of any type of pointer is only determined by the digit of addressing so all the pointer share the same size:

   ```c++
   int* pi, bool* pb, double* plf;
   sizeof(pi), sizeof(pb), sizeof(plf)  // 8
   ```

   For many data types and structures such as `array` or `map` or some user-defined `struct`, the size varies from an instance to another. For some function like `quicksort` which parameter requires the fixed size of element, this is unbearable. With the help of pointer, we're able to use the pointer to convert the varies length into fixed one.


