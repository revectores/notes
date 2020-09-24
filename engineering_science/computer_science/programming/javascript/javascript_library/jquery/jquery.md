# JQuery

### 1. Basic Concept

##### # You Might NOT Need JQuery[^# You Might NOT Need JQuery]

With the help of modern framework like [Vue](vue), [React](), and [Angular](), and modern browser, you might not need jQuery. Refer the [you_might_not_need_jquery](http://youmightnotneedjquery.com/) document for the further consideration about whether to use jQuery on earth.

This document is constructed in about Feb 2017, hence the content might be outdated. Refer to the [official document](https://api.jquery.com/) for updated details.



##### # What JQuery do

jQuery是一个JS库, 实现了许多可以简化JS代码编写的方法(最重要的, 将原来仅用于CSS的选择器扩展成一个一般的结点获取方法). "write less, do more"是JQ的信条.

使用jQuery库需要添加引用

```html
<script src="jquery.js"></script>
```



##### # Basic Syntax

所有jQuery语句由**选择器(selector)**、**动作(action)**和**参数列表(arguments list)**三部分构成格式`$(selector).action(args)`

其中`$`标志了这是一个jQuery语句, 以区别于原生的JS语句. 选择器的语法规则和CSS中的规则大部分是一致的(也有少数特殊关键字的选择器, 例如`document`和`this`等). 对于使用CSS规则创建的选择器, 必须使用引号加以封装, 否则解析器无法正确执行代码, 例如选择id为p1的元素:

```javascript
$("#p1").hide();
// Hide the element with id `pi`
```

jQuery中动作大致可以分为两类: 一类是对选择器执行的操作, 例如`hide`动作可以隐藏指定的元素; 另一方面它可以是对选择器的**事件监听(event listening)**, 例如click监听, 这时其参数是一个[回调函数](), 在所监听的事件发生时将被执行. 把监听语句和真正的动作语句嵌套在一起, 就构成了一个事件—动作绑定. 

为了确保jQuery不会对尚未加载的元素进行操作或监听, 通常我们将所有的jQuery代码放在一个对文档加载完毕的监听事件中:

```javascript
/* Notice that `document` here is the keyword but css selector,
hence no quotes are required. */
$(document).ready(function(){
	// ...
});
```

这也是一种事件—动作绑定. 



##### # Conflict Avoiding

默认情况下我们使用`$`来标志jQuery代码, 但有时候其他库也会使用这一符号, 为了避免可能出现的冲突, jQuery允许使用`noConflict`方法来创建新的标识符代替`$`这一点, 格式为: 

```javascript
var newTag = jQuery.noConflict()
```

其中`newTag`就是采用的新标识符. 







### 2. JQuery Action

##### # Hide, Show and Toggle

[隐藏、显示和切换]

动作`hide`和`show`实现元素的隐藏和显示. `hide`最后的实质上相当于`display:none`, 也就是说最后将不为元素保留原来所占的空间. `toggle`使得隐藏的元素`show`而显示的元素`hide`. 三者都允许提供`speed`和`callback`两个参数, 分别用于指定显示/隐藏所花**时间**, 以毫秒为单位[^1], 以及执行完毕动作后的回调函数.

```javascript
selector.hide([speed], [callback
```

最简单的用法就是不提供参数:

```javascript
$("#p1").hide();	// hide element with id `p1`.

// hide element `btn1` if it's clicked
$("#btn1").click(function(){$(this).hide();})

// there is no meaning to do this:
$("#btn1").click(function(){$(this).toggle();})
// because you can't click `btn1` to show itanymore if is has been hidden.
```

当然, 实际上也可以通过设定计时器来实现随着隐藏的完成, 同时调用函数的效果, 也就是说这两段代码理论上是等效的:

```javascript
$("#p1").hide(1000, foo);

// equivalent to
$("#p1").hide(1000);
setTimeout("foo()",1000);
```

之所以需要设定计时器, 是因为JQuery代码在执行`hide`的过程中并不会暂停下来, 而是在动作开始执行以后立刻就去执行下一条代码(可以通过设定两个hide的并行来确认这一点), 因此, 设定一个和hide的speed同步的计时器, 就可以实现和回调函数等效的功能.

值得注意的是这里的代码格式细节, 在hide的第二参数中, foo作为回调函数, 只需要写一个函数名, 不需要写括号, 也不需要用引号封装; 而在`setTimeout`中, 作为第一参数的是代码段, 函数只是作为一种常用的特殊代码而存在(而不是严格的回调函数要求), 因而必须使用引号来封装, 而引号内的一切都只需要按照JS的一般语法来写即可(显然JS中正常情况下调用一个函数都是需要在后面加括号的, 否则的话大概会被当作一个孤零零的变量, 并不会执行任何行为)



##### # Fade

`fadeIn/fadeOut/fadeToggle`和`show/hide/toggle`类似, 参数也同样是`speed`和`callback`两项, 最终的结果也是相同的`display:none`. 其区别在于变化过程: 隐藏实际上是**自右下到左上擦除并渐出**, 显示实际上是**自左上到右下擦入并渐入**; 而相应的fade则只是**纯粹的渐入/渐出直到透明度为0/1**. 

在擦入/擦出的过程中, DOM树中的其他标签(如果没有固定住位置的话)会随着擦入/擦除的元素的大小变化而发生移动, 而fade的渐出/渐入则是在渐变的消失或显示的那一瞬间, 所有其他元素位置发生的瞬间移动.

`fadeTo`拓展了`fadeIn`和`fadeOut`, 使得透明度的调整结果不再限于只能是0/1的二元对立, 而是允许在speed后面添加一个**透明度**参数(也就是第二个参数, 从而回调函数将成为第三个参数), 指定对象变化的目标透明度. 



##### # Slide

`slideDown/slideUp/slideToggle`是纯粹地**不带渐变的自左上而右下擦入和自右下而左上擦出**.

请注意, 以上三种变换类型在令参数`speed=0`的情况下(前两种默认`speed=0`)是完全没有区别的, 区别仅仅在慢速变换的情况下才能够看得出来.



##### # CSS Anime: `animate`

使用animate可以使元素的CSS发生渐变, 通过渐变可以实现一些类似于动画的效果:.

```javascript
$(selector).animate({targetCSS}, speed, callback )
```

需要注意这里用大括号括起的目标CSS列表, 和一般的CSS声明格式有如下几点不同: 

1. 各项声明之间必须由逗号分隔, 而正规CSS各项声明由分号分隔;
2. 声明的名称用驼峰命名法, 而不是短线法;
3. 所有声明的值都**必须**用引号括起, 无论值由一个或多个词构成.

举个例子:

```html
<div style="width:100px; height:100px; background:#0000FF; position:absolute;">
<!-- Notice that here we set the position as absolute, for the default value is not moveable and cannot be created an animate -->
</div>

<!-- We use div to bulid a square -->
<script>
$(document).ready(function(){
	$("div").animate({left:'200px', top:'200px'})
});
</script>
```

在这个例子中, 我们用`div`创建了一个正方形, 然后设定好目标CSS, 则这个正方形(的左上角)将移动到坐标为(200, 200)的位置上, 这样我们就创建了一个位移的动画.

类似地, 我们也可以创建大小变化的效果; 不过JQ内建的`animate`并不提供对于颜色渐变的支持, 因此如果希望在`targetCSS`中加上有关背景颜色的项目是无法实现功能的, 需要外部库的支持.







### 3. DOM Operation

jQuery不仅能够实现以上纯粹的样式变更 还可以介入DOM树改造其内容. 我们在本部分介绍jQuery对DOM tree的操作方法.

| Function Description  |              Method              |
| :-------------------: | :------------------------------: |
|  Achieve and Modify   |     `text, html, val, attr`      |
| Incremental Operation | `append, prepend, after, before` |
|  Deletion Operation   |     `remove, detach, empty`      |

其中attr覆盖了一切属性的操作, 而其中有一类属性(class)因常常与CSS联系而比较特殊, 因而JQ提供了对class属性进行操作的便捷方法.

此外, JQ还提供了对CSS和一些尺寸类属性的快捷方式的支持. 

| Type of Adjusted Attribute |                Method                |
| :------------------------: | :----------------------------------: |
|            css             |                `css`                 |
|      class attribute       | `addClass, removeClass, toggleClass` |
|       size attribute       |           `width, height`            |



##### # Achieve and Modify

`text, html, val`三个方法用于内容的访问和修改. `text`仅仅获得元素的文本内容, 即过滤掉内容中所有可能存在的标签, 而`html`则包括标签在内. `val`可以获取像input对象这样可输入对象中的值.

当不传递参数时, 函数的返回值就是相应元素的内容(三个方法对于何谓内容的理解是不同的), 给定参数时, 则将元素的内容设定成传入的参数.

值得注意的是, 参数可以通过回调函数的形式给出, 其中第一个参数是当前元素在选择器所检索出的元素列表中的序号, 第二个则是元素原来的内容(也就是参数置空时, 函数的返回值). 例如

```html
<p>para1</p><p>para2</p><p>para3</p>

<script src="jquery.js"></script>
<script>
    ("p").text(function(i, oldText){return i})
</script>

<!-- result in the website:
	<p>0</p><p>1</p><p>2</p>
-->
```

因此这样一来我们就可以对一类元素进行统一的处理.[^2]

`attr`用于访问和修改元素属性, 访问时给定一个参数指定属性名, 修改时给定两个参数分别为属性名和值. 另外属性修改同样允许使用回调函数.

一次对多个属性进行修改也是允许的, 这时候就需要像这样传一个由“属性名—值”构成的字典参数:

```html
<a id="link1" href="http://www.baidu.com">
<script>
	$("#link1").attr({
		"id": "linkone"
		"href": "http://www.google.com"
	})
</script>
```

注意到由于id也是一个属性, 因而也可以通过`attr`进行修改. 但这段代码的操作并不值得推荐, 通常我们并不应当修改元素的id.



##### # Incremental Operation

内容的增添操作有四个命令: `append, prepend, after, before`. 其中`append`和`prepend`用于在元素内的前部和后部添加内容, 而`after`和`before`则用于在元素的前后添加内容. 实际上上述操作中都可以嵌入标签, 但要注意所嵌入的标签应当是语法上合法的, 例如在内联元素内部嵌入块元素这就很不好. 



##### # Deletion Operation

`empty, remove, detach`用于DOM结点的删除. 我们知道, JQuery语句的格式已经提供了选择器, 不过这三个命令的参数同样是选择器, 这也就意味着以下两种写法实际上是等效的:

```javascript
$("div.div1").empty()
$("div1").empty(".div1")
```

`empty`用于“清空”指定的元素, 即所有的子元素, 而`remove`则删除元素及其子元素. `detach`和`remove`类似, 但区别在于`remove`会一并删除掉元素所绑定的事件、参数, 而`detach`则会保留它们, 因此`detach`常常用于“暂时拒绝访问”.



##### # Shortcut Bypassing `attr`

JQuery提供了对一些常用属性修改操作的快捷写法, 绕过`attr`方法. 例如`addClass, removeClass, toggleClass`方法用于变更类属性, 三者都直接以类名作为参数, 功能就正如它们的名字所提示的那样.

`css`方法用于变更元素的css, 注意到css和属性形式的高度一致性, 因此其实语法上对于元素CSS属性的访问和修改和attr的语法是一样的: 也就是访问时使用一个参数(属性名), 修改时使用两个参数(属性名+目标值或回调函数), 同时对多个属性进行修改则同样需要传一个object进去.

除了class和css以外, 一些尺寸属性也被认为是特殊的, 例如`height, width, innerHeight, innerWidth`等等, 这些属性同样也可以通过(作为动作)直接访问得到, 具体支持的尺寸动作请自行参照文档.



##### # Iteration

我们知道DOM树中的元素之间有各种各样的关系, JQuery提供了丰富的方法, 从一个元素出发, 可以对其父元素、子元素和亲兄弟元素(具备同一个父元素的元素)进行遍历

|     Iteration Operation     |                    Method                    |
| :-------------------------: | :------------------------------------------: |
|      Upwards Iteration      |       `parent, parents, parentsUntil`        |
|     Downwards Iteration     |               `children, find`               |
| Iteration in The Same Level | `siblings, next[All/Until], prev[All/Until]` |









[^1]: 并不是真正意义上的"speed".

[^2]: 当然, 这实际上也可以结合数组通过JavaScript原生的for循环来实现.
[^# You Might NOT Need JQuery]: http://youmightnotneedjquery.com/




