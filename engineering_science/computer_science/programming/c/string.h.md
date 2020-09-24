# string.h

Functions in `<string.h>`. Following the convention in K&R, the variables `s, t` are of type `char *`. `cs, ct` are of type `const char*`, `n` is of type `size_t`, and `c` is an `int` converted to `char `.

##### # String Copy and Concatenation Function

```c
char* strcpy(s, ct);
char* strncpy(s, ct, n);

char* strcat(s, ct);
char* strncat(s, ct, n);
```

The `strcpy` function copy string `ct` to `s`, including the tailing `0`. Furthermore, `strncpy` function copy exactly `n` characters, padding with `\0` if `ct` has fewer than `n` characters.

The `strcat` function concatenate string `ct` to the end of string `s`.



##### # String Comparison

```c
int strcmp(cs, ct);
int strncmp(cs, ct, n);
```

`strcmp` function compares the string in lexicographical order, returns `<0` if `cs<ct`. `strncmp` compares at most `n` characters.



##### # String Searching

```c
char* strchr(cs, c);
char* strrchr(cs, c);
char* strspn(cs, ct);
char* strcspn(cs, ct);
char* strpbrk(cs, ct);
char*
```





 