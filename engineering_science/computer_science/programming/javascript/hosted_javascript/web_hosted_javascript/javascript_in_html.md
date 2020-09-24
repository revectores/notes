# JavaScript in HTML

HTML中的内嵌JS代码由标签对`<script></scrpit>`括起, 旧时代由于同时存在许多不同的浏览器脚本语言, 需要在`script`标签中通过属性`type="text/javascrpit"`来注明语言类型, 但随着JavaScript成为现代浏览器的默认脚本语言, 这个属性声明已经不再需要了.

我们通常将JavaScript代码集中写在文件的某个位置, 例如`<head>`中或`<body>`末尾, 应用后者可以确保在页面中所有元素(其中很可能包括JS需要调用或需要对JS作出相应的元素)都加载完毕后再载入JS, 以防止可能的错误. (当然实际上这一点也可以通过监听document的DOMContentLoaded事件实现).

也可以通过在`<script>`标签对中添加`src`属性来指定应用的外部JS文件地址或URL.

JavaScript在HTML环境中提供了某些函数. 例如`alert(message)`在浏览器上弹出一个窗口以显示信息, `console.log(message)`用于在控制台console上显示调试信息. `document.write(html_string)`用于向页面写入HTML. 注意到如果在页面加载完毕后执行该语句, 则其将会覆盖整个页面的内容. 特别地, 我们甚至可以使用`document.write` 函数向页面内写入JS代码.

