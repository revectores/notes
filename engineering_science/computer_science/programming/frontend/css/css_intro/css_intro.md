#  CSS Basic

### 1. Basic Concept

##### # Definition

**Cascading Style Sheet(CSS)** define the displaying style of HTML elements. The introduction of CSS seperates sesemantics and style.

HTML的样式定义可以在四个位置进行, 自上而下优先级递增:

1. 浏览器默认定义.
2. 外部`<link>`样式表.
3. 内部样式表`<style>`.
4. 位于元素内部的内联样式.

`<link>`标签和`<style>`均位于`<head>`内, 定义格式为: 

```html
<link type="text/css" rel="stylesheet" herf=css_href />
<style type="text/css">

</style>
```



### 2. Core Syntax

##### # Format

一条CSS语句由**选择器**(selector)和一条或多条**声明**(declaration)构成. 选择器从页面中筛选出需要应用CSS的部分, 规定了期望改变样式的HTML元素有哪些, 筛选可以采取许多方式. 声明是由属性名及其值构成的键值对.

```css
selector {
	property1: "value";
    property2: "value with space";
}
```

当`value`不含空格时可以不用引号封装, 但通常建议所有`value`均用引号封装, 不论是否包括空格.

在元素内部利用`style`属性设定样式时, 就不存在选择器了, 直接将上面格式中的大括号换成双引号(服从元素属性的一般格式), 在引号内写各个声明即可(声明之间仍然需要用**分号**分隔, `value`则用单引号括起), 由于是作为元素属性存在, 因此应当尽量写在一行内: 

```html
<tag style="property1: 'value'; property2: 'value with space'"></tag>
```



##### # Hierarchy

一般而言在现代浏览器中, 子元素将继承父元素的样式, 但对于某些老旧的浏览器而言有可能无法理解继承(如Netscape4), 这时只能利用选择器分组技术, 显式声明可能出现的子元素的样式. 

如果不愿意某个子元素类型继承父元素的样式, 只需要将其单独再声明一次样式即可. 



### 3. Selector

##### # Basic Selector

最简单的选择器就是直接写出元素名称例如`p, h1, h2`, 可以写多个并且用逗号分隔, 这称为选择器分组.



##### # Contextual Selector

**上下文选择器(contextual selector)**包括**后代选择器**、**子元素选择器**和**相邻兄弟选择器**三种技术. 

后代选择器语法格式为`n1 n2`, 两个元素之间由空格分隔, 选择存在于`n1`中的所有`n2`, 无论其中经过了多少层继承. 

子元素选择器格式为`n1 > n2`, 选择拥有直接父元素`n1`的`n2`, 与后代选择器不同, 两个元素之间只允许经过一层继承. 

相邻兄弟选择器格式为`n1 + n2`, 选择紧跟在`n1`之后的`n2`, 并且二者必须具有相同的父元素. 

注意到以上派生选择器都只选择`n2`, 只对`n2`进行处理, `n1`仅仅只是作为一个筛选工具而存在.



##### # Id Selector

语法为`#id`, 根据id选择元素, 注意到在一个HTML文档中`id`是唯一的, 因此该选择器也只作用在唯一的元素.

id选择器常常可以和派生选择器结合起作用, 例如: `#someid p`选择存在于id为`someid`的元素内的段落.



##### # Class Selector

语法为`.class`, 类选择器用句点`.`标志, 用于选择拥有特定`class`属性的元素, 在一个文档中`class`不唯一, 允许多个元素属于同一个class, 这也就是class和id的不同之处. 



##### # Attribute Selector

语法为`[attribute = value]`, 用于选择具有特定属性值的元素. 注意到即使HTML文档中的属性值需要用引号括起, 但在属性选择器的语法中并不需要(可能是由于已经使用中括号予以了封装). 式中`=value`可以去掉, 用于选择具备特定属性的元素, 而不论其值如何. 

本质上id选择器和类选择器也是一种属性选择器, 因为`id`和`class`都可以视为是元素的某种没有直接效果的属性. 如果某些元素的共同特征已经在属性中表现出来, 就没有必要再为其设定`class`.

属性选择器允许应用一些正则技术.

以上所有选择器技术都可以组合使用. 





### 4. Styles

##### # Background Style

背景色`background-color`和背景图像`background-image`. 与HTML中的`bgcolor`和背景图像`background`属性不同的是, CSS中的这两个属性可以应用于任何标签, 且不可继承, 但`background-color`的默认值为`transparent`(透明的), 实际上表现为显示父元素的颜色. 

如果需要改变背景图像平铺的方式, 可以使用`background-repeat`属性

| background-repeat value | description            |
| ----------------------- | ---------------------- |
| `repeat`[default]       | 允许x方向和y方向的平铺 |
| `no-repeat`             | 不允许任何方向平铺     |
| `repeat-y`              | 仅允许y方向上的平铺    |
| `repeat-x`              | 仅允许x方向上的平铺    |



##### # Border Style

**边框(border)**是绝大多数HTML元素都可以应用的样式之一, 边框的属性有三种: `style, width, color`, 其中`style`表示边框的样式, 最常用的是`solid`(实线), 对于不同的HTML元素有不同的`style`默认值. 剩下两个属性很好理解, 就不再赘述了. 

在CSS中进行设置时, 可以像这样把三个属性分开分别设置:

```css
.SomeClass {
	border-style: solid;
	border-width: 5px;
	border-color: #0000FF;
}
```

也可以将三者合并到`border`中一起写: 

```css
.SomeClass {
	border: solid 5px 0000FF;
}
```

合并书写时, 顺序并不重要, CSS解析器会自动解析每个字段的含义; 也并不一定要把三个属性都写满, 只写一个或两个也是可以的. 

如果不需要显示边框, 将`border-style`设定成`none`即可, 当然, 由于可以合并书写的缘故, 你也可以直接将border设定成none(但要记得内部过程是转化为了border-style); 另外, `border-width=0`虽然也可以起到同样的效果, 但是这样做会浪费浏览器解析style和color的资源, 因此我们不建议这种设定方式. 

`border`样式统一设置元素的所有边框. 我们也可以独立设置每一个边框样式.

- `border-top`
- `border-bottom`
- `border-left`
- `border-right`

其中每一类`border`均可以进一步拆分为`style, width, color`三项属性. 例如单独设施上框线

```css
.SomeClass {
	border-top-style: solid;
	border-top-width: 3px;
}
/* equivalent to */
.SomeClass {
	border-top: solid 3px;
}
```


