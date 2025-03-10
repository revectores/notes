# HTML Event

### 1. Event Binding

直接裸露在`<script>`标签内的js代码会在页面加载到这部分时就立即执行. 然而很多时候某些代码要求需要等待页面产生某些事件(通常是用户进行了某些交互操作, 例如鼠标单击、鼠标移动等等, 或者是页面初始化, 需要等待DOM树完全加载完毕)后再执行, 这时候的解决方法就是将这部分代码所代表的动作与事件绑定在一起. 通常为了便于代码维护, 这些与事件绑定的代码块都会被封装到一个函数中. 
在HTML中实现事件绑定有两种主要方式: 

1. 在元素属性中绑定事件. 这种方式将特定事件作为元素的一个属性名, 其属性值设定为相应的动作, 从而实现动作与事件的绑定.
2. 在JavaScript中设定**事件监听(event listening)**. 

以下详述这两种方式的具体语法.



##### # Bind By Attribute

等号左边的属性名是事件名, 在元素属性中书写的事件名一般带有前缀`on`. 并且字母一律小写, 不使用驼峰命名法. 例如单击事件`onclick`, 按下鼠标`onmousedown`, 释放鼠标`onmouseup`等等. 详细的事件列表请参考==TODO: Find Reference.==

使用属性绑定事件时, 其格式服从属性的一般格式, 即属性名(这里是事件名)不需要用引号封装, 而代码块需要用引号封装(特别要注意写在这里面的引号必须用与封装的引号不同的形式). 当代码比较短并且不需要复用时, 可以像这样直接写在属性值里, 但更一般的情况下则是将其封装成一个函数, 从而把函数体下放到`<script>`标签中. 



##### # Event Listening

使用[DOM](document_object_model.md)方法获取节点后, 我们可以通过以下方法为`node`添加事件监听

`[node].addEventListener([event], [callback])`.

**事件对象**会被作为第一个参数传入`callback`中. 但即使回调函数没有定义参数, 在函数中仍然可以通过`event`变量来访问事件对象. 事件对象有许多属性, 其中最重要的是`target`属性, 该属性指明了触发事件的是哪一个结点对象. 





### 2. HTML Event List

##### # Keyboard Event

键盘事件监听键盘的活动状态, 不需要结点对象. 键盘事件包括`keydown/keypress/keyup`, 其中`keydown/keypress`监听键的按下, 而`keyup`监听键的释放. 

键盘事件在游戏中是非常重要的, 假如我们需要持续检测一个键是否被按住(例如表示移动的方向键), 要如何设计代码逻辑呢? 可以这样考虑: 我们建一个flag令其默认值为false, 当触发keydown事件时将其改变为true, 而触发keyup事件时再改回false, 则true就表明该键被按住. 不过在这种设计方案下, 如果要检测的键很多, 并且允许这些键同时按下的话就需要很多的独立boolean值, 因此我们可以考虑建一个空对象, 当任意一个键被按下则在该对象中加入相应的属性, 被释放则将属性删除, 则判定时只需要在对象中查找是否有对应的属性名即可.

```javascript
keys={}
addEventListener("keydown", function(e){
	keys[e.keyCode] = true;
});
addEventListener("keyup", function(e){
	delete keys[e.keyCode];
})

if (37 in keys){
    // ...
}
if (38 in keys){
    // ...
}
```

