# C++ `<functional>`

##### # `std::function`

Class template `std::function` is a general-purpose polymorphic function wrapper. Instances of `std::function` can be store, copy, and invoke any [CopyConstructible]() [Callable]() target - functions, [lambda expressions](), [bind expressions](), or other function objects, as well as pointers to member functions and pointers to data members.

The stored callable object is called the **target** of `std::function`. If a `std::function` contains no target, it is called **empty**. Invoking the target of an empty `std::function` results in `std::bad_function_call` exception being thrown.

`std::function` satisfies the requirements of [CopyConstructible]() and [CopyAssignable]().

[c++_std_function_demo.cpp](__src__/c++_std_function_demo.cpp) shows the common usages of `std::function`, includes

- Free function
- Reference to free function
- A call to a function object
- Lambda
- A call to `functional` provided function object

```c++
int half(int x){
    return x / 2;
};

struct third_t {
    int operator()(int x) {
        return x / 3;
    }
};

struct MyValue {
    int value;
    int fifth(){
        return value / 5;
    }
};

int main() {
    std::function<int(int)> fn1 = half;
    std::function<int(int)> fn2 = &half;
    std::function<int(int)> fn3 = third_t();
    std::function<int(int)> fn4 = [](int x){return x / 4;};
    std::function<int(int)> fn5 = std::negate<int>();

    std::cout << "fn1(60): " << fn1(60) << '\n';
    std::cout << "fn2(60): " << fn2(60) << '\n';
    std::cout << "fn3(60): " << fn3(60) << '\n';
    std::cout << "fn4(60): " << fn4(60) << '\n';
    std::cout << "fn5(60): " << fn5(60) << '\n';

    std::function<int(MyValue&)> value = &MyValue::value;
    std::function<int(MyValue&)> fifth = &MyValue::fifth;

    MyValue sixty {60};
    std::cout << "value(sixty): " << value(sixty) << '\n';
    std::cout << "fifth(sixty): " << fifth(sixty) << '\n';

    return 0;
}
```

