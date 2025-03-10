# String

### 1. Basic

##### # Definition & Basic Concepts

A **string** is defined as the finite sequence of the **characters(elements)** in alphabet $\Sigma$. The number of characters is the **length** of string, specially, if there's no character in a string, or the length of string is 0, it's an **empty string**. Any subsequence of the string sequence is a **substring**.

Based on the definition, a string is no more than a linear list of characters, which implies that any storage stragey and algorithm designed for linear list can be used on string.



##### # Implementation

String is supported as an indivual data type by most programming language. While for C language core, there're no bulit-in string type support, instead, string is represented by the `char` array, which contains a `\0` (ASCII `0`) as the terminal singal(character). Further details are illustrated in the C Programming Language's Notes [String](String). We'll use the some codes like following to implement a string:

```c
#define MAXN 100;

char str[MAXN];
```







### 2. Operations

Useful function of string usually include two types

1. Operation/Property of only one string, which includes
   - Get the length of string `strlen(str)`.
   - Range Based Substring Getting `strsub(str, start, end)`.
   - Range Based Deletion `delete(str, del_start_at, del_length)`.
2. Operation on two strings, which includes
   - Compare two strings based on the lexicographical order `strcmp(str1, str2)`.
   - String insertion `insert(str, pos, inserted_string)`. This can be degenerated as char insertion and string/char append.
   - Pattern Recognition `strstr(str, pattern)`. Normally the base algorithm is only required to find **the first** occurance since the `findall ` case is simply the repeat. Combined with the position-range-specific deletion introduced before, we can delete the given patterns in strings.

We'll introduce and implement all of these operations manually except pattern reconigition. The algorithms which implement that task would be illustrate in the indivual section.

```c
/* Common Codes */
#define FAIL 0;
#define SUCCESS 1;

char s[MAXN], s1[MAXN], s2[MAXN];
```

Get length of string:

```c
int strlen(char str[]){
    int i;
    for(int = 0; str[i]!='\0'; i++);
    return i;
}
```

Range based deletion:

```c
int delete(char s[], del_start_at, del_length){
    int raw_length = strlen(s);
    if(del_start_at >= raw_length) return SUCCESS;
    
    int seg_start_at = del_start_at + length;
    for(int i=seg_start_at; i<raw_length; i++){
        str[del_start_at + i] = str[seg_start_at + i];
    }
}
```





