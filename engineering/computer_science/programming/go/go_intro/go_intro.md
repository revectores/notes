# Go

### 1. Basic Concept

##### # Main Structure

A simplist go program demo:

```go
package main

import "fmt"

func main(){
    fmt.Println("Hello, World!")
}
```

by which we declare the current file as the package `main`, the `main` function inside `main` package will be executed by default.



##### # Compile and Execute

```shell
go build hello.go
go run hello.go
```

which will compile (a file `hello*` will be generated in the directory) and run the program respectively. Notice that the filename is not constrained by the package name.



##### # Package

Use `import` to import other packages:

```go
package main

import "fmt"
import "math/rand"

func main(){
    fmt.Println("My favorite number is", rand.Intn(10));
}
```



##### # Variables Export

Whether a variables/functions etc. get exported depends on its first character: it get exported if it's capitalized. As notice, the functions and variables provided in the built-in packages are all beginning with capitalized first character.



### 2. Syntax Misc

##### # Distributive Law

The distributive law can be applied to most of the go keyword, no extra comma or semicolon required:

```go
import (
	"fmt"
    "math/rand"
)

var (
	i int
    s string
)
```



| Syntax        | Style                                                        |
| ------------- | ------------------------------------------------------------ |
| Comment       | Conventional inline and multiple lines comment syntax supported. |
| Semicolon     | Not necessary. Can be used to merge lines.                   |
| `++` and `--` | Supported                                                    |







### 3. Variables

##### # Variable Declaration

Use `var` to declare variables, the type should be given after the last variable:

```go
var c, python, java bool
```

The uninitialized variables are assigned as the zero values, referred the data type section for the zero values of each basic data type. We can provide initializer to variables, in this case we can let the compiler to do the type inference:

```go
var c, python, java = true, false, "no!"
```

The short assignment `:=` is supported only inside a function:

```go
func main(){
    var i, j int = 1, 2
    c, python ,java := true, false, "no!"
}
```



##### # Constant

Replace `var` with `const` to declare constant. Constant cannot be declared using `:=` syntax.

```go
const pi = 3.14
```

The numeric constants are high-precision values.

```go
const (
	bigInt = 1<<500
	smallInt = bigInt>>499
)

func main(){
	fmt.Println(smallInt)	// 2
}
```







### 4. Data Types

The basic types of Go are

```go
bool

string

int int8 int16 int32(rune) int64
uint uint8(byte) uint16 uint32 uint64 uintptr

float32 float64

complex64 complex128
```

To print the type of variable, use `fmt.Printf` function with `%T` formatter:

```go
var (
	MaxInt uint64 = 1<<64 - 1
)

func main(){
    fmt.Printf("Type: %T Value: %v\n", MaxInt, MaxInt)
}

// Type: uint64 Value: 18446744073709551615
```

The zero value, traditionally, is `0` for numeric types, `false` for boolean type, and empty string `""` for string.

The explicit type conversion `Type(value)` has to be given during the assignment between items of different types.







### 5. Function

##### # Syntax

The type comes after the variable name and function prototype in Go, like the type hint in Python with arrow removed.

```go
func add(x int, y int) int {
    return x + y; 
}
```

For consecutive parameters with same types, we can omit type but the last.

```go
func add(x, y int) int {
    return x + y;
}
```

Multiple return value supported, notice do the same to the function type:

```go
func swap(x, y string) (string, string){
    return y, x
}
```



##### # Named return values

Instead of providing returned values after `return` statement, we can directly provides the name of returned when specifying the return types. Then the `return` statement becomes a **naked return**.

```go
func split(sum int) (x, y int){
    x = sum * 4 / 9
    y = sum - x
    return
}
```

In this case, the variables are treated as those variables defined at the top level. This approach should only be used in short functions, to aviod the reability reduce in the long function.



##### # Function As Value

Function is also one type of value, that is, we can pass and return function, as what we done to common variables.

```go
func compute(fn func(float64, float64) float64) float64 {
    return fn(3, 4)
}

func main() {
    hypot := func(x, y float64) float64{
        return math.Sqrt(x*x + y*y)
    }
    fmt.Println(compute(hypot))
    fmt.Println(compute(math.Pow))
}
```



##### # Closure

The concept and property of closure is described in [javascript_function_closure](javascript_function_closure.md). This statement can apply to Go as well. An demonstrating example:

```go
func adder() func(int) int {
    sum := 0 
    return func(x int) int {
        sum += x
        return sum
    }
}

func main(){
    pos, neg := adder(), adder()
    for i := 0; i < 10; i++ {
        fmt.Println(
            pos(i)
            neg(-2*i)
        )
    }
}
```







### 6. Flow Control

##### # Syntax

Parentheses is redundant, but brace is necessary (I recognize Google from the syntax design), initializer can be provided to declare local variable with block scope, not only for `for`, but also `if` and `switch`:

```go
sum := 0 
for i := 0; i < 10; i++ {
    sum += i
}

if sum == 45 {
    fmt.Println("correct!")
}

if other_sum := 50; sum == 45 {
    fmt.Println("correct!")
}
```

`while` is not needed, since it is no more than the special case of `for` with condition only:

```go
sum := 1
for ; sum < 1000; {
    sum += sum
}
// equiv to
for sum < 1000 {
    sum += sum
}
```



##### # New `switch`

