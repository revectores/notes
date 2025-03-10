# HTML Basic

> **Ability Stack**
>
> 本文档的核心目的在于使得读者能够写出一个基础的原生HTML4.0 document. 其中最重要的是理解链接、图像、表格、列表、框架, 以及表单这几个重要的HTML要素的使用.
>
> 
>
> 具体而言, 本文档的完整阅读者将具备以下能力: 
>
> 1. 理解HTML的基本概念, 包括什么是HTML、元素和标签的意义, 以及能够配置HTML开发环境.
> 2. 理解HTML文档的基础结构性标签: html, head, body, doctype, title,style, script的结构意义, 以及注释的语法.
> 3. 理解重要的内容标签title, h1~h6, p, 理解重要的格式化标签br, hr
> 4. 理解块级元素和内联元素的概念, 以及与此相关的div和span的使用.
> 5. [!] 理解链接a、图像与映射img, map、表格table, th, td, th, caption、列表ul, ol, li、框架frameset, iframe等非常重要的HTML要素的使用方法.
>
> 6. 理解表单form, input的使用, 由于这方面涉及到与服务器端的交互, 建议与PHP方面的内容结合理解.
> 7. 理解首部元素中的base.
> 8. 理解首部元素中的meta, 其"name content"键值对和"http-equiv content"在应用情景上的差异, 以及常见的键值.
> 9. 理解传统的通用样式类属性bgcolor, background, align, width, height, 和一些样式类标签. 这些样式类属性在现在大多数都已经被CSS取代因而不再推荐了, 而大部分样式类标签甚至在新的HTML5标准中被废弃, 但是通过原生HTML的写法仍然不失为一种有趣的实现方式.
> 10. 理解短语元素的使用.
> 11. 理解防止语义冲突的字符实体技术.
>
> 充分理解本文档内容的读者应当能够独立完成后面的第一部分练习题, 而第二部分的练习题则和其他文档的内容有关, 或者需要查找相应的参考资料才能够完成.
>
> 
>
> **Reference**
>
> 本文档使用了来自以下书籍/web站点的参考资料: 
>
> http://www.w3school.com.cn/					HTML教程部分



### 1. Basic Concept

##### # Introduction

**超文本标记语言(HyperText Markup Language, HTML)**是用来描述网页[^1]的一种标记语言. 注意它的属性是一种**标记语言(markup language)**而不是编程语言(programming language). 标记语言的特点是使用一套**标记标签(markup tag)**来描述它所想要表达的内容, 如HTML, XML, 以及Markdown等等. 

浏览器的任务就是根据HTML内容来解释网页, 渲染出多样的网页效果.



##### # Element and Tag

一个HTML页面由各种**元素(element)**嵌套组合而成. 元素由**标签(tag)**及其内容构成. 为了明确一个元素的边界, HTML中的绝大部分标签成对出现, 分别称为**开始标签(start tag)**和**结束标签(end tag)**, 或者称为**开放标签(opening tag)**和**闭合标签(closing tag)**, 结束标签是对应的开始标签在标签名称前加上反斜杠/. 开始标签和结束标签之间的部分就是这个元素的内容. 

有一些元素没有内容, 称为**空内容(empty content)**, 这时候就不需要结束标签, 但是根据严格的XHTML规范, 任何标签都必须关闭, 这时我们需要在开始标签的最后加上`/`强调闭合的语义.

```html
<br />
<img src="picture.jpg" />
```

元素的属性规定了该元素的一些性质, 例如表现形式(也就是样式)[^2]、所指向URL等等, 属性写在开始标签内, 例如.

```html
<p id="p1" font-color="red"></p>
```

注意严格意义上属性值都要由引号予以括起. 标签名、属性、属性值都是不区分大小写的. 建议均采用小写.

尽管元素是包含标签在内的广义概念, 但是由于其抽象性, 实际上在叙述具体标签使用的时候, 往往并不会用到"元素"这个词, 而是直接叙述更为实在的"标签". 应予以注意.



