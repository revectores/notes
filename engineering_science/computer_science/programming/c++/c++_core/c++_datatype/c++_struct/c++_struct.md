# Struct

### 1. Construction

Struct is a sequential group of different types of data, we provide a set of name and their corresponding types to construct a struct:

```c++
struct time{
    int hour;
    int min;
    int sec;
}
```

After this we're able to declare some variable as an instance of `time` to use this structure:

```c++
struct time t0;
// Sequent initalization:
struct time t1 = {11, 40, 30};
// Keyword pathway:
struct time t2 = {.min=40, .sec=30};
// or keyword combined with sequent:
struct time t3 = {.min=40, 30};
```

There is a useful short cut for creating new instance struct which is directly writing the struct name and the initalizer after struct definition, and you can create many of them:

```c++
struct time{
    int hour, min, sec;
}
t0,
t1 = {11, 40, 30},
t2 = {.min = 40, .sec = 30},
t3 = {.min = 40, 30};
```

Once the struct is constructed, we're able to consider it as any build-in data type, which means it's possibile to make it the parameter or return type of a function, this can be pretty convinent to passby the limitation of return value.







### 2. Interact with Pointer

The funny part occurs on the interaction between pointer and struct. A pointer which points an struct has a quick path to achieve the attribute:

```C++
struct time* pt = &t0;
cout << (*pt).hour << " " << (pt->hour);	// 11 11
```

As shown above, if some pointer `pt` points to the struct, then we're able to use the left arrow to directly point the struct's element without fisrt dereference to the struct itself.

Notice that in the expression above if we remove the brackets besides `*pt` it will causes error:

```c++
cout << *pt.hour  // error
```

Based to the priority (attribute-achieve dot `.` has the higher priority), this will be considered as `*(pt.hour)` instead of `(*pt).hour`, which makes the interpreter misunderstand to consider `pt.hour ` as a pointer. We can construct a situation to apply this:

```c++
struct ptime{
    int *phour, *pmin, *psec;
} pt0 = {&(t0.hour), &(t0.min), &(t0.sec)}
cout << *(pt0.hour);	// 11
// Here the brackets can be removed without causing misunderstanding.
```







### 3. Abstraction Mechanism

##### # C++ Support

Comparing to class, struct is a simpler way to construct a group of data. In C++, actually almost all things that class can do is also supported, it's basicly "A class with all the parameters are public by default":

```c++
struct person{
private:
    std::string name;
    int age;
public:
    person(string _name, int _age){
        this->name = _name; this->age = _age;
    }
    int age(){
        return this->age;
    }
    int age(int _age){
        this->age = age;
    }
}
```



##### # C Style Struct

But in the primitive C this is limited, anyway there's no OOP concepts on the C, there is no so-called private and public declaration, besides we are not allowed to define a method of struct and the pointer `this` is not supported. The C just considered it as a simple group. If we want to construct a function as the method of struct, a function pointer is a good way to express:

```c
struct person{
    int age;
    void (*print)(const struct person*);
    char name[20];
};

void print(const struct person* p){
    printf("name:%s, age:%d", p->name, p->age);
}

int main(){
    struct person someone = {18, print, "Revector"};
    someone.print(&someone);
}
/* By constructing function pointer we can even simulate the dot syntax, while it's not elegant to pass so many meanless construction parameter. Anyway trying to implement a different paradigm in the language itself is not a good idea.*/
```


