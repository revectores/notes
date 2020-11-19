#include <iostream>
#include <cmath>


class Complex{
private:
  	// conventional notation for private variable 
    __float128 _re;
    __float128 _im;

public:
    // Constructor, without return type (even no `void` return type declaration)
    // `this` is a pointer points to the current instance. It can be omitted inside the class definition EXCEPT in the constructor.
    Complex(__float128 re, __float128 im){this->_re=re; this->_im=im;}

    // Destructor
  	~Complex(){};
  
    // Member function, defined in the class body
    __float128 re() {return _re;}
    __float128 im() {return _im;}
    __float128 abs();

  	// friend function, authorized to read the the private and protected variable
  	/* Notice that the abs here will not be collision with the member function `abs`, cause they are not at the same namespace. */
  	friend __float128 abs(const Complex &z){
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
  	Complex operator+ (__float128 const &d){
    	return {_re + d, _im}; // braces way, recommended
  	}
  
  	Complex operator- (Complex const &z){ return{_re-z._re, _im-z._im}; }
  	Complex operator* (Complex const &z){
    	return {_re*z._re-_im*z._im, _re*z._im+_im*z._re};
    }
  	// ...
};

// Member function, defined outside of the class body
__float128 Complex::abs() {
	return sqrt(_re*_re + _im*_im);
}

/* function overloading, noticed that outside the class the private variables are not allowed to read. */

int main(){
  	Complex z1 = Complex(1,2); 					// function style. use constructor as a function.
  	Complex z2{3,4};					 		// object style.
  	std::cout << z1 + z2 << std::endl;	 		// z1.opeartor+(z2);
    std::cout << abs(z2) << " " << z2.abs() << std::endl;
}