##### # Block Element vs Inline Element

HTML元素根据样式的不同可以划分为**块级元素**(block-level element)和**内联元素**(inline element), 块级元素通常占据单独的一“块”, 每一块级元素都至少占据一行, 并且在其内容前后都有一空行与其他元素分隔开(不需要手动添加`<br />`); 而内联元素则嵌在块级元素中. 因此: 块级元素可以包含块级元素或内联元素, 内联元素只能包含内联元素. 

块级元素`<div>`和内联元素`<span>`没有特殊的语义, 它们一般用于标志HTML文档中的不同区域, 以便于统一进行样式管理.



##### # Semantic HTML

HTML语义化视角认为, 标签标志着一种语义, 我们应当依据标签蕴含的语义而不是表观样式来构建HTML页面. 尽管浏览器会赋予内容标签一个样式, 但浏览器的默认样式不应该成为选择这个标签的理由, 因为你永远都可以用CSS把内容规定为任何你希望的样式. 标签和样式并没有直接的关联. 语义化有两个优势:

- 便于自动化处理, 特别是搜索引擎对页面的索引. 搜索引擎在检录网页时将按照标签的语义来对整个页面进行定性, 例如标签`<h1>`的重要程度比`<h2>`高, 则搜索引擎在分配权重时(关键词检索)将更重视`<h1>`里的内容.
- 便于无障碍阅读. 无障碍辅助工具高度依赖于有意义的页面. 合理的语义化能够帮助无障碍工具高效运转.





### 2. Common Tag

##### # Structual Tag

一个常规的HTML页面以`<html>`作为最外层标签, 表示整个HTML页面. 只有`<!DOCTYPE>`标签位于html标签对之前, 其他内容均位于html标签对之间. `<head>`标签标志页面头部. `<body>`标签标志页面的主体, 在浏览器上显示的内容都包含在该标签对内.

`<!DOCTYPE>`用于声明文档类型, 必须写在第一行. 声明紧跟在标签名后面. <!DOCTYPE>虽然格式类似于开始标签, 但并不是一个真正的标签, 因此没有结束标签. 

```html
<!DOCTYPE html>
<html>
    <head>
        <!-- head goes here... -->
    </head>
    <body>
        <!-- body goes here... -->
    </body>
</html>
```



##### # Head Tag

`<title>`用于设定当前页面的标题, 这会在三个地方显示: 浏览器的标签页上、页面被收藏到收藏夹中的默认标题, 以及显示在搜索引擎结果中的标题. 由于和SEO紧密相关, 因此标题的设置是非常重要的.

 `<base>`的`href`属性用于确定页面全局URL基准地址.

```html
<base href="http://www.bilibili.com/">
<a href="video/av5686929/">
   
<!-- equivalent to
<a href="http://www.bilibili.com/video/av5686929/">
-->
```

`<base>`的`taget`属性确定页面全局链接跳转的页面开启模式

```html
<base target="_blank">
```


也可以将`target`设置成某个框架.

`<link>`和`<style>`用于样式导入和配置.



##### # Meta Tag

元信息标签`<meta>`同样位于`<head>`中, 用于声明该页面的有关信息. 其内容为空, 且没有闭合标签. 声明的内容在开始标签以键-值对方式体现. 格式为: 

```html
<meta name=[key] content=[value] />
<meta http-equiv=[key] content=[value] />
```

第一种格式用于告知搜索引擎该页面的内容, 多用于[搜索引擎优化](), 其中常用的key有`keywords`(声明这个网页的关键词)和`description`(对这个网页进行描述), 当搜索引擎对页面进行检索时, 会主动寻找`<meta>`中的这两个key, 利用它们来了解这个网页的特点, 为结果排序提供参考. 搜索引擎通常会将网页的`description`显示在搜索结果中.

