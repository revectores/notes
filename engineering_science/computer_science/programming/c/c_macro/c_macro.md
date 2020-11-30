# C Macro

##### # Macro Basic



##### # Define Constant By Macro









##### # Variadic Macro

Use `...` to represent variable number of argument of marco and use `__VA_ARGS__` identifer to expand it:

```c
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
```

C++ support the renaming of identifer, note that after renaming `__VA_ARGS__` cannot be used:

```c
#define eprintf(args...) fprintf(stderr, args)
```

We are able to use both variable length arugment with normal named arugment in the argument list:

```c
#define eprintf(format, ...) fprintf(stderr, foramt, __VA_ARGS__)
```



In standard C if you left the variadic arugment empty it would be an error since the due to the tailling comma after marco expansion:

```c
// eprintf()
```







Variadic marcos became a standard part of C with C99. GNU CPP previously supported them with a named variable argument, which is still supported fro backward compatibility.





