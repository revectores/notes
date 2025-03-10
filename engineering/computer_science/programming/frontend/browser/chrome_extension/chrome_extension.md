# Chrome Extension

##### # Chrome Extension File Structure

一个chrome必须具备的是`manifest.json`作为入口文件, 该json描述了扩展的基本信息, 其中必须包含的基本信息有

```json
{
    "manifest_version": 2	// 在现有的chrome必须加入
    "name":					// 扩展名称
    "description":			// 扩展描述
    "version":				// 版本号
    						// 以上三项显示在chorme://extensions页面中
    "browser_action": {
        "default_title":	// 鼠标停留在右上角的图标上时显示的浮动文字
        "default_icon":		// 右上角图标地址, 建立采用19*19 png格式
	}
}
```

如果不需要弹窗(点击扩展图标后弹出的小html页面), 可以直接在manifest中加上js代码的入口: 

```js
"background": { "scripts": path }
```

如果需要弹窗, 则要在`browser_action`中加上`default_popup`项, 指定弹出窗口(一般是一个HTML文件)的路径. 注意在加上弹窗之后, `background`的入口将不起作用.

更多的特殊`manifest`项目将在不同的应用中分别阐述.

在根据`manifest`文件的要求设计好文件树之后, 就可以通过`chrome://extensions`页面(注意勾选开发者模式)来进行文件的测试/打包了.



##### # i18n

如果需要为不同地区提供不同语言版本的扩展, 采用国际化技术就很有必要. 国际化的主要手段就是把程序中可能存在的(包括manifest文件中存在的)各个信息字段作为一个**变量**(而不是固定的字符串), 再创建好各个不同的**语言包**, 只需要设定好所需要的语言包就可以将相应的变量值导入程序中. 

具体实现如下: 

在扩展文件夹下创建`_locales`文件夹, 在该文件夹下创建语言包文件夹(注意文件夹名并不能任意选取, 必须是合法的语言代码, 如`en_US, zh_CN`等等, 否则会产生错误), 在每个文件夹下分别创建`messages.json`文件. 

`messages.json`文件的结构在Chrome文档中已经有详细描述, 参阅: 

https://developer.chrome.com/extensions/i18n-messages

之后, 我们在manifest和JavaScript中就可以调用该messages中的内容, 在manifest中的调用方法是`"__MSG_[msgname]__"`, 在js中的调用方法是`chrome.i18n.getMessage("[msgname]", [para1, para2, ...] )`.

注意到在`manifest`文件中是不能传参的, 因此在其中不应使用content包含参数`$x`的`message`.

取得可用语言使用回调函数`chrome.i18n.getAcceptLanguages(function([language_list]))`

该函数是一个回调函数, 所传函数的参数被赋值后是浏览器可接受的语言所构成的数组. 



##### # Chrome Extension API

在开发chrome extensions时, 需要调用一些Chrome提供的API, 这些API写在JavaScript文档中, 调用时就像是一般的JavaScript函数一样. 

Chrome扩展图标在浏览器的右上角显示, 使用`chrome.browserAction.setIcon([path: path])`方法可以重新设定引用路径从而改变图标. 监听单击扩展图标事件`chrome.browserAction.onClicked.addListener(function)`.

向HTML中注入JavaScript代码`chrome.tabs.executeScript( { code:"[jscode]" } )`. 注意在jscode中的引号必须与外侧的引号形式不同(在上面的格式中, 就是只能用单引号), 否则会提前结束代码. 



##### # JS Injection

向页面中注入代码(包括JavaScript, CSS等)是扩展实现其功能的一个重要项目, 因而Chrome提供了许多方式来实现这一功能.

长期注入: `content_script`字段写入. 如果对于某一些站点总是需要注入某些代码, 最好的方式是将其用写入`manifest`文件的`content_script`字段, 其格式如下:

```json
{
    "content_script": [{
        "mmathces": ["url"],	// target injected url
        "css": ["css_file"],
        "js": ["js_file"]
    }]
}
```

编程式注入




