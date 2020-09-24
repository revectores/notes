# HTML Style Attribute







### 3. General Style Attribute



##### # Background

`bgcolor`和`background`

可以设定背景的标签有`<body>`和`<table>`的任意子标签(除`<caption>`).

`bgcolor`属性指定了某个元素的背景色, background属性指定元素背景图像的URL.

`bgcolor`属性的值可以是颜色的十六进制值、RGB值或颜色名. 例如如果要将背景色设定为黑色, 可以使用以下三种等效的表达方式: 

- `<body bgcolor="#000000">`

- `<body bgcolor="rgb(0,0,0)">`

- `<body bgcolor="black">`

对于`background`, 如果所给的图像小于页面, 则默认情况下图像将重复平铺.



##### # Alignment

对齐方式`align`, 宽度`width`, 高度`height`一般而言当标签存在对这几个属性的需要时, 都可以应用.



##### # Inline Style

粗体字标签`<b>`, 斜体字标签`<i>`, 更大的字号`<big>`, 更小的字号`<small>`, 下标`<sub>`, 上标`<sup>`



### 4. Tag Specific Style

##### # Style for Table Tag

`<table>`的`border`和`img`的`border`属性一样, 表示表格最外层边框`frame`的厚度, 以像素为单位. 默认情况下`border=0`, 此时的表格无论内外层都是没有边框的. 

`frame`属性指定了最外层边框的模式, 其属性值包括

| `frame` value |  rendering effect  |
| :-----------: | :----------------: |
|      box      | frame in all sides |
|     above     |    above frame     |
|     below     |    below frame     |
|    hsides     |  horizontal frame  |
|    vsides     |   vertical frame   |

`cepadding`属性和`cellspacing`属性分别指定了单元格内容到其边框的距离和不同单元格之间的距离.

`<table>`及其子标签(除`<caption>`)都可以应用通用的`bgcolor`属性和`background`属性来指定其背景色或背景图案URL. 注意在`<table>`中设定它们时不会影响到`<caption>`的背景, 尽管`<caption>`是`<table>`的子标签. 

此外, `<table>`及其子标签(除`<caption>`)都可以应用`align`属性和`width`属性.



##### # Style for List

`<ul>`的`type`属性可以定义项前面的标志图形, 默认状态是小圆点`type="disc"`. `<ol>`的`type`属性可以定义项前面的有序排列, 默认状态是`type="1"`, 排列是`1, 2, 3...`





