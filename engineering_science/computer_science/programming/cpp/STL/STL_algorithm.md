# Algorithm

Algorithm library provides a series of packed useful algorithm, which can be basically classified as two types: non-modifying operation and modifying operation. Here we introduce some of them which can be pretty useful in kinds of test and development.

For the most common function in the library, it loops a container to get some information about it, which usually requires two parameter to express the container: the pointer(iterator) to the first and the one after the last element. This pattern will occur again and again, which seems to be some remain of C style. After the sequence infomation is given, it also often requires some function parameter to be the user-defined standard to check, find, comparation, or anything else. This kind of requirements often occur along with the **Lambda Expression** and **Function Pointer**. Formally, the common parameters construct like this:

```c++
return_type func_name(InputIterator first, InputIterator last, UnaryPredicate pred)
```

In this document we called the first two elements (if they are the range-specifier of `InputIterator`) Trivial Parameter (TP) and the others are named as Non-trivial Parameter (NP).







### 1. Non-Modifying Sequence Operation

##### # `for_each`

This is the simplist one, it just like the modern auto for cycle:

```c++
std::vector<int> A = {1, 2, 3, 4, 5};
for_each(A.begin(), A.end(), [](int i){cout << i;});
```



##### # Extension Logical Judgement

This includes three functions called `all_of`, `any_of` and `none_of` which simply the encapsulation of one `for` loop.

```c++
vector<int> A = {2, 4, 6, 8, 10};
bool all_even = all_of(A.begin(), A.end(), [](int i){return !(i%2);});
// all_of: return true if all the results is true.
```



##### # Element Searching

This includes four functions in `find` family: `find`, `find_first_of`, `find_if` and `find_if_not`. All of them are trying to find an element which meets some specific condition by going through the `InputIterator`, but the way of expressing condition is strengthened by the sequence:

1. `find` provides function to check simple equivlance. The NP is an element.
2. `find_first_of` is able to compare to a range instead of single element. The NPs are another Iterator range.
3. `find_if` and `find_if_not` provides the most powerful function. The NP is a function.

All of them return a pointer to the finded value, otherwise they return a pointer which pointer to the `last` of the `InputIterator`.

```c++
vector<int> A = {1, 2, 3, 4, 5};
vector<int> B = {2, 4, 6, 8, 10};
bool is_there_six = find(A.begin(), A.end(), 6) != A.end();	// false
int first_B = *find_first_of(A.begin(), A.end(), B.begin(), B.end()); // 2
int first_even = *find_if(A.begin, A.end(), [](int i){return !(i%2);}); // 2
```



##### # Search Subsequence

`search` and `find_end`, both return the first address of the first/last finded subsquence of the main sequence.



##### # Count

`count` and `count_if` is provided, which are similarly to `find` and `find_if`.



##### # Whole Iterator Comparation

`equal` and `is_permutation`, both TPs and NPs are iterator range.







### 2. Modifying Sequence Operation

##### # Whole Iterator Permutation Restruction

There're two function to reconstruct the iterator's array: `rotate` and `reverse`. `rotate` is what the "rotation symmetry" means. 

```c++
vector<int> A(9); iota(A.begin(), A.end(), 1);
rotate(A.begin(), A.begin()+3, A.end());
// Notice that its TP is not as the usual sequence.
for(auto e:A) cout << e;		// 456789123
```

```c++
vector<int> A(5); iota(A.begin(), A.end(), 1);
reverse(A.begin(), A.end());
for(auto e:A) cout << e;		// 54321
```

These two functions are local operation. Plus, for some modifying functions, there're corresponding none local operation which with the tail "_copy", fortunely these two function both have the copy correspondent:

```c++
vector<int> A(9); iota(A.begin(), A.end(), 1);
vector<int> B(A.size())
rotate_copy(A.begin(), A.begin()+3, A.end(), B);  // B={4,5,6,7,8,9,1,2,3}
```

Notice that the copy function will not work as "return an iterator" (for container, this is convient, but the concept of iterator is much wider than that, and, actually, the iterator can't be "returned" otherwise it returned two pointer as you passed to them) to let you assign. The added parameter, which indicating the start address of receiver is required.



##### # Remove and Replace

This two is extremely similar with each other. They are both a family, which conclude

`remove`, `remove_if`, `remove_copy`, `remove_copy_if`

`replace`, `replace_if`, `replace_copy`, `replace_copy_if`

respectively.


