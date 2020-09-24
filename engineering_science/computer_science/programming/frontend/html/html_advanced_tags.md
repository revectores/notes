# HTML Advanced Tags

这份文档中我们将介绍HTML中的一些不那么常用的标签. 



##### # `<marquee>`

`<marquee>`标签并不是W3C标准中的规范. 通过direction属性可以设置其滚动的方向, 默认情况下自右向左.

`scrolldelay`和`scrollamount`是两个共同决定滚动速度的属性, `scrolldelay`指定单位时间(以毫秒为单位), 而`scrollamount`指定在单位时间内移动的像素, 其默认值分别为`85(ms), 6(px)`. 因此减小`delay`和增加`amount`都可以加速滚动. 

根据以上两个参数我们很容易计算一个像素点从一端移动到另一端所需的时间. 例如当`width = 960px`, 则默认滚动一次的时间为960/6*0.085=13.6s.

`marquee`最常用的两个方法是`stop/start`, 分别用于停止滚动和开始滚动. 常规的设计是将`stop`和`onmouseon`绑定在一起, `start`和`onmouseout`绑定在一起, 使得用于能够在鼠标悬停的状态下仔细阅读静态的文字.



##### # `<select>`

`<select>`标签用于创建单选或多选菜单, 其中的每一项由一对`<option>`标签标志: 

```html
<select>
	<option>Apple</option>
    <option>Banana</option>
	<option>Orange</option>
</select>
```

<select>
	<option>Apple</option>
    <option>Banana</option>
	<option>Orange</option>
</select>

如果希望设定多选, 则可以添加multiple属性, 该属性没有属性值. 当设定了这一属性以后, 就可以通过按住Ctrl的方式来选择多个option.

```html
<select multiple>
	<option>Apple</option>
    <option>Banana</option>
	<option>Orange</option>
</select>
```

<select multiple>
	<option>Apple</option>
    <option>Banana</option>
	<option>Orange</option>
</select>

【size问题】

`<select>`标签的`size`样式是一个很混乱的局面, 对于单选而言, 默认情况下的样式是**下拉列表**, 这一样式的好处在于页面的简洁, 但无法直观地一眼看到所有选项; 对于多选而言, 默认情况下的样式则是**定长框**(默认情况下定长框的长度, 理论上是由浏览器来决定, 本地实验表明chrome,Firefox和IE11下无论项数有多少默认定长框长度均为4). 如果我们将size属性设定为0, 则就代表服从默认情况.


如果我们令`size=1`, 对于单选框而言, 和`size=0`没有区别, 仍然是下拉列表, 但对于多选框而言(因为多选框是不可能通过下拉列表形式呈现的), 则是只显示一个项的定长框. 

当我们令`size`为其他正数时, 则单选框和多选框的样式都会变成相应长度的定长框. 

综上我们可以得出的结论是: 如果样式是下拉列表, 它一定是单选框; 如果样式是定长框, 它可能是单选框或复选框, 但如果定长框的长度是`1`, 则它一定是复选框. 

另外值得注意的一点是, 通过原生HTML是不可能规定下拉列表的长度的, 本地实验表明Chrome, Firefox都在下拉列表长度<=20时显示整个列表, 而>20时通过滚动条解决问题. 对于IE而言这个数值是30(而且IE对于下拉列表的显示样式非常奇怪, 不再详述, 有兴趣自己做实验).

以上就是对于奇特的`size`属性的讨论(以上讨论建立在尚未设定`select`的`style-height`的条件下, 实验表明似乎一旦设定了`height`则`size`会自动被屏蔽掉……总之情况会变得非常复杂, 请尽量不要同时设置`size`和`height`)

【宽高设定】

`<select>`的宽在默认情况下是由选项中最长的一项来决定的. 由于`select`是坚决不提供水平滚动条的, 这一方式非常自然, 否则会导致后面的内容被截断, 不过你也可以强行设定定宽, 但`select`不提供`width`, 需要通过设置样式的方式进行.

`select`同样不提供`height`, 必须通过style设置, 不过我们不建议直接调整`height`, 如果不是有严格像素要求的话请尽量通过`size`来控制.

【select对象的属性、事件和方法】

很多时候`select`中的选项需要即时地和页面上的项目发生联系, 最常见的是和另外的`select`发生联系. 举个例子, 我们有两个`select`, A是国家的选择项, 而B是地区的选择项, 我们需要根据A的变化而动态地改变B中的项目, 这时候就需要对`select`对象本身的特点进行考察. 

获取当前`select`所选择项的`index`的属性是`selectedIndex`. 举个例子: 

```html
<select id="select-1">
	<option>op1</option>
	<option selected>op2</option>
	<option>op3</option>
</select>
<script>
	var sel1 = document.getElementById("select-1")
	console.log(sel1.selectedIndex)		// 1
</script>
```

`select`最常见的是`onchange`事件, 当所选择的`option`发生改变时触发. 


