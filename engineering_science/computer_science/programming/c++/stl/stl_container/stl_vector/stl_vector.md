# Vector

Vector is basically a functional dynamic array, which makes us need not to worry about the complie time memory allocation, and implementation of the basic manipulation, besides, it's the conceptually simplist structure of C++ `container`, and there're lots of common methods among them, as a result, getting familiar about one basic of them can help us get the idea of the API design method, and need not to care much of the API name in the future but focus on the design of structure. (Actually `array` is a simplier one, so there's lots of comparison between array and vector in this document)

Just as array, vector stores its elements in the continuous memory, as the result we're able to simply use the pointer points to the first element and offsets to access its elements, while insertion and deletion operation of vector costs $O(n)$ averagely.







### 1. Construction

##### # Initialization

We create a vector with specific type of data like this:

```c++
vector<int> vec1;
```

Here we get a 0-size vector `vec1` who stores `int` elements. we can get the size of a vector by `size` method, and `empty` method to check if it's empty:

```c++
vec1.size();   // 0
vec1.empty();  // true
```

We can also add a parameter to allocate some spaces and declare the initial values for the vector, if the initial element is omitted, the empty value will be applied:

```c++
vector<int> vec2(10, 5);
vec2.empty();	// false
vec2.size();	// 10
vec2[0];		// 5

vector<int> vec3(10);
// In this case the vector will have 10 size with initial traditional empty values depend on the type, e.g. `0` for `vector<int>`.
```

Using C++ initializer list syntax to declare vector with values:

```c++
vector<int> vec4 {1,2,3};
```

You can also initialize vector form another vector:

```c++
vector<int> vec5(vec4);
vector<int> vec6(vec5.begin(), vec5.end());
// The `begin` and `end` method will be introduced in Chapter 3.
```



##### # Construct Patterns

If an increasing integer sequence is required, we can use a for-loop to accomplish this, or introduce the `itoa ` method in the `numeric` library.

```c++
#include <numberic>

vector<int> vec1(5);
itoa(vec1.begin(), vec1.end(), 1);
// vec1 = {1, 2, 3, 4, 5}
```



##### # Size Control

As we mentioned before, vector is a dynamic or resizeable array, we can change the size of vector by simply with the `resize` function applied:

```c++
vec3.resize(7);
// or with the value want to fill:
vec3.resize(7,3);
```



##### # `capacity` VS `size`

The `size` and `capacity` of a vector is different concept. The allocate operation costs time, so the implementation of vector designed a mechanism to detect the potential space needs, and previously allocate more space before which is required. This process will not be shown in the number of size, and is transparent to user unless we use the `capacity` funtion to check the current actual allocated space.

```c++
vector<int> vec1;
for(int i=0;i<10;i++){
	vec1.push_back(i);
	cout << "capacity = " << vec1.capacity() << ", size = " <<  vec1.size() << endl;
    }

/*
capacity = 1, size = 1
capacity = 2, size = 2
capacity = 4, size = 3
capacity = 4, size = 4
capacity = 8, size = 5
capacity = 8, size = 6
capacity = 8, size = 7
capacity = 8, size = 8
capacity = 16, size = 9
capacity = 16, size = 10
*/
```

The preallocation mechanism has not been standardized therefore the behaviour can be different in the different mechine and interpreter, while the `size` has.



##### # `clear`

The `clear` method delete all the elements and reset the size into 0, which totally rebulids a vector.

```c++
vector<int> vec1 = {1,2,3};
vec1.clear(); // vec1 = {}
```







### 2. Element Manipulation

##### # Subscription

Vector provides the same pathway as array to get the element (operator `[]`), the `at ` method has the same effect, and support the range checking, so this it suggested.

```c++
vector<int> vec1(5,1);
cout << vec1[2];	// 1
cout << vec1.at(2); // 1

cout << vec1[5];	// -1
cout << vec1.at(5);	// std::out_of_range: vector
```

Specially we can use `front` and `back` method to get the first and last element. (Notice that there's simliar method `begin` and `end` which are not the element-access method but to get the iterator, which will be introduced in Chapter 3)



##### # `push_back` & `pop_back`

Although we can change the size of vectores explictly, usually we don't consider about this in the programming while left it to the the vector itself, so we are be able to save more energy for the data itself. The most useful method is adding an element to the end, using `push_back` method:

```c++
vector<int> vec1(5, 0);
vec1.push_back(1);
// vec1 = {0, 0, 0, 0, 0, 1}
```

The important fact we have to notice is that the `push_back` method strictly extends the size of vector and put the new element in the new space.

In the contrary, there is a `pop_back` method, which is a `void` function that do not return anything, that's an important feature to notice because in some language the "pop" method was usually designed as returning the deleted element.

```c++
vec1.pop_back();
// vec1 = {0, 0, 0, 0, 0}
```

There are no `push_front` and `pop_front` function for vector.



##### # `insert`

`(pop/push)_back` function is the special insert function which is limited in the specific position. General insertion based on the `iterator` of position (which is introduced in Chapter 3).

```c++
vector<int> vec1 = {1,2,3};
vec1.insert(vec1.begin(), 100);		// vec1 = {100, 1, 2, 3}
// or insert more the same item at one time:
vector<int> vec2 = {1,2,3};
vec2.insert(vec2.begin(), 2, 100);  // vec2 = {100, 100, 1, 2, 3}
// Here's a strange property that the position of inserted value is changed one the insert time is added. It seems that the interpreter need to based on the number of parameter to determine the meaning of every position...
```

Besides, we can insert another vector or array into our injected vector:

```c++
vector<int> vec1 = {1,2,3};
vector<int> vec2 = {4,5,6};
int arr1 = {7,8,9};
vec1.insert(vec1.begin(), vec2.begin(), vec2.end()); // vec1 = {4, 5, 6, 1, 2, 3}
vec1.insert(vec1.begin(), arr1, arr1 + 3); // vec1 = {7, 8, 9, 4, 5, 6, 1, 2, 3}
// These both require the pointer to vector or array.
```

What we must remember is that the core idea of vector (and the array) is the continuous storage in the memory. Although the insert operation is permitted, this requires the movement of the latter elements, which pretty inefficient, whenever this opeartion occurs frequently, you should consider another a data structure.



##### # `erase`

`erase` function also based on the iterator of position, we can pass one argument to erase only one element or two arguments to erase a sequence of them:

```c++
vector<int> vec1 = {1,2,3,4,5};
vec1.erase(vec1.begin());  // vec1 = {2,3,4,5}
vec1.erase(vec1.begin(), vec1.end()-2);  // vec1 = {4,5}
// Notice that the last position is not included in the erased sequences, as a result vec1.erase(vec1.begin(), vec1.end()) will work as clear().
```



##### # `swap`

This method take another vector as the parameter to swap two vector.

```c++
vector<int> vec1 = {1,2,3}, vec2 = {4,5,6};
vec1.swap(vec2);	// vec1 = {4,5,6}, vec2 = {1,2,3}
```







### 3. Iteration

Based on the same access method as array, the iteration of elements can also be done by simply for-loop:

```c++
vector<int> vec1 = {1,2,3};
for(int i=0; i<vec1.size(); i++) cout << vec1[i];	// 123
```

There is a python-style sugar for this:

```c++
for(auto e : vec1) cout << e;	// 123
```

where the `auto` recognize the type of element in the vector, which is `int` in this case.

Besides, there is an iterator-based way like this

```c++
for(auto iter = vec1.begin(); iter != vec1.end(); iter++) cout << *iter; // 123
```

Here `iter` is a special type defined in the vector library `vecter<int>::iterator`. The behaviour of this type is similar with `pointer` (Support the `*` operation for pointed-value-achieve and the simple addition/subtraction to get the offset). Method `begin` and `end` both return this type of value, which "point to" the first element and **the position after the last element's position** respectively. This can be concluded by the following equivalence-checking expression:

```c++
vector<int> vec1 = {1,2,3};
cout << (*vec1.begin() == vec1.front());		// 1
cout << (*(vec1.end() - 1) == vec1.back());		// 1
```

The auto iteration style is perferred in modern C++, based on the higher abstraction, we're able to avoid those errors caused by operating pointer manually.




