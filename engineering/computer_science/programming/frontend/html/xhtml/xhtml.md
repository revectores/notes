# XHTML

##### # Historical Background

**可扩展超文本标记语言(Extensible HyperText Markup Language, XHTML)是**一种与HTML语言同样被设计用作数据的格式化(显示)的语言标准.

要了解XHTML首先需要了解可扩展标记语言XML, XML是一种被设计用于**数据传输**的语言, XML的语法非常严格, 一切标签都必须正确关闭, 而HTML则不然, 纵然HTML的功能非常强大, 但其解析是不严格的, 比如某些标签即使没有关闭也不会发生编译错误, 浏览器容许许多语法错误的存在, 导致许多解析能力较弱的终端无法正确地解析这些不严格的HTML文档. 由于HTML和XML常常需要协同工作, 因而HTML的这些随意性对于有效地兼容HTML和XML是不利的.

为此, 新的XHTML标准出现并融合了两种语言的优势. 本质上XHTML是一种为取代HTML存在的更纯净的高级HTML标准, XHTML标准和HTML4.01标准是基本一致的. 

总的来说, XHTML是融合了XML严格性特点的HTML.



##### # How to Upgrade to XHTML

将HTML升级到XHTML非常简单, 只需要两点.

1. 在`<html>`标签中写上`xmlns="https://www.w3.org/1999/xhtml/"`属性, 虽然这个属性是固定的, 但是还是要写.

2. 规范书写HTML代码. 

    具体而言, 一个规范的HTML文档必须:

    - 有`<!DOCTYPE>`声明.
    - 标签必须正确地闭合(不能错误嵌套), 包括空标签, 也就是说要在空标签的起始标签的>前面写上/, 注意这个斜杠/必须和前面的标签体有至少一个空格. 注意到`<!DOCTYPE>`不是元素, 不需要闭合.
    - 标签名称和属性名称对大小写敏感, 必须全部小写. 
    - 属性值必须用引号封装. 
    - 属性值不能简写. 例如`<option selected>`必须写全成`<option selected="selected" />`
    - 统一用`id`属性代替`name`属性. 



##### # `<!DOCTYLE>`

有三种不同的XHTML文档类型(称为三种不同的**DTD**, Document Type Difinition**文档类型定义**), 分别称为Strict(严格类型)、Transitional(过渡类型)和frameset(框架类型). 严格类型包括所有不被反对使用的, 以及不出现在框架结构中的元素和属性; 过渡类型包括严格类型中的一切和被反对的元素和属性; 框架类型包括过渡类型的一切和框架元素. 三者的声明方法分别可以在http://www.w3school.com.cn/xhtml/xhtml_validate.asp查询到.



##### # Why XHTML Failed

前面提到, W3C为了严格化HTML的语法提出了XHTML标准, 然而在Web上的许多网页原先并没有严格编写, XHTML不实现向后兼容势必会造成非常严重的影响, 因此W3C提出了在上一小节提到的三个DTD层次, 以便于过渡原先不符合XHTML标准的网页, 矛盾暂时得到了缓和, 然而在之后提出的XHTML2.0中, W3C试图强制要求所有页面规范化, 不再与原先的HTML兼容, 导致XHTML遭到了新兴浏览器厂商的抛弃, Opera, Mozilla Foundation, Apple联手成立了网页超文本应用技术工作小组(Web HyperText Application Technology Working Group, WHATWG)以推进HTML5标准的建立.
