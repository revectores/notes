# Web

页面中的常用数据隐藏手段：

- 源码注释

  有时候源码里会放后台的PHP和MySql代码（显然这就是一道审计题）

- 放在Response Header里

- 





### 2. SQL Injection

##### 2.1 基础注入方式

常规登陆的SQL语句写法

```SQL
SELECT * FROM database WHERE username='username' and password = 'password'; 
```

这里的`username`和`password`是用户输入数据.

构造`password`为`' or '1' = '1`使得原SQL查询语句结构变成

```SQL
password = '' or '1' = '1'; 
```

注意到在构造出的`' or '1' = '1`中，最前面的单引号用于封闭查询语句中前面的单引号，之后的语句用于构造一个恒等式，最后的单引号由查询语句提供。

对于这种简单的注入有很多种构造注入语句的方法，上面是比较好理解的一类，实际上可以写成更简单的形式：`' or '1`, 那么构造后的语句成为

```SQL
password = '' or '1';
```

这样做可行的原理是php字符串强制转化为bool型时的转化规则：（特别要注意的是php类型转换规则非常特立独行）即空字符串和'0'为false而其他任何字符串为true. 所以这里的'1'会被强制类型转换为true, 和上面的表达式的效果一样. 为什么这个简化如此重要呢？因为并不是所有情况下我们都能够完全控制注入方式，例如在MD5注入中，//TODO

我们发现上面的两种注入方式都需要用到`or`语句，但是如果`or`被过滤掉了怎么办呢？还有一类构造要求同时控制`username`和`password`, 同时输入`1'='0`或`'='`.  这里涉及的具体php和sql的执行机制暂时不是非常明确，有待测试，但是实践上表明这样操作的确是可行的. // TODO

`$sql = "username='1'='0' and password='1'='0'"`

`$sql = 'username='=' and password='=''`



解决方案：禁止用户输入可能引起注入的危险字符`'`, `or`等等。

##### 

##### 2.2 报错注入

报错注入故意构造某些错误的语句，诱导错误信息产生，从而得到关于后台的某些信息。

还是考虑通常的登陆入口

```SQL
SELECT * FROM database WHERE username='username' and password = 'password'; 
```

假设我们强行在其中插入某些可执行语句并故意构造错误，就有可能使得错误信息在前端反馈出来，常见的有`extractvalue`语句和`updatexml`等.

例如如果我们构造`username = extractvalue(1, concat(0x5c,(select database())))`

解释一下这里的函数结构：外层的`extractvalue`是查询`xml`信息的语句，第一个参数是目标xml文档，第二个参数是xml路径，我们在这里需要利用的性质是：当路径的格式存在错误时，`extractvalue`函数将会在前端dump出错误信息，其中包含了所写的错误路径。那么现在有两个问题：如何在其中写入想要的信息，以及使其是错误的路径呢？

为了获取想要的信息我们需要构造sql语句，例如这里特殊的`select database()`返回当前查询的数据库名，这就意味着通过这种方式我们把语句中的`database`信息给提取了出来（事实上只要没有过滤，这个地方可以写任意的sql语句，从而提取任何想要的信息）；`concat`的作用是强行加入一个不应该出现在路径名中的字符（这里是`0x5c`也就是`\`, 通常也会使用`0x7e`也就是`~`），从而保证路径格式是有问题的。



##### 2.3 过滤绕过

server端为了避(chu)免(ti)sql注入常常会使用某些方式过滤掉某些敏感字符串（涉及到过滤时web题中时常会给出被处理过的字符串是什么样的，如果没有的话就需要自己看报错信息判断了），这时候我们就需要根据被过滤掉的字符来采取一定的措施去规避。以下讨论均假设原先需要构造的语句写作

```sql
SELECT flag FROM flag
```

**针对关键字被过滤的绕过**：

- 双写绕过：服务端检测sql关键字并从原始字符串中去掉，但有时候（程序员比较懒）只去掉了第一个，这时候就可以通过再写一遍来解决问题：

  ```sql
  SELECTSELECT flag FROMFROM flag
  ```

  注意到这里所查询的表名和列名并不是sql关键字，因此并不需要双写.


**针对空格过滤的绕过**：

- 加号绕过：利用php一个奇特的特性：加号在传输到服务端时会莫名其妙地变成空格，所以如果空格被滤掉了可以用加号来替代

  ```sql
  SELECT flag FROM flag
  ```

  ```sql
  SELECT+flag+FROM+flag
  ```

- 注释绕过：注释会被去掉，而影响语法时会自动替换成空格，因此可以用来绕过

  ```sql
  SELECT/**/flag/**/FROM/**/flag
  ```
