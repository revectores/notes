# Regular Expression

### 1. Core Syntax

##### # Basic Concept

**Regular expression(regex, re)** is the universal tool to match or replace text with specific pattern, which is constructed by some symbols and rules. The universality and power has been proved since almost all the modern programming language has implemented the regular expression even its superset. Although the details of syntax might vary across programming languages, the rules of constructing patterns are unitive.

This document specifies the universal syntax of regular expression, while the language-specific part will be introduced in the document of the languages.

One should notice that some syntax only match **THE FIRST** text which meets the pattern, while other match **ALL** the substrings. Furthermore, some languages provide special machanism about precise control, such as specifying whether ignoring cases, multilines, including special character sets, and so on. Most of the special machanism are irrelavent to the core syntax of regular expression itself, but been specifying by specific languages respectively. For example, in Python we'll use `re.search` method to find the first matched substring, while use `re.findall` method to find all the matched substrings.



##### # Match Text

如果要唯一精确匹配某些英文文本, 则在pattern中直接将它们写出来即可, 注意到标准情况的正则是**区分大小写**的, 但也可以在具体语言中通过设定来进行不区分大小写的正则匹配. 

值得注意的一点是, 我们下面将会提到, 某些特殊的字符或字符串序列在模式的构造中有特殊的意义, 这些字符或字符序列称为**元字符(metacharacter)**, 例如句点`.`表示任意一个字符, `w+`表示大小写字母和数字, 如果文本中本来含有这些内容, 就必须在它们前面加上一转移符反斜杠`\`, 反斜杠本身出现在文本中时, 同样也需要被转义.

匹配不可打印的字符有两种方式:

- 使用所需匹配字符ASCII的16进制或8进制表示, 例如`\x0A`表示匹配ASCII 10, 即换行符`\r`, 而`\011`匹配ASCII 9, 即制表符`\t`.
- 直接使用**元字符(metacharacter)**

| Metacharacter | Description | Equivalent HEX Value |
| ------------- | ----------- | -------------------- |
| `\f`          | 换页符      |                      |
| `\n`          | 换行符      | `\x0A`               |
| `\r`          | 回车符      | `\x0D`               |
| `\t`          | 制表符      | `\x09`               |
| `\v`          | 垂直制表符  |                      |

注意到不同的操作系统下标志一行结束的手段是不同的

| Operating System | Line Break Mark |
| :--------------: | :-------------: |
|     Windows      |     `\r\n`      |
|    *NIX/Linux    |      `\n`       |
|      macOS       |      `\r`       |

因此需要根据操作系统来设计不同的正则表达式, 例如如果我们需要查找文本中的**空行**(这意味着两个行结束符连续出现), 那么在以`\r\n`标志行结束的Windows下就需要构造`\r\n\r\n`, 而以`\n`标志行结束的Unix/Linux下只需要写`\n\n`, Mac下则写`\r\r`. 



##### # Match Single Character

[任意单字符]

句点`.`用于匹配单个**任意**字符(包括句点本身), 唯一的特例是换行符`\n`, 注意不是回车`\r`, 回车(好像)是可以被句点匹配的.[^1]



[匹配给定集合内的单字符]

有时我们希望匹配一个属于特定集合中的字符, 这时可以使用中括号[]创建一个**字符集合**, 则在这个集合内的字符都可以被匹配, 例如[ns]可以匹配n或者s, 与此同时还可以利用连字符-来创建基于ASCII的**字符区间**, 例如[a-z]匹配任意小写字母, [A-F]==[ABCDEF], [0-9]匹配任意数字等等, 事实上, 我们可以创建ASCII上的任意连续字符区间, 但最常用的还是字母区间和数字区间, 其他区间都很不直观. 注意这里我们所使用的连字符-是一个特殊的元字符, 因为它只在中括号内是元字符, 而在其他地方只是一个普通字符, 因而在中括号外不需要被特地转义.

值得注意的是, 使用[A-z]并不意味着匹配所有大写字母和小写字母, 这是因为在ASCII表上大写字母区间和小写字母区间之间还存在着另外一些字符, 如果要达到匹配所有字母的目的应该要写成[A-Za-z], 注意区间和区间之间是不用分隔符的(就正如不使用区间时, 各个字母也不需要分隔符一样).

另外, 字符区间的尾字符的ASCII必须要大于其首字符的ASCII, 否则所声明的区间没有任何意义.

显然, 如果中括号中只有一个普通字符, 则它只表示本身, 这时中括号可以脱掉, 例如[0]==0.

我们举一个实用的例子: 匹配HTML代码中使用的6位RGB色值的正则可以写作

`#[0-9A-Fa-f][0-9A-Fa-f][0-9A-Fa-f][0-9A-Fa-f][0-9A-Fa-f][0-9A-Fa-f`

