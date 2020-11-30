# Class

### 1. Basic Usage

##### # Introduction by Instance

[`c++_class_demo.cpp`](c++_class_demo/c++_class_demo.cpp) is a demo for c++ class, which shows the following usages:

1. Access control: `private` and `public` keyword.
2. Construtor and destructor.
3. Member function, defined inside and outside the class.
4. Operator Overloading for `<<`, `+`, `-`, `*`.
5. How to create instances of class.

This concludes most of the basic concepts of C++ class.



##### # Constructor & Destructor

In the example above we use the assignments to accomplish the initialization of attribuates.

```c++
Complex(int re, int im) {
	this->_re = re;
	this->_im = im;
}
```

Since this is a common pattern, there's a shortcut for this:

```c++
Complex(int re, int im): _re(re), _im(im) {};
```

Notice that even if no more codes needed for the construction, the empty braces are still required.

It's permitted to define different constructors based on the numbers and types of parameters. For example, we want to set the default imaginary/real part of complex to zero if it's not provided.

```c++
Complex(int re, int im): _re(re), _im(im) {};
Complex(int re): _re(re), _im(0) {};
Complex(): _re(0), _im(0) {};
```







### 2. Class Inheritance

##### # Example of Inheritance

[`c++_class_inheritance_example.cpp`](c++_class_inheritance_example/c++_class_inheritance_example.cpp) is the example about how C++ create inheritance:

```c++
class Employee {
public:
	std::string name;
	int age;
};

class Manager : public Employee {
public:
	short level;
};

int main() {
    Employee e;
    Manager m;
    m.name = "Robert"; m.level = 8;
    std::cout << m.name << " " << m.level;
}
```

Here class `Manager` is derived from `Employee` and is added an attribuate `level`. We use this structure as example to show the attribuates of inheritance.



##### # Constructor

The derived class inherits all the member variables and function from base class, **EXCEPT** the constructor. If the constructor is included in base class, derived class needs to use it as an **initializer** to bulid itself's constructor.

```c++
#include <iostream>
#include <string>


class Employee {
public:
    std::string name;
    int age;
    Employee(std::string name, int age): name(name), age(age) {};
}

class Manager : public Employee {
public:
    short level;
    Manager(std::string name, int age, short level): Employee(name, age), level(level) {};
}

int main(){
    Manager m("Robert", 30, 8);
    cout << m.name << " " << m.age << " " << m.level;
    return 0;
}
```



##### # Construction Order

With two types of relationships of class given: **inheritance** and **composition**, a class definition may written like:

```c++
class_np::classname : baseclass, member1, member2
```

There's problem occurs about in what kind of sqeuence the constructor and destructor is executed. The answer is inituitive:

1. If the class has base class, then the base class is first constructed.
2. If the class has member classes, then the member classes constructed successively based on the declaration order.
3. After all these works done, the class itself is constructed.

The destruction order is opposite to the construction order.



##### # Polymorphism Mechanism: Virtual Function

