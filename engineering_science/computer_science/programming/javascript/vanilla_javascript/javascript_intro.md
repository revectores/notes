# JavaScript Introduction

### 1. Basic MISC

##### # Introduction

JavaScript语言本身不仅仅可以在浏览器中运行, 而是可以在任何搭建了JS解释器的平台上被解释(Node.js, Unity3D, Cocos). 本文档仅仅对JS语言本身的特性进行介绍, 不涉及任何依赖于平台的内容.



##### # Comment

单行注释为双斜杠//, 多行注释前后由/*  */括起.



##### # Delimeter

JavaScript语句由分号分割, 但也允许省略, JS会在缺少分号且无法正确解析代码时自动添加分号. 也就是说如果缺少分号的多行忽略换行符后可以正确解析, 则JS不会对其进行分割, 例如: 

```javascript
var a
a
=
3
console.log(a)

//javascript will consider it as:
var a; a=3; console.log(a);
```

分号可以用于在一行中写多个语句. 早期这个操作常常用于缩小JS大小从而降低文件传输时间, 用于生产环境的JS常常都被压缩在一行内. 实际上这个操作只能省几个`\n`, 目前JS文件大小已经不会再成为性能瓶颈, 这个需求已经不再有意义, 目前如多在一行中写多个语句更多是为了可读性的考虑.

在字符串中可以通过`\`来换行.



### 2. Variable

##### # Declaration

传统的JavaScript语法使用`var [varname]`声明一个变量. 一个`var`可以同时声明多个变量, 它们之间用逗号连接. JavaScript作为动态语言, 在进行变量声明时并不需要指定类型. JS的变量名区分大小写.

允许在声明同时对变量进行赋值. 不赋值时变量值为`undefined`, 这实际上是一个特殊的数据类型. 有时, 为了让变量实际上拥有我们之后希望赋予的类型, 我们会通过`var [var_name] = new [type_name]`的方式为变量赋于一个目标类型的默认值. 例如Number类的实例则为0, string类型则为空字符串等等.



##### # Data Type

我们在[javascript_data_type](/Users/rex/Library/Mobile Documents/com~apple~CloudDocs/skill/notes/engineering_science/computer_science/programming_language/javascript/vanilla_javascript/javascript_data_type/javascript_data_type.md)中详细介绍JavaScript变量的数据类型.



##### # Scope

在函数内用`var`语句声明的变量是局部变量, 在函数外用`var`语句声明的则是全局变量. 如果在函数内对未声明的变量进行赋值操作, 该变量将被自动声明为全局变量.







### 2. Basic Opeartion

##### # Calculation

加法运算允许在数字之间、字符串之间(连接操作), 以及在数字和字符串之间进行, 在最后这种混杂的情况下, 数字将被隐式转换为字符串再进行字符串连接操作. 然后对于其他运算(减法、乘法和除法)而言, 数字和字符串之间的运算都被转化为数字运算.[^1]

```javascript
>>> "1" + "1"
"11"

>>> "1" + 1
"11"
// but:
>>> "1" - 1
0
>>> "1" * 3
3
>>> "6" / 2
3
```

我们也可以利用隐式转换的特点来进行类型转换:

```javascript
// convert a numeric string to number by multipling 1:
>>> "123" * 1
123

// notice that if the string is not a numeric, you'll get NaN
>>> "123a" * 1
NaN

// And we can also change a number into a string:
>>> 123 + ""
"123"
```

JavaScript和大多数正常的语言一样, 除法运算不取整. 取余运算用百分号%表示. JS支持自增和自减操作, 支持算术操作符放在等号左边. 



##### # Equality

JS提供了两种相等层次, 一般的相等`==`要求值相等, 而全等`===`则必须值和类型都相等. 在`==`比较中隐含了隐式转换的过程. 例如:

```javascript
>>> var x = 5
>>> x === '5'
false
>>> x === 5
true
>>> x == '5'
true
```

类似于不等号`!=`, 不全等号为`!==`.

NaN和不等于任何东西, 包括它自身.

```javascript
>>> NaN == NaN
false

// Use isNaN() function to check whether a variable is NaN:
>>> x = NaN
>>> isNaN(x)
true
```

上面提到, JS的弱类型特点会给算术运算的理解带来很多麻烦, 对于比较运算也是如此. JS的比较运算非常混乱, 以至于好事者将其做成了一个表格: http://thomas-yang.me/projects/oh-my-dear-js/





### 3. Function

```javascript
function [func_name] ([args]){
    // ...
    return [value]
}
```







### 4. Control Structure



##### # Condition Structure

JS的条件结构很常规, 包含if和swith并遵循C的一般规范, if/else if后面跟的条件由括号括起, 代码块由大括号标识. swith语句分支需要由break执行退出功能, default语句指定没有匹配时的行为. 

支持三元运算符: 条件?表达式1:表达式2



##### # Cycle Structure

循环结构同样遵循C规范, 有趣的是其for语句允许类似Python迭代器的for(...in...)用法, 注意到在JS中后面有括号括起. 循环过程允许break和continue.



### 5. Error Handling

try...catch(err)...语句用于捕获并处理错误信息, 机制和Python中的try...except...类似, 属性err.message用于获取错误的具体信息.





### 6. Object Oriented Techiques

在JS中一切都是对象. 任何一个变量(无论它是以哪种方式创建的)和函数都是对象. 我们知道对象的特点就是拥有属性和方法, 在以后的内容中我们会具体介绍JS内建对象(如字符串、数字等)的内建属性和方法. 这里只讨论面向对象的一般技术内容. 

除了内建对象以外, JS允许我们通过`new Object()`直接创建自己的对象. 创建了对象以后我们就可以向它随意添加属性与方法并在未来访问. 我们也可以在对象创建之初就定义属性和方法

```javascript
person = {
    age: 20,
    name: 'robert'
}
```

如果一系列对象都具有相同的属性, 那么逐一创建它们就会显得非常繁琐, 因此JS提供了对象构造器: 

```javascript
function objectCreaterName(property1, property2, ...) {
	this.property1 = property1;
	this.property2 = property2;
    function method1(arg1,arg2,...) {
        // ...
	}
}
// Then we can use this "objectCreater" to create new object.
var objectName = new ObjectCreaterName(pro1, pro2, ...)
```

这里所谓的对象构造器非常类似于类的功能, 而下面的语法就像是在创建一个类的实例一样(就正如我们在赋值语句中所做的那样). 但是JavaScript不把它称为类.









[^1]: 实际上这里的operator overloading究竟应当代表何种意义完全是人为规定的.

