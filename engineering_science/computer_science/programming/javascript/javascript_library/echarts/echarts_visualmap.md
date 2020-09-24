# Echarts VisualMap

`visualMap`用于将数据映射到视觉通道.

 `visualMap`组件分为分段型`piecewise`和连续型`continuous`, 通过`type`属性规定

```javascript
let option = {
    visualMap: [
        {
            type: 'continuous',
        },
        {
            type: 'piecewise',
        }
    ]
};
```



`dimension`属性规定用数据的哪个维度映射到视觉元素上, 默认使用最后一个维度. `inRange`和`outOfRange`属性规定这个维度的数据映射到哪些视觉元素上.

`min, max`属性规定了组件允许的最小值和最大值. `min, max`必须手动设置, 默认值为`[0, 100]`, 并不会自动适配`series.data`中的最值.





`inRange`属性定义在`[min, max]`范围内的视觉元素. 可选的视觉元素包括

- `symbol`: 图元的图形类别.
- `symbolSize`: 图元的大小.
- `color`: 图元的颜色.
- `colorAlpha`: 图元颜色透明度.
- `opacity`: 图元及其附属物(如文字标签`label`)的透明度.

- `...`

我们可以同时定义多个视觉通道, 这些视觉通道会被同时采用. `opacity`和`colorAlpha`类似, 但我们建议使用`opacity`, 它能够同时控制图元中的附属物的透明度.



当`visualMap`的类型为`continuous`, 或为`piecewise`但没有设置`categories`时映射方式将被设定为线性映射.

线性映射表示`series.data`中的每一个值都会从`[min, max]`映射到设定的`[visual_value_1, visual_value_2]`. 例如

```javascript
let option = {
	visualMap: {
        min: 0,
        max: 100,
        inRange: [
            opacity: [0.4, 1]
        ]
    }    
}
```

此时我们会对`series.data`中的每一个元素进行线性映射计算得到`opacityValue`, 例如当`series.data = [50, 10, 100]`时我们得到的`opacityValues = [0.7, 0.44, 1]`.