第二种格式则用于告知浏览器页面的基本信息, 例如声明该页面所用的字符集, 常用的key有`content-type`声明页面的MIME类型及所用字符集, `content-language`声明页面语言等.

不同的键值对必须放在不同的`<meta>`标签之中, 不允许在一个标签内放多个键值对. 

注意, 如果在首部没有用`content-type`显式声明页面的MIME类型, 则默认被解释为html, 即default状态下的meta是

```html
<meta http-equiv="content-type" content="text/html">
```

但是我们会发现这两种方式意义的分界并不是那么严格, 例如`name`格式可以使用一种名为`renderer`的key, 这个key是用来建议双核浏览器默认情况下用哪一种方式来渲染页面的, 可选的content有三项, 分别指定webkit内核、IE兼容模式和IE标准模式(奇特的是, 许多银行网站似乎都没有令renderer=ie-stand, 看来双核浏览器实现银行网站的自动切换似乎并不是靠这个renderer).

所以说其实也不必机械地看待`name`和`http-equiv`的区分, 毕竟协议都是server同搜索引擎/浏览器之间可以自行商定的, 只是一般来说它们分别使用name和http-equiv作为公认标识而已.

默认情况下浏览器一般会将刚浏览过的页面缓存在本地, 以避免短时间内重复加载所造成的资源浪费. 但如果页面因具有时效性等原因希望建议[^4]浏览器每次访问时都重新加载页面, 则需要在meta标签中进行以下声明:

```html
<meta http-equiv="pragma" content="no-cache" />
<meta http-equiv="cache-control" content="no-cache" />
```

由于不同浏览器的性格不同, 可接受建议不同, 因此在必要时应当尽量写全.



##### # Content Tag

 `<h1>~<h6>`分别表示1~6级的标题, `<p>`则标志一个段落. 



##### # Comment Tag

```html
 <!-- This is a comment -->
```

Notice that there is an exclamation point `!` in the start tag, but not in the end tag. As in other programming languages, we can use the comment tag to temporary disable some codes for debugging.



##### # Formatting Tag

浏览器在渲染HTML时会自动忽略其中多余的空格和换行, 所有的换行和空格不论在HTML原始文档中出现了多少次都当做一个空格来处理. 因此在源代码中进行的排版不会显示在前端, 这时如果我们需要换行就需要特殊的标签`<br />`, 注意到由于其是空标签因此在开始时应予以闭合, 另外`<hr />`用于插入水平线, `&nbsp;`用于插入空格.

事实上这里的`&nbsp;`是一种用于代替空格的[**字符实体(entity)**]().



##### # Link and Anchor

链接是万维网的精髓之所在, 它使得一个资源可以包含指向其他资源的内容, 使得万维网称为一个超文本系统, 便于用户访问. 

HTML利用标签`<a>`来创建一个链接, 其href属性指明链接的URL(严格地说是URI, 关于URI和URL的语法参见Computer Network - HTTP potocol部分), 例如, 我们可以创建一个指向google首页的链接: 

```html
<a href="http://www.google.com">Click me to enter Google!</a>
```

在没有指定特殊CSS的情况下, 浏览器会将作为超链接的文字(在尚未被点击的情况下)以蓝色+下划线显示, 以突出这是一个链接.

现在我们假设有一个非常长的HTML页面, 用户如果要迅速找到他所需要的资源就不太方便, 一个自然的想法是在建立一个目录, 并且将其放在页首, 用户点击目录中的某一个内容时就可以自动跳转到相应的部分(这也就是大部分百科词条的通用做法, 例如wikipedia和百度百科), 那么这要如何实现呢? 首先我们必须对跳转的位点建立一个**锚(anchor)**. Anchor同样也是以`<a>`标签来创建的, 本质上锚就是一个设定了`name`属性的`<a>`标签: 

```html
<a name="history">
```

