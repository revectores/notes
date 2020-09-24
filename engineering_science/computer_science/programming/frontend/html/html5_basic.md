# HTML5 Basic

> **Ability Stack**
>
> 本文档的核心目的在于介绍HTML5的新特性使用方法, 包括音频视频流、Canvas和SVG三个部分.
>
> 具体而言, 本文档的完整阅读者将具备以下能力: 
>
> 1. 理解video, audio标签的使用方法.
> 2. 理解使用JS对canvas进行的简单操作(这部分以后可能会独立成一个文档).
> 3. 理解SVG的概念.
>
> 充分理解本文档内容的读者应当能够独立完成后面的第一部分练习题, 而第二部分的练习题则和其他文档的内容有关, 或者需要查找相应的参考资料才能够完成.

众所周知, HTML5是WAHTWG为拒绝W3C提出的[XHTML](xhtml.md)所作出的努力, 经过艰苦卓绝的斗争, W3C终于在2014.10.29正式公布了HTML5标准. 现在我们就来考察HTML5的新特性.



### 1. Semantic HTML Tag

`<article>, <aside>, <details>, <figcaption>, <figure>, <footer>, <header>`

`<main>, <mark>, <nav>, <section>, <summary>, <time>`









### 2. Video Audio Stream

在HTML5以前, 并没有关于音频/视频在网页上的显示标准, 大多数音频和视频是通过Flash这样的插件的支持来显示的, 然而并不是所有的浏览器都具备同样的插件. H5则解决了这个问题, 使得在网页中插入音视频变得非常容易. (如果你仔细观察的话, 会发现很多网站都已经采用了H5 video, 尤其是H网, 以及B站, 但除此之外的国内各大视频网站出于广告和防盗链这两方面的考虑仍然在坚守Flash阵地, 下面我们将会看到对于H5 video来说通过审查元素得到视频源是非常方便的)

H5支持三种视频格式: `ogg, mp4, WebM`. 以及三种音频格式音频格式: `ogg, mp3和wav`.令人尴尬的是不同浏览器似乎对它们有不同的支持程度(W3C上的表格大概已经是老版本的了, 这里不对具体版本的支持状态作详细讨论). 

插入视频只需要使用`<video>`标签, 并且用`src`标志视频源即可, 非常简单快捷. 毫无疑问视频可以通过`width`和`height`来调整播放器的大小, 值得注意的是, 和`img`的这两个属性不同, 视频本身的比例是不会发生改变的, 如果宽高比与视频源的比例不同, 则多出的部分会被留白. 

默认情况下视频是没有控制栏(显示播放, 暂停等按钮)的, 设定`controls="controls"`属性值可以在视频下方显示控制栏. 

如果设定了内容, 则`video`元素的内容会被作为不支持video元素的浏览器的备用提示. 

我们在上面提到, 不同的浏览器对H5三种格式的支持有所不同, 那么要如何实现对多种浏览器的兼容呢? H5在设计时已经考虑到了这一点, 通过将src属性变成`<video>`的子标签`<source>`的方式来实现一个video元素对应多个不同格式的视频源: 

```html
<video controls="controls">
    <source src="movie.ogg" type="video/ogg">
    <source src="movie.mp4" type="video/mp4">
    Your browser does not support the video tag.
</video>
```

我们看到, 通过src属性指定了每一个source的源地址, 并且同过type属性声明了它的视频格式, 当浏览器渲染到这里时, 会按照顺序搜索可用的视频源地址, 只要找到了某一个源可用那么就不会再看后面的source.

`<audio>`标签用于播放音频, 它的各种属性设定和`<vedio>`是完全类似的.





### 3. Canvas

`<canvas>`标签在HTML上放上了一个画布. 我们可以通过JavaScript在这个画布上进行作图.



##### # Canvas Demo 

直接上一段基础示例代码:

```html
<canvas id="test1" width="500" height="500" style="border:1px solid #c3c3c3">
	Your browser doesn't support canvas!
</canvas>
<script>
function myFirstDraw(){
	var canvas1 = document.getElementById("test1");
	var ctx = canvas1.getContext("2d");
	ctx.fillRect(100, 100, 50, 50);
	ctx.moveTo(200, 200);
	ctx.lineTo(300, 300);
	ctx.stroke();
}
myFirstDraw()
</script>
```

首先, canvas可以设定width和height, 其默认值是300x150. 值得注意的是canvas的宽高设置和其他元素不同, 其他元素的宽高通过属性进行设定和通过样式进行设定是完全等效的, 对于canvas来说, 通过属性进行设定(像上面那样)真正将画布的大小扩大了, 绘图时在新的等距坐标系中进行, 但是通过样式进行设定(style属性或独立到CSS中)在绘图时会先在原先的300x150比例中进行绘制, 然后再将绘制成的图形放大成500x500, 这显然不是我们所需要的效果, 因此canvas的宽高应当直接通过属性进行设定. 

那么如果有多个canvas希望统一进行处理要怎么做呢? 这时候通过JS对元素属性进行操作即可. 

默认情况下canvas是不显示边框的, 这里通过设定style的方式添加上了一个边框(这里为了代码简洁性直接把CSS写在属性里了, 可以独立出来写到CSS当中). 

`<canvas>`的元素内容同样作为用户浏览器不支持该元素时的提示文字. 