(注意这里同样的模式重复了六次, 显然是非常冗余的, 在后面的重复匹配一节中我们将给出更简明的写法)

值得注意的是, 即使`[`或`]`单独使用, 它们仍然需要被转义(任何配对的元字符, 任何不能单独使用的元字符也都是如此, 这某种意义上体现了正则解释器还是很弱小很依赖语法的严格性的[^2]), 例如, 如果需要匹配一个JavaScript数组模式`myArray[n]`, 那么我们就必须构造一个这样的正则: `myArray\[\d+\]`. 其中作为数组边界的两个中括号被转义, 以表示它们自身, 中间则给出了数字集合.

[取非运算]

中括号可以配合取非运算符`^`进行使用, 它意味着匹配任何**不在**所声明字符集合中的字符(注意是`^`作用于中括号整体, 并不仅限于紧跟在它后面的字符). 取非运算符必须放在中括号内部的**最开头**进行使用, 否则会被解释为一个普通字符. 

[字符集合的简化写法: 类元字符]

我们常常将一些常用的字符类型(称为**字符类**)用元字符(称为**类元字符**)来代替. 值得注意的是, 类元字符在正则语法中并非必不可少的技术手段, 你总是可以通过构造一个字符集合来替代它, 下面的表格中给出了常用的类元字符

| 类元字符 | Description                | Equivalent     |
| -------- | -------------------------- | -------------- |
| `\d`     | 任何一个数字字符           | `[0-9]`        |
| `\w`     | 任何一个数字、字母或下划线 | `[A-Za-z0-9_]` |
| `\s`     | 任何一个空白字符           | `[\f\n\r\t\v]` |

将其中任意一个类元字符改成其所对应的大写就相当于取非操作, 例如`\D`表示非数字字符, 等效于`[^0-9]`

另外还有一种被称为**POSIX字符类**的技术, 其“类元字符”的形式比较特殊, 如下表

| POSIX Character Class | Equivlent                                         |
| :-------------------: | ------------------------------------------------- |
|      `[:digit:]`      | `[0-9]`                                           |
|     `[:xdigit:]`      | `[a-fA-F0-9]`                                     |
|      `[:lower:]`      | `[a-z]`                                           |
|      `[:upper:]`      | `[A-Z]`                                           |
|      `[:alpha:]`      | `[a-zA-z]`                                        |
|      `[:alnum:]`      | `[a-zA-Z0-9]`                                     |
|      `[:blank:]`      | `[\t]`                                            |
|      `[:space:]`      | `[^\f\n\r\t\v]`                                   |
|      `[:cntrl:]`      | ASCII 0~31 + ASCII 127                            |
|      `[:print:]`      | Any printable character                           |
|      `[:graph:]`      | Any printable character but space                 |
|      `[:punct:]`      | Any character besides `[:alnum:]` and `[:cntrl:]` |

POSIX类元字符在地位上实际上相当于不带中括号的字符集合, 因此使用时必须在两边再嵌上一层中括号, 这样一来实际到手的正则中就有两层中括号, 值得注意. 例如对于上面的RGB匹配, 我们可以使用POSIX的`[:xdigit:]`进行改写: 

`#[[:xdigit:]][[:xdigit:]][[:xdigit:]][[:xdigit:]][[:xdigit:]][[:xdigit:]]`



