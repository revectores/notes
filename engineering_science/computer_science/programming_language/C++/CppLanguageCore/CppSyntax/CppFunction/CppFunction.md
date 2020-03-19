# Cpp Function

### 5. Lambda Expression

##### # Introduction

Here's an typical example of lambda expression:

```c++
int addition = 1;
[addition] (int x, int y) -> int {return x + y + addition;}
```

We noticed that there're there part of this inline function: variable capture `[addition]`, type declaration part `(int x, int y)->int` and the function body part.

The first part declares a **clourse** of the lambda function: only the global variables those in this set can be used in the lambda function. If none of this is not needed, then we just leave an empty `[]`. This can also set the specific reference/value capture:

```c++
[]			// None of the global variable are captured.
[x, &y] // only x,y and x captured by value, y captured by reference.
[=]			// All of the global variable can be captured, by value.
[&]			// All of, and by reference.
[&, x]	// All by reference but x by value.
```

The second part declares the type of input and output variables. It's called trailing return types which is introduced in C++11.

The third part is simply the function definition, which usually short and can be written in one line.

Lambda expressions are usually used to provide an **function parameter** to avoiding the unnecessary space waste for only one-time using:

```c++
vector<int> A = {2,4,6,8,10};
bool all_even = is_all(A.begin(), A.end(), [](int i){return !(i%2)});
cout << all_even;		// true
```



If the persistence is required, we can use a function pointer to store the address of that lambda expression.

```c++
int (*add)(int a, int b) = [](int a, int b) {return a+b;}
// It seems it's not possible to create recursion by this:
int (*sum)(int n) = [&](int n){return n? sum(n/10)+n%10 : 0;}; // error.
```

Instead, we need an `std::function` object to receive the lambda expression to create recursion successfully:

```c++
function<int (int)> sum = [&](int n){return n? sum(n/10)+n%10 : 0;};
```


