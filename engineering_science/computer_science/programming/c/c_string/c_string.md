# C String

### 1. Declaration & Initialization

C-style string is not an specific type but the array of characters, which means you can initialize it like initializing any other type of array:

```c
char s[] = {'H', 'e', 'l', 'l', 'o', '\0'};
```

Noticed that a typical c string always stopped with `\0` (which equals to the ascii value 0, so you can directly write a char 0) in the end, which helps the interpreter recognize where the string ends.

As a short-cut to initialization, we can use the string expression to accomplish the same goal, and the interpreter will add the suffix zero automatically:

```c
char s[] = "Hello";
```

Noticed that because of the suffix zero, the length of this char array is not 5 but 6 instead.

When we create a string in the manual way, the string must be end with a zero rightly otherwise the function and implementment for string will mistakenly considered the string is not ended yet (although it's already pass the border of charArray):

```c
char s[] = {'H', 'e', 'l', 'l', 'o'};
printf("%s", s);
/* The behaviour of this in undefined, the interpreter might print every bits after last 'o' until '\0' occasionly occurs in the memory. */
```

Becaused the string is an array, and an array it not allowed to operate assignment (besides the first initialization, if you considered it as a special assignment).







### 2. Useful Function

Noticed that C-style string is no more than an array, which means all the function applied to the array can be also applied in the string, one thing needs to be care about is still the suffix zero.

```c
char s[] = "Hello";
cout << sizeof(s)/sizeof(s[0]);  // 6
// This count in the final 0. But string function strlen will ignore it:
cout << strlen(s);		// 5
```

Besides `strlen`, there're some other function for string which shown in the following.

`strcpy` to copy the string into another and `strcat` implements the concatenation, both avoiding the bad-looking `for` loop.

```c
char s1[] = "Hello"; char s2[20];
strcpy(s2, s1);  // Copying s1 into s2, Now s2 = "Hello".
// Notices the assignment-like sequence.
strcat(s2, s1);  // Now s2 = "HelloHello"
```

`strcmp` to compare two string by the dictionary sequent. No, it's not possible to pass the third parameter to make the comparsion standard user-defined.

```c
char s1[] = "Hello"; char s2[] = "Hi";
cout << strcmp(s1, s2);		// -4
/* This is because 'e'-'i' = -4. Which means this function no only gives the comparsion result but quantify it. */

char s3[] = "Helloa";
cout << strcmp(s1, s3);		// -97
/* If two string is the same until one of the string reaches its end, then the function will consider the last 0 as the final one of s1. This mechanism can be checked by deliberately puting a none-zero value to the end of string to see what happened: */
char s4[] = {'H', 'e', 'l', 'l', 'o', '\1'};
cout << strcmp(s4, s3);		// -96
```

`strch` and `strstr` provide the searching function, both of them returns a pointer to the first occurance of character/string in the string.

