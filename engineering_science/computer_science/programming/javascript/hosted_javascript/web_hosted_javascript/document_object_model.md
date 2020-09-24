# Document Object Model

##### # Concept

<img src="dom_tree.png" alt="dom_tree" style="zoom: 25%; float:right" />DOM被构造为对象的树, HTML中的每一个元素都作为树的一个结点, 除此之外, 每一个元素的内容也作为相应元素的子节点. 当网页被加载时, 浏览器创建文档的DOM, 该模型提供了一系列接口, 便于不同的编程语言对其中的结点元素进行某种操作. 



##### # Node Modification

应用JS可以相应界面事件并且对HTML中的元素内容、属性和样式进行更改. 为了准确进行修改操作, 我们需要确定: 要操作哪个元素对象, 操作元素的什么性质, 执行什么操作行为.

要确定对哪个元素进行操作, 需要获取结点元素对象, 方式包括

1. 通过`getElements?By`系列语句进行获取. 
    - `getElementById`
    - `getElementsByClassName`
    - `getElementsByTagName`
    - `getElementsByName`

其中第一条ById语句直接返回拥有该id的元素对象(因为id的唯一性), 其他几条语句都返回对象数组, 即使匹配对象只有一条也返回单元数组. 

2. 通过`this`获取: 当`this`被写在起始标签之内时, 等效于该标签所标记的元素对象, 例如

    ```html
    <h1 onclick="this.innerHTML = 'Thank you!'">

    <h1 onclick="hackMe(this)">Click to Hack!</h1>
    <script>
        funciton hackMe(id) {
        id.innerHTML = "HACK!!!";
        }
    </script>
    ```
    

由于DOM将节点视为对象, 我们可以使用对JavaScript对象的操作方法访问并修改元素内容、属性、样式, 以及绑定的事件. 访问和修改属性的一般语法为`[node].[attribute]`, 特别地, `style`属性会被自动创建为对象, 因而我们可以通过`[node].style.[property]`访问具体的样式. 访问修改元素事件所绑定的动作`[node].[event_name]`. 该方法的本质是通过元素属性绑定动作的一种变体. JavaScript中一般不采取这个方法来绑定元素事件, 而是直接为元素添加事件监听, 具体方法见[html_event]().



##### # Node Creation and Deletion

我们可以通过`document`对象的`createElement`方法和`createTextNode`方法创建空节点元素以及文本内容. 使用结点的`appendChild`方法可以在该结点元素下添加子结点[^1].

`createElement`的`tag`参数指定了该结点的元素类型, 如p, h1等等(注意必须用引号括起). 注意到创建后的元素是没有内容的. 因而需要创建文本节点后应用`appendChild`方法导入. 整个创建过程的实例如下


```html
<div id="div1">
<p id="p1">a para</p>
<p id="p2">another para</p>
</div>
<script>
var parent1=document.getElementById("div1")
var child=document.createElement("p")
var txt=document.createTextNode("new para")
child.appendChild(txt)
parent1.appendChild(child)
</script>
```

元素的删除通过父元素的`removeChild`方法进行. 而子节点可以通过`parentNode`方法获取其父节点, 因而实际上我们也可以直接通过子节点删除自身: `node.parentNode.removeChild(node)`.









[^1]: 注意添加的子节点应当是合法的, 例如不允许在内联元素中添加块元素作为子节点).

