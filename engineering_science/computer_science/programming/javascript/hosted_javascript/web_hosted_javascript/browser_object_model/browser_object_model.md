# Browser Object Model

**浏览器对象模型(Browser Object Model, BOM)**提供了一系列与浏览器(甚至客户端)有关的API供JavaScript使用.x



##### # `window` Object

window对象表示浏览器的窗口. 在浏览器环境中中window对象是顶层对象, 所有的JS全局对象、函数和变量都是它的成员. 全局函数是window对象的方法、而全局变量则是window对象的属性.

```javascript
>>> var a = 1;
>>> window.a;
1
>>> window.a = a;
>>> a;
2
```

事实上甚至[DOM](document_object_model.md)的根节点`document`同样也是`window`对象的属性.

当然实践中我们一般不把window对象显式写出来, window对象主要显式用于一些和窗口直接相关的属性和事件.

`window.innerHeight`表示浏览器窗口的内部[^1]高度, `window.innerWidth`表示浏览器窗口的内部宽度.

`window.close`方法用于关闭当前窗口, 这个方法没有参数, 而`window.open`方法用于打开一个新窗口, 以新窗口的URL作为参数. 另外还有移动窗口的`moveTo`方法和调整窗口尺寸的`resizeTo`方法.

`window` 下属许多子对象包含了与当前窗口相关的各种信息:

- `document`对象作为DOM树的根节点.
- `screen`对象可以获得用户屏幕有关的信息. 

- `location`对象可以获得当前URL的有关信息(域名、路径、端口、协议等等包含在URL中的内容)

- `history`对象有两个back和forward两个方法, 分别等效于浏览器中的后退和前进按钮.

- `navigator`对象用于获取和浏览器/客户端有关的信息.





[^1]: 这里的"内部"指的是除开浏览器标签栏、地址栏和收藏夹栏等等部分, 真正显示页面的有效部分, 也就是说如果要让这两个值都达到屏幕的分辨率, 则需要F12将浏览器窗口全屏.