The semantics of `switch` is finally redesigned to human-understandable:

- Evalute up-down, only the first true label get executed, that is, no `break` needed.
- Variables and function are supported.
- Switch with omitted condition is equivalent to `swtich true`.

```go
today := time.Now().Weekday()
switch time.Saturday {
case today:
    fmt.Println("today")
case today + 1:
    fmt.Println("tomorrow")
case today + 2:
    fmt.Println("two days later")
default:
    fmt.Println("far away")
}
```

```go
t := time.Now()
switch {
case t.Hour() < 12:
    fmt.Println("Good Morning!")
case t.Hour() < 17:
    fmt.Println("Good Afternoon")
default:
    fmt.Println("Good Evening")
}
```







### 7. Type and Struct

We use the keyword `type` to create new type based on existing ones, not just making an alias as C `typedef`.

```go
type MyInt float

func main() {
    var i MyInt = 1;
    fmt.Printf("%T", i); // main.MyInt
}
```

Normally a useful type is a struct, like C struct, composed of many fields. When initializing, the zero value of corresponding type will be assigned to the unspecified value.

```go
type point struct {
    x int
    y int
}

func main(){
    v1 := Vertex{1, 2}
    v2 := Vertex{x: 1}
    v3 := Vertex{}
    v1.x = 4
    fmt.Printf(v1, v2, v3) // {4, 2}, {1, 0}, {0, 0}
}
```







### 8. Pointer

`*T` is the type of pointer points to type `T`. `&` and `*` are supported for referencing and dereferencing.

```go
p *int;
```

Specially, the pointer to the field to `struct` also use `.`, not `->` in C:

```go
type Vertex struct {
    X int
    Y int
}

func main() {
    v := Vertex{1, 2}
    p := &v
    p.X = 1e9	// equiv to (*p).X
    fmt.Println(v)
}
```







### 9. Built-in Data Structure

##### # Array and Slice

Type `[n]T` is an array of `n` values of type `T`. The size of array is a part of the type, hence the size of array is fixed.

Instead, a **slice** is dynamically-sized, the type `[]T` is a slice with element T. The usage is basically the same as slicing in Python, the difference is, slicing (as a syntax sugar) in Python create a new list with those sliced eleemnts, while slice in Go (as a data type) is just a **persepctive** of the sliced array:

```go
nums := [5]int {0, 1, 2, 3, 4}
numsSlice := nums[2:4]
numsSlice[0] = 22

fmt.Println(nums) // [0 1 22 3 4]
```

The **length** of slice is the numbers it contains, while the **capacity** of slice is defined as the numbers in underlying array starting from the start of slice. 

```go
func main(){
    nums := [5]int {0, 1, 2, 3, 4}
    numsSlice := nums[1:4]
    fmt.Printf("len=%d cap=%d", len(numsSlice), cap(numsSlice))	// len=3 cap=4
}
```

The zero value of a slice is `nil`, which has a length and capacity of 0, and has no underlying array.





##### # Map

The `map` maps key to value. Use `make` to create a map, use the mpa literal to assign key-value pairs.

```go
var name2age = map[string]int {
    "Robert": 21,
    "Harry": 14,
}
```

Use the conventional subscription `[]` to access and modify the value of map. `delete(m, key)` to delete a key from a map.

```go
fmt.Println(name2age["Harry"])
name2age["Harry"] = 15 
delete(name2age, "Harry")
```

If the key does not exist, the one-value assignment casue panic, the two-value assignment makes the `ok = false` and `v` as the zero value of map's element type.

```go
v = name2age["John"]
v, ok = name2age["John"]
```



##### # Range

use `range` to interates over a slice or map. The behaviour is designed the same for both slice and map: `key/index, value` are returned in both cases. Use `_` to omit one of them (this conventional name is now forced since Go consider the unused variable as compile error), or omit the second variable if only the index is needed.

```go
var pow = []int{1, 2, 4, 8, 16}
var name2age = map[string]int {
    "Robert": 21,
    "Harry": 14,
}

func main() {
    for i, v := range pow {
        fmt.Printf("2**%d = %d\n", i, v)
    }
    for k, v := range name2age {
        fmt.Println(k, v)
    }
}
```







### 10. OOP Mechanism

##### # Method

Class not supported, but you can create **method** for type, a method is a function with **receiver**, which is given between the `func` keyword and function name, this  relative location is same as when we call the method `T.methodname(params)`

```go
type Vertex struct {
    X, Y float64
}

func (v Vertex) Abs float64 {
    return math.Sqrt(v.X*v.X + v.Y*v.Y)
}

func main() {
    vertex := Vertex{3, 4}
    fmt.Println(vertex.abs())
}
```



##### # Pointer Receiver

Use pointer as recevier type, we gain the ability to modify the attribute of struct:

```go
func (v *Vertex) Scale(f float 64){
    v.X = v.X * f
    v.Y = v.Y * f
}

func main(){
    vertex := Vertex{3, 4}
    vertex.Scale(10)
    fmt.Println(vertex)
}
```

Notice that although the receiver is pointer to type `Vertex`, we do not write `(&vertex).Scale(10)` explicitly, which conversion is done automatically.







### 11. Interface

`interface` is a type, which is defined as a set of method signatures, which structure is built automatically as the concrete types are built.

A value of interface type can hold any value that implements those methods. In other words, the interface is marked by its methods or "interfaces".






