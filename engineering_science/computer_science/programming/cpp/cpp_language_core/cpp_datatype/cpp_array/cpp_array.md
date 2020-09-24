# Array

### 1. Basic concepts

##### # Declaration & Initialization

Array is a series of **same** type of data which stores in the continuous space in the memory, as a result, the interpreter is able to achieve any location in the array. This feature is named as **Random Reading**. We can declare an array by specific length given:

```c++
int A[5];
```

Using the subscript operator `[]`  to get/assign the specific location of element, notices that the array subscript starts at 0, which included by C:

```c++
int A[5] = {1, 2, 3, 4, 5};
cout << A[0];		// 1
cout << A[4];		// 5
for(int i=0; i<5; i++) cout << A[i];	// 12345
```

It's not allowed to assigned the array seperating from declearation, i.e. this kind of expression cause an error:

```c++
int A[5];
A = {1, 2, 3, 4, 5};		// error: array type 'int [5]' is not assignable
```

If the elements provided less than the length of array, other elements will be initialize as the 'empty' value of the type (0 for intArray, false for boolArray and so on):

```c++
int A[5] = {1, 2};
cout << A[3];		// 0 
```

If you want to initialze all the elements to specific non-empty values, the for-loop is necessary.

As the same of variable, never use the elements of array without initializing it. Some fool-proof designed interpreter will automatically initialize them to the empty value but it's not the standard. It's possible to access the trash data which remains in the memory. Besides, the `[]` operator doesn't provide strictly bound-check, the programmer should be careful to aviod crossing the maximum subscript of the array.

##### # Size and Length

There's no bulit-in function for C and even C++ to get the length of an array, we accomplish that by getting the size of array, and with the same data type principle applied:

```c++
int A[5];
cout << sizeof(A);  // 20 = sizeof(int)*5
cout << sizeof(A)/sizeof(A[0]);	// 5
```

Here `sizeof(A)` uses the name of array to represent the array, and get the size of the whole array.



### 2. Multi-Dimensional Array

##### # Assignment, Auto-pair machanism

Two dimensional array is an array of array. We can assigned it as it in multiple way:

```c++
int A[2][2] = {{1,2},{3,4}};	// Most official way.
int A[2][2] = {1,2, 3,4};		// The inner braces can omitted.
int A[][2] = {1,2, 3,4};		// Auto recognize the size of first dimensional.
int A[2][2] = {1,2};			// Unassigned elements will be set to 0.
```

In the memory, it still stores in the continous space:

`A[0][0], A[0][1], A[0][2], A[1][0], A[1][1], A[1][2], ...`



### 3. What Array Is: A Pointer's Perspective

As mentioned above, the essence of array is no more than **continous addressing**, which means that the **pointer** of each element is continous.

| Address(Pointer) | `&A[0] = A` | `&A[0] + 1 = A + 1` | ...  | `&A[0] + k = A + k` |
| ---------------- | ----------- | ------------------- | ---- | ------------------- |
| Value            | `A[0]`      | `A[1]`              | ...  | `A[k]`              |

Acutally, what the name of array `A` represents is just the address of the first element in array `&A[0]`, which gives the following statement: `&A[k] = &A[0] + k = A + k`, or `A[k] = *(A+k)`.


