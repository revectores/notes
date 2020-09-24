# Class

### 1. Basic Usage

##### # Introduction by Instance

C++ class provides mechanism to divided `private` and `public` method, both variables and method functions can be declared as `private` or `public`.

Here is an example of a simple class implementation, which shows the following usages:

1. `private` and `public` mechanism.
2. `construtor` and `destructor`
3. Member function, defined inside and outside the class.
4. Operator Overloading for `<<`, `+`, `-`, `*`.
5. How to create instances of class.

This concludes most of the basic functions of C++ class.

```c++
#include <iostream>
#include <cmath>


class Complex{
private:
  	// widely-used way to express private variable
    double _re;
    double _im;

public:
  	// Constructor Function, without return type(no void keyword even)
  	/* the variable `this` is a pointer which points to the current instance. It can be omitted	inside the class definition EXCEPT in the constructor. */
    Complex(double re, double im){this->_re=re; this->_im=im;}
		// Destructor
  	~Complex();
  
  	// Member function, defined in the class body
    double re() {return _re;}
    double im() {return _im;}
    double abs();

  	// friend function, authorized to read the the private and protected variable
  	/* Notice that the abs here will not be collision with the member function, cause they are not at the same namespace. */
  	friend double abs(const Complex &z){
    	return sqrt(pow(z._re,2) + pow(z._im,2));
  	}
  
  	// iostream overloading
    friend std::ostream& operator<< (std::ostream& os, const Complex &z){
        os << z._re << '+' << z._im << 'i';
        return os;
    }

  	// operator overloading
    Complex operator+ (Complex const &z){
        return Complex(_re + z._re, _im + z._im);  // Construction way
    }
  
  	// operator can be overloaded for different types of parameters.
  	Complex operator+ (double const &d){
    	return {_re + d, _im}; // braces way, recommended
  	}
  
  	Complex operator- (Complex const &z){ return{_re-z._re, _im-z._im}; }
  	Complex operator* (Complex const &z){
    	treturn {_re*z._re-_im*z._im, _re*z._im+_im*z._re};
    }
  	// ...
};
// Member function, defined outside of the class body
double Complex::abs() {
	return sqrt(_re*_re + _im*_im);
}

/* function overloading, noticed that outside the class the private variables are not allowed to read. */

int main(){
  	Complex z1 = Complex(1,2); 		// function style. use constructor as a function.
  	Complex z2{3,4};					 		// object style.
  	std::cout << z1 + z2 << endl;	 			// z1.opeartor+(z2);
    std::cout << abs(z2) << " " << z2.abs() << endl;
}
```



##### # Constructor & Destructor

In the example before we use the pure assignment to accomplish the initialization of attribuates.

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

Noticed that even if no more codes needed for the construction, the empty braces are still required.

It's allowed to define different constructors based on the numbers and types of parameters. E.G. we want to set the default imaginary/real part of complex to zero if it's not provided.

```c++
Complex(int re, int im): _re(re), _im(im) {};
Complex(int re): _re(re), _im(0) {};
Complex(): _re(0), _im(0) {};
```







### 2. Class Inheritance

##### # Example of Inheritance

Here is the example about how C++ create inheritance:

```c++
class Employee {
public:  
    std::string name;
    int age;
}

class Manager : public Employee {
public:
	short level;
}

int main(){
    Employee e;
    Manager m;
    m.name = "Robert"; m.level = 8;
    cout << m.name << " " << m.level;
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
3. wAfter all these works done, the class itself is constructed.

The destruction order is opposite to the construction order.



##### # Polymorphism Mechanism: Virtual Function

