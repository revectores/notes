# C++ Template

Template is introduced in C++11.



##### # Function Template

The demo shows how the function template works

```c++
template <typename T>
int compare(const T &v1, const T &v2)
{
    if(v1 < v2) return -1;
    if(v2 < v1) return 1;
    return 0;
}
```

As a template, the function `max` are now able to accept any two parameters with the same comparable type.



##### # Class Template

The demo shows how the class template works.

```c++
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

template <class T>
class Stack {
private:
    std::vector<T> elems;
public:
    void push(T const&);
    void pop();
    T top() const;
    bool empty() const {
        return elems.empty();
    };
};

template <class T>
void Stack<T>::push (T const& elem){
    elems.push_back(elem);
}

template <class T>
void Stack<T>::pop(){
    if (elems.empty()){
        throw std::out_of_range("Stack<>::pop empty stack");
    }
    elems.pop_back();
}

template <class T>
T Stack<T>::top() const {
    if (elems.empty()) {
        throw std::out_of_range("Stack<>::top(): empty stack");
    }
    return elems.back();
}

int main(){
    try {
        Stack<int> intStack;
        Stack<std::string> stringStack;

        intStack.push(7);
        std::cout << intStack.top() << std::endl;

        stringStack.push("hello");
        std::cout << stringStack.top() << std::endl;
        stringStack.pop();
        stringStack.pop();
    } catch (std::exception const& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
        return -1;
    }
}
```

