# Container

Container is a collection of objects of the same type.



### 1. List

The `list` implememted by standard library is a **double-linked list**. The construction of list is similar with `vector`, while we're not able to access element by simply giving the offsets due to the property of linked list. More details of this data structure can be found in [linear list]().

The funtions of getting the specific pointer `begin` and `end` are usable, and we're able to track the linked chain to get the element:

```c++
list<int> list1 = {1, 2, 3};
iter = list1.begin(); 	// iter points to the first element
cout << *(iter++);		// 2
cout << *(next(iter,2))	// 3
```

We exchange the efficiency of random access with the efficiency of restrcution, which includes the operation like `insert` and `erase`. Besides, the `push_front` and `pop_front` method is supported since first element anymore is allowed to change, instead of a fixed address like the case in  `vector`.



### 2. Map

Similar to dictionary in Python, map is a structure which stores its element as `(key->value)`, and we can easily access or set the `value` by passing the name of key in the `[]operator`.

Since there's key and value in map, we need two data types to initialize it, and use nested brackets to give the initial values if which are required:

```c++
map<int, int> map1 = {{1,2}, {2,3}};
// term access:
std::cout << map1[1];	// 2
// term set:
map1[3] = 4;			// map1 = {{1,2}, {2,3}, {3,4}}
// It's allowed to directly create an new key by setting it's value.
```

The iteration manipulation works like this:

```c++
for(auto e : map1)
    cout << e.first << ":" << e.second;

for(auto it = map1.begin(); it != map.end(); it++)
    cout << it->first << ":" << it->second;
```

Where the key and value are considered as the property of the key-value pair `struct`, and the `->operator` of iterator (pointer) provides a quick access method.

Notices that map is an unordered data structure, you need to use `vector` to manipulate a map if you want the order information perserved.

```c++
struct ordered_map{
	int key,
	int value
};
vector<ordered_map> omap1;
```



### 3. Set



### 4. Stack

As we know stack is the container with FILO property. Notice that `stack` container doesn't support a method for initialize the values, if which is wanted we have to manually do the push loop:

```c++
#include <stack>
std::stack<int> nums;
for(auto& num: {1,2,3}){
    nums.push(num);
}
```





### 5. Queue