接下来看绘图逻辑. 首先我们先获得canvas1对象, 然后通过canvas类的getContext方法来获得一个“2D画笔”ctx, 接下来就可以利用这个画笔进行操作了. 在上面的代码中体现了两种操作: 一是使用fillRect方法绘制一个实心矩形, 其中的四个参数分别表示矩形左上角顶点的横纵坐标, 以及矩形的横纵边长. 二是使用moveTo和lineTo(注意区分大小写)命令来绘制线段, 这非常好理解, 但要注意在一系列以上moveTo和lineTo命令的组合以后必须使用stroke()方法才能够最终将路径绘制出来. 



##### # Line

【从stroke到beginPath】

线条是最基本的绘图元素了. 在上面的示例代码中我们已经给出了画线条的moveTo和lineTo方法, 以及最后“成图”的stroke()方法. 

既然代码是按照顺序被解释执行的, 那么这里的stroke()究竟意义何在? 事实上它只有和beginPath()结合起来理解才有具体意义. 所谓的beginPath用于“重新开始一条路径”, 为了清楚地说明这个概念, 请看下面的示例代码: 

```javascript
ctx.beginPath();	// You can delete this line, the result will be the same.
ctx.moveTo(100, 100);
ctx.lineTo(200, 200);
ctx.stroke();
ctx.lineWidth = 10;
// Notice here we reset the lineWidth,the default value is 1.
ctx.moveTo(300, 300);
ctx.lineTo(400, 400);
ctx.stroke();
```

我们设想中这段代码应当先以1px的笔触画出一条斜线, 再以10px的笔触画出一条斜线, 但是实际执行中我们发现两条斜线都是10px的, 这是为什么呢? 

这是由于stroke()会以自身到上一个beginPath()作为自己的考虑空间, 并且首先应用其中的样式(如果样式有冲突则应用最后一个), 然后再去执行绘图代码. 那么在上面的代码中, 第一个stroke的考虑空间只有两行代码, 它画出了一条1px的线, 而第二个stroke则首先搜索到了指定lineWidth的样式命令, 先应用它, 然后再画出两条10px的线, 由于比较粗, 就把前面的1px的线给覆盖了. 

因此, 如果要实现预想中的目的, 就必须在第一个stroke后面添加上beginPath语句, 从而启动一条新的路径. 

如何证明在上面的代码中前者是真的被覆盖了(而不是前一个stroke被禁止执行了呢)? 在介绍完线条属性之后我们就可以设计出合适的证明代码. 

【线条属性】

上面我们介绍了ctx的lineWidth属性, 用于调整线条的笔宽, 其默认值是1(px).

strokeStyle属性用于设定线条的颜色、透明度等样式: 

```javascript
ctx.strokeStyle = "#0000FF"  // Same as "blue" or 'rgb(0,0,255)'
// You can also use 'rgba' to set color and transparency at the same time:
ctx.strokeStyle = 'rgba(0,0,255,0.5)'
// Remember to use the ' besides the property value.
```

【证明代码】

我们可以通过更改线条颜色的方式来写证明代码, 将上面的内容添加两行代码如下(用红色表示新增加的部分): 

```javascript
ctx.beginPath();
ctx.strokeStyle = "FF0000";
ctx.moveTo(100,100);
ctx.lineTo(200,200);
ctx.stroke();
ctx.strokeStyle = "0000FF";
ctx.moveTo(300,300);
ctx.lineTo(400,400);
ctx.stroke();
```

运行发现, 第一条线变成了紫色, 这正是红色和蓝色重叠的结果, 说明了第一条线被绘制了两次. 



##### # Draw Image

在canvas中导入图片的思路是: 先创建图片对象并指定其src, 接着用画笔的drawImage方法来把这个对象画到canvas里. 示例代码如下: 

```javascript
ctx = canvas1.getContext('2d');
var img = new Image();
img.src = "demo.jpg";
ctx.drawImage(img,0,0);
```

其中drawImage方法的后两个参数指定了图像左上角位置的坐标. 

值得注意的是, 由于img的导入往往需要时间, 因此仅仅采用上述语法很容易使得img在尚未导入时就已经被drawImage调用了, 从而导致绘制的失败. 因此我们应当确认了img已经导入完成以后再调用它, 实现这一点需要利用img对象的onload方法: 

```javascript
img.onload = function(){
	ctx.drawImage(img,0,0);
}
// Do not all drawImage until img is perpared.
```

上述语法在img导入完成以后立刻调用drawImage方法, 如果不愿意被绑定起来可以添加一个flag, 以后在需要调用时再另行判定: 

```javascript
var imgReady = false;
img.onload = function(){
	imgReady = true;
}
// ...
if (imgReady) ctx.drawImage(img,0,0);
```







### 4. Scalable Vector Graphics

所谓的SVG指可伸缩矢量图形(Scalable Vector Graphics), HTML5支持通过<svg>标签直接在页面内加入SVG图像, SVG结构本质上是XML, 因此可以很容易地通过操作DOM树的方式来通过JS控制SVG.

canvas和SVG都是在H5的新增图形管理元素, 其中前者是位图而后者是矢量图; 除此之外二者的关键区别在于SVG的XML本质决定了其中任何一个元素均被视为DOM树对象, 可以很容易地对元素进行操作, 但是对于canvas来说, 一个图线一旦被绘制出来浏览器就不会再关注它, 也无法对其进行操作, 因此如果要“移动”这个图线就必须重新绘制整个场景. 但SVG的这个特性也导致了其渲染速度很慢(任何过度使用DOM的应用都不快), 因此不适合游戏应用. 