这样我们就建立了一个名为history的锚, 之后就可以在页面的其他地方创建链接来跳转到这个anchor的位置上(同样也是使用href属性, 但锚的名称前必须加上#, 以告知浏览器这是一个anchor).

```html
<a href="#history">
```

页面间跳转和页面内跳转可以结合起来使用, 即跳转到另外一个页面的某个anchor上. 

如果从页面外部引用了一个不存在的锚, 不会发生错误, 只是停留在页面开头; 而如果从内部引用了一个不存在的锚则什么也不做.

最后`<a>`标签还有一个`target`属性, 默认情况下点击链接将会直接在本页面上打开新页面, 而设定`target="_blank"`以后则可以使页面在新的选项卡中打开. 



##### # Img

图像由`<img>`标签标志, 该标签没有内容. `src`属性指定图像在服务器上的位置. 图片的宽度和高度分别由`width`属性和`height`属性指定, 如果只指定了其中一个而没有指明另外一个的话, 则原图像将按比例缩小显示.

`alt`属性用于浏览器加载图片失败时的文字提示, 有些浏览器将鼠标移到图片上也会显示`alt`属性所定义的提示文字.

`<img>`标签也可以作为`<a>`的内容, 则当用户点击图片时会跳转到指定的`href`, 例如, 以下标签使得用户点击时直接访问图片的源地址: 

```html
<a href="picture.jpg"><img src="picture.jpg" /></a>
```

值得注意的是, `img`标签中的`src`不受[同源策略]()的限制, 也就是说允许对其他服务器上的资源发起访问请求, 浏览器不会对其进行检查. 这也就意味着我们可以首先通过JS获取用户的某些信息(尤其是cookie)并且通过将其嵌入到img标签的src属性中的方式对自己原先已经部署好的服务器发起GET请求, 从而得到用户的信息.

`<map>`标签建立了一个映射, 规定图像中某些像素行使相当于`<a>`的功能. 当img使用`mapname`属性引用`<map>`标签时, 就会按照标签中指定的法则形成图像中相应的可点击区域. 图像的不同区域可以指向不同的链接, 每一个区域由一个子标签`<area>`规定.


需要注意的是, `<map>`的两个属性`name`和`id`都表示其名称, 但不同的浏览器在执行`<img>`的mapname属性引用时所依据的`<map>`属性是不一样的, 可能是name/id二者之一, 因此要两个都写上(当然是写一样的, 除非你想让不同浏览器进行不同的映射, 这是很破坏客户端透明性的一个行为).

`<area>`标签是`<map>`的子标签, 具体规定单个区域的映射. area标签的属性主要是`shape, coords, href`.

`shape`和`coords`协同作用, 前者规定映射区域的形状, 后者则规定具体的参数, 参数的个数由shape的值确定: 

- `shape="circle"`时, coords有3个参数: 圆心x坐标, 圆心y坐标, 半径. 
- `shape="rect"`时, coords有4个参数: `x1, y1, x2, y2` , 指名了矩形对角线两端的坐标. 
- `shape="poly"`时, coords有2n个参数: `x1, y1, x2, y2, ..., xn, yn`, 指明了多边形各个顶点的坐标, 多边形会自动封闭, 最后不需要重复起点坐标.

实例[https://www.w3schools.com/tags/tryit.asp?filename=tryhtml_areamap](https://www.w3schools.com/tags/tryit.asp?filename=tryhtml_areamap)展示了`area`的应用.[^5]

```html
<img src="workplace.jpg" alt="Workplace" usemap="#workmap" width="400" height="379">
<map name="workmap">
  <area shape="rect" coords="34,44,270,350" alt="Computer" href="computer.htm">
  <area shape="rect" coords="290,172,333,250" alt="Phone" href="phone.htm">
  <area shape="circle" coords="337,300,44" alt="Cup of coffee" href="coffee.htm">
</map>
```

<img src="workplace.jpg" alt="Workplace" usemap="#workmap" width="400" height="379">

<map name="workmap">
  <area shape="rect" coords="34,44,270,350" alt="Computer" href="https://en.wikipedia.org/wiki/macbook">
  <area shape="rect" coords="290,172,333,250" alt="Phone" href="https://en.wikipedia.org/wiki/IPhone">
  <area shape="circle" coords="337,300,44" alt="Cup of coffee" href="https://en.wikipedia.org/wiki/coffee">
</map>



##### # Table

表格由`<table>`标签定义, 其子标签`<tr>`标签定义表格的一行, 而`<tr>`的子标签`<td>`定义行内的一个单元格. 显然, 对于一个所有单元格都一样的表格, 所有`<tr>`中的`<td>`个数都应当相等. 注意到有一些浏览器无法正常显示空的`<td></td>`对, 此时需要加空格占位符.

我们可以把第一个`<tr>`中的`<td>`换成`<th>`来定义**某一列的**表头. 

在所有`<tr>`之前还可以加上`<caption>`来定义表格的**标题**. 标题可以有多个, 不同的标题将按顺序占据不同的行. 

定义某个单元格所占的列数可以通过其`colspan`属性指定, 而所占行数则通过`rowspan`属性指定, 在这种情况下为了保持表格的规范性, 每个`<tr>`中的`<td>/<th>`可能会不相等. 示例代码请参见http://www.w3school.com.cn/tiy/t.asp?f=html_table_span.



##### # List

HTML中的列表分为**无序列表**`<ul>`和**有序列表**`<ol>`两类, 显然, 无序列表的语义是一个无序的集合, 在默认样式上表现为每一项前面的标志都是一样的, 默认情况下是小圆点`·`, 而有序列表的语义则是一个有序序列, 在默认样式上表现为某种有序排列, 默认情况下是`1, 2, 3...`

`<ul>/<ol>`中的项均以`<li>`表示. 列表可以嵌套, 在编写嵌套列表时要注意标签的顺序和完整性. 

还有一类有特殊语义的列表称为**定义列表**, 由一组**名词及其解释**构成, 一个定义列表由`<dl>`标志, 其中需要被解释的名词由`<dt>`标志, 在一对`<dt>`标签后紧跟的`<dd>`标签表示对上一个`<dt>`的名词解释.

```html
<dl>
<dt>Computer</dt>
<dd>A machine used to compute</dd>
<dt>Monitor</dt>
<dd>Showing information via visual form</dd>
</dl>
```

<dl>
<dt>Computer</dt>
<dd>A machine used to compute</dd>
<dt>Monitor</dt>
<dd>Showing information via visual form</dd>
</dl>


##### # Character Identity

由于例如某些符号在HTML代码中有特殊的含义(例如"<",">"用于标记标签的开始和结束), 如果要在浏览器中显示出它们就不能用原来的符号, 否则文档在加载时就已经被错误地解析. 这时候要用另一些符号来代替这些特殊字符. 这些符号被称为字符实体. 

字符实体格式为`&entity_name`或`$#entity_number`.

例如, 空格的实体名称是`nbsp`, 编号是160, 则一个空格应当写作`&nbsp;`或`$#160;`.

采用实体名称能够帮助开发者更好地记忆和维护文档, 但并不是所有的浏览器都支持最新的实体名称.

常用的特殊符号对应的实体名称及编号如下

| Symbol | Identity Name | Code |
| :----: | :-----------: | :--: |
|   <    |      lt       |  60  |
|   >    |      gt       |  62  |
| space  |     nbsp      | 160  |
|   &    |      amp      |  38  |
|   "    |     quot      |  34  |








### 3. Form

表单用于数据提交, 整个表单由`<form>`标签标记. `<from>`标签的`action`属性规定了表单数据提交的目标URL. `form`的众多的子标签以及`<input>`标签的众多`type`属性类型实现了不同的数据输入模式.



##### # `<input>`

`input`标签是表单最重要的一个子标签, 根据其`type`属性的不同可以变化为不同的形式. 常用的`type`有

| `type` of `<input>` | Rendering Output    |
| ------------------- | ------------------- |
| `text`              | single line textbox |
| `radio`             | single selection    |
| `submit`            | submit button       |

`input`常用属性除`type`外还有`name`和`value`, 前者规定了该标签的名称, 以便于在PHP中使用关联数组对其进行处理, 不同的`input`不允许具有相同的`name`, 当然`submit`标签没有必要设定`name`. 而`value`属性则规定了`input`在页面上显示的(默认)值.[^3]







### 4. Frame

##### # `<frameset>` and `<frame>`

框架使得你可以在一个HTML页面上显示多个其他页面(使用<frameset>)或者在页面中嵌入其他页面(使用<iframe>).

`<frameset>`标签标志一个框架的集合, 它的地位和body平等, 也就是说`<frameset>`并不被嵌套在`<body>`中, 而是直接作为一个大的容器元素而存在. 不过值得注意的是, 不同于body的唯一性, frameset自身也是可以嵌套的.

一个`<frameset>`含有多个`<frame>`子标签标志每一个框架, `<frame>`子标签的`src`属性表明了框架内所显示页面的URL. 下面是一个frameset结构的例子: 

```html
<frameset cols="50%,50%">
	<frame src="http://www.baidu.com" />
	<frame src="http://www.bilibili.com" />
</frameset>
```

注意到我们为frameset标签添加了cols属性并为其赋上了`"50%, 50%"`的二元元组值, 这是在规定框架的显示方式: 将HTML页面均等地划分为两列并分配给两个框架显示内容. 如果要将HTML划分为多行, 则应使用`rows`属性. 在绘制框架时必须选择`cols/rows`二者之一, 否则页面将无法正确显示整个框架. 

另外值得说明的一点是, 从`<a>`的`href`属性我们已经知道, 页面可以通过`anchor`进行锚定, 同样的frame的src属性也可以利用这一点, 从而将框架的默认显示状态调整到某一个特定的anchor上.

我们可以使用嵌套的方式来将HTML页面同时以水平和竖直两种方式进行划分. 例如下面的代码就先将页面划分成均等的两行, 再将后一行划分成不均等的两列: 

```javascript
<frameset rows="50%,50%">
    <frame src="http://www.baidu.com" />
    <frameset cols="25%, 75%">
    	<frame src="http://www.51cto.com" />
    	<frame src="http://www.bilibili.com" />
	</frameset>
</frameset>
```

在默认情况下, 框架之间的分界可以被拖动, 从而改变各个框架在页面中所占的比例, 如果希望禁止这种行为, 可以通过添加属性`noresize="noresize"`的方式来实现. `noresize`属性可以添加在`<frameset>`标签中或`<frame>`标签中, 如果添加在前者中, 则是全局下都禁止了改变框架大小, 等效于给每一个`<frame>`都添加上`noresize`. 



##### # Navigation by Frame

我们知道`<a>`标签的`target`能够指定href所指向的新页面在何处打开: 默认是覆盖当前页, 而`target="_blank"`则打开新标签页. 事实上除了以上两处外, 链接还可以在框架内打开, 实现如下:

```html
<!-- frame.html -->
<a href="http://www.baidu.com" target="example1">Show me baidu!</a>
<a href="http://www.51cto.com" target="example1">Show me 51cto!</a>
```

```html
<!-- index.html -->
<frameset cols="15%, 85%">
	<frame src="frame.html" />
	<frame src="http://www.bilibili.html" name="example1" />
</frameset>
```

这里我们额外建立了一个文件`frame.html`来显示目录内容, 这是因为一旦创建`frameset`结构就不可能向其中添加任何非`frame`标签了, 因此只能用另外一个文件写好代码再通过框架引用它. 

在上面这个实例中, 我们将右边框架的`name`属性设定为`example1`, 从而可以利用`<a>`的`target`属性对其进行引用, 使得新打开的标签页在这个框架内打开. 由于这种设计很适合用于目录导航, 因此被称为导航框架技术.

这个实例同时也说明了框架之间实际上是可以进行交流的. 现在我们假设这样一种情况: 如果一个纯粹是为了被框架引用而设计出来的页面(就像上面的index.html那样)被单独打开了, 那么点击其中原来指向其他框架的链接将会发生什么呢? 由于找不到这样的target, 是不是什么也不做呢? 答案是否定的, 本地实验说明, 如果找不到对应的target, 则浏览器会将链接在新窗口打开, 也就是等效于`target="_blank"`.



##### # `<iframe>`

大多数情况下我们并不希望为了显示某个页面而牺牲掉所有其他标签的可用性, 因此更多时候我们一般使用内联框架, 在页面中嵌入其他页面. 内联框架的标签是`<iframe>`, 其属性`src`指定源, 属性`width`和`height`指定显示的大小(或比例). 

不过即使你将`<iframe>`的width和height都调整到100%, 在大多数浏览器中内联框架也不会占据全部页面, 而是会在四周留下空隙, 表明这是一个内联框架.

`iframe`通过设定`name`属性也可以成为`<a target="iframe">`的目标. 







### 5. Phrase Element

短语元素是为了给文档中某些元素的某些部分标记上特殊的含义而存在的, 这些元素通常作为内联元素而存在. 浏览器一般会为短语元素赋予一些特殊的样式, 但是永远不要为了这些样式使用短语标签, 正如前面强调过的那样, CSS会给你更好的效果.



##### # Emphasis`<em>, <strong>`

`<em>`定义强调语气, 而`<strong>`定义更强的强调语气

`<em>`在样式上类似于`<i>`, 而`<strong>`在样式上会类似于`<b>`, `<i>,<b>`这两个样式类标签已经不被建议使用了.



##### # Code Phrase

作为内联元素的`<code>`很适合用于标记行内代码, 但是当代码有多行, 并且可能有缩进时, 就需要在外边套上一层`<pre>`[^6]来预定义格式.` <pre>`能够将文本以HTML源码中原本的格式输出. 多行代码单独使用`<pre>`虽然在样式上能够起到相同的效果, 但是由于`<pre>`本身是不带有“表示代码”的语义的, 因此去掉`<code>`单独只用`<pre>`就无法起到语义化的效果. 

关于嵌套的顺序问题, 尽量应当将`<pre>`设置在外层, 毕竟原则上来讲`<pre>`是块级元素而`<code>`是内联元素(实际上哪种顺序都不影响).

`<var>`用于标记变量. 



##### # Abbreviation

`<abbr>`标签标志它所括起的内容是一个缩写, 该标签常常与属性title联合使用, 使得当用户鼠标停留在缩写上时能够及时提示完整的拼写. 

`<acronym>`则在缩写的基础上进一步强调这是一个“首字母缩写”, 同样可以结合title, 但是在新的HTML5标准中已经不再支持`<acronym>`, 只能用`<abbr>`替代. 







[^1]: 事实上通常意义上的网页等价于HTML文档.
[^2]: 众所周知, 现代前端开发已经基本不可能再使用HTML属性来控制元素样式, 但出于完整性考虑我们仍然会介绍HTML标签属性的这一功能.
[^3]: 由于`input`元素根据`type`的不同, 其值可能是可变的如`text`或不可变的如`radio/submit`, 对于值可变的`input`元素, `value`只能称为它们的默认值.
[^4]: 事实上HTML资源无法强制浏览器实行任何行为, 因此页面只能“建议”浏览器这么做, 至于最后的行动则完全取决于浏览器的意愿.
[^5]: Typora支持`map`映射, 因此我们甚至可以直接在Typora文档中看到渲染这个效果.

[^6]: 预定义格式标签`<pre>`并不是短语元素，但由于其和`<code>`常常联合使用, 因此放在这里一起叙述.