##### # Types of Metacharacters

我们应当注意到, 句点`.`是一个元字符, 当且仅当它不被转义, 而`\n`是一个元字符, 当且仅当它被转义, 如果n前面没有转义符号, 则它将被作为一个普通字符. 因此, 元字符可以被分为由普通字符转义而成的(如`\n`), 和直接借用普通字符的(如句点`.`和中括号`[]`等等)两类. 这种构造方式在很多地方都存在. 

另一方面, 从语法上看, 元字符可以分为**用于匹配文本的**(如句点.)和正则**语法所要求的**(如中括号[])两类.

在上面讨论字符集合时我们注意到, 连字符`-`仅仅在中括号内才成为一个元字符, 在中括号外则只是一个普通字符. 反过来, 除此之外的大多数的元字符在中括号内都只是一个普通字符, 例如加号、句点等等, 都只表示匹配它们自身, 不需要被转义, 但对它们进行转义并不会发生语法错误, 效果是一样的, 只是没有必要.



##### # Match Repeatedly

如果需要匹配某一字符或字符集合的**一次或多次**重复, 可以使用`+`, 例如`a+`将匹配一个或多个连续出现的`a`, `\d+`匹配一个或多个连续出现的数字, 等效于`[0-9]+`. 在这里例子中我们为字符集合添加加号后缀, 必须注意将+放在字符集合的外面而不是里面, 如果写成`[0-9+]`, 则其中的`+`将会退化成一个普通字符.

类似地, 星号`*`可以匹配**零次或多次**重复, 问号`?`匹配一个字符的零次或一次重复(可以形象地理解为问号前面这个字符“可有可无”). 实现重复匹配的三个元字符在实践中被广泛应用, 以下举两个应用中的简单实例

1. 匹配一个HTTP或HTTPS的URL: `https?://[\w.\/]+`
	
	在这个正则中有两个值得注意的语言点: 第一是s后面的问号, 表示匹配`http`或者`https`; 第二是字符集合中, 语义上作为路径分隔符的正斜杠/和反斜杠之间的微妙关系: 我们注意到正斜杠/本身在正则中并不是一个元字符, 然而我们在这里却仍然将它转义了, 这是由于某些特殊的正则实现对正斜杠有特殊理解: 在JS中, 正斜杠被用作正则两端的**分界符**, 也就是说**JS使用正斜杠来标志一个正则表达式的边界**, 如果不对其转义则会发生定界错误, 当然, 如果十分清楚在自己所写的实现中不存在这个问题, 那么也可以不转义. 

2. 兼容版本的空行匹配: `[\r]?\n[\r]?\n`. 我们使用中括号把`\r`给括了起来`[\r]?`. 实际上这和`\r?`是等效的, 这样写纯粹是为了代码可读性, 以便于我们能够清晰地在复杂的转义符号中看出问号是和哪些内容配对的. 

除了上述三个符号以外, 正则提供了对重复次数的精准控制机制. 重复次序(或重复次序的区间, 甚至可以是开区间)由一对大括号`{}`标志, 对于上面的RGB模式, 我们现在可以改写成: `#[[:xdigit:]]{6}`.

对于重复区间, `{0,3}`表示可以重复次数可以是0,1,2,3, 也就是包括两个端点在内的所有整数, 逗号右边也可以留白表示开区间(注意左边是不能留白的, 必须给一个起始位点), 因此我们完全可以用区间来表达上面的三个特殊符号: 

| Metacharacter | Equivalent |
| :-----------: | :--------: |
|       ?       |   {0, 1}   |
|       *       |   {0, }    |
|       +       |   {1, }    |



##### # Greedy Mode and Lazy Mode











[^1]: QUESTION: 句点对回车和换行的匹配, 这里参照的是《正则表达式必知必会》P14的叙述, 有待进一步考证.P1
[^2]: 但其实根据正则表达式的不同实现, 在某些程序设计语言中会提供相应容错的支持, 不过最好不要依赖这种行为, 因为这不是正则的标准语法.



