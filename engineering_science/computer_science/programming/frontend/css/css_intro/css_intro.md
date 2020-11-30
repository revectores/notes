#  CSS Basic

### 1. CSS Basic Concept

##### # CSS Definition

**Cascading Style Sheet(CSS)** define the displaying style of HTML elements. The introduction of CSS seperates sesemantics and style.

You can define the style of HTML elements in four places with CSS:

1. Inline style inside elements properties.

2. Internal stylesheet `<style>`, defined inside `<head>`:

    ```html
    <style type="text/css"></style>
    ```

3. External stylesheet included by `<link>`, defined inside `<head>`:

    ```html
    <link type="text/css" rel="stylesheet" herf=css_href />
    ```

The priority decreases from top to down. Additionally, the default style defined by the browser has the lowest priority.



##### # CSS Statement Format

A CSS statement constructed by a **selector** and multiple key-values pairs, called **declarations**. The selector filter those elements that apply declarations.

```css
selector {
	property1: "value";
    property2: "value with space";
}
```

All the values shall be surrounded by quotes, although the quotes can be omitted if no space inside value.

When we use inline style by applying `style` property, there is no need to set the selector. The inline style looks like

```html
<tag style="property1: 'value'; property2: 'value with space'"></tag>
```



##### # CSS Hierarchy

The child elements will automatically inherit styles from their parent. Create a new statement in the child element again to override the inheritance.







### 2. CSS Selector

##### # Basic Selector

The simplist selectors are the element type, such as `p`, `h1`.



##### # Grouping Selector

The comma-separated selector list selects the union of each selector. For example, `h1, h2, h3, h4, h5, h6` select all levels of title.



##### # CSS Combinator

The **combinator** or **contextual selector** selects elements not only based on themselves but the context. There are four types of combinator in CSS.

- **Descendant selector** `e1 e2`, selects all the `e2` inside `e1`, no matter how many inheritance between them.
- **Child selector** `e1 > e2`, selects all the `e2` as the direct child of `e1`.
- **General Sibling Selector** `e1 ~ e2`, selects all the `e2` as the sibling of `e1`, that is, with the same parent element but after `e1`.
- **Adjacent Sibling Selector** `e1 + e2`, selects all the `e2` as the direct sibling of `e1`.

Note that in all the combinators only `e2` get selected, while `h1` is the context.



##### # Attribute Selector

The **id selector** `#id` selects element with specific id.

The **class selector** `.class` selects elements with specific class.

Generally, **attribute selector** `[name = value]` selects the attribute with given property name/value pair. Note that there is no need to quote the property value in attribute selector. If `=value` is omitted, the selector selects all the elements with that property regardless the values. Some regular expression can be applied to attribute selector.



##### # Combination of Selectors

All the selectors can be combined. For example, the selector

```css
#h1.title > h3.subtitle
```

will select all the `h3` with class `subtitle` as the direct child of `h1` with class `title`.







### 3. CSS Styles

##### # CSS Background Style

<u>Introduce properties about background, includes  `background-color `, `background-image` and `background-repeat`.</u> 

The `background-color` and `background-image` property, as named, sets the background color and image respectively. These two properties can be applied to any elements ==CITATION NEEDED==. The corresponding deperated HTML properties are `bgcolor` and `background`. 

The `background-color` and `background-image` are not inherited. When we set the color of parent element, it seems that it is inherited by the children since the the default value of `background-color` is transparent hence the color from parent element are shown.

Use `background-repeat` property to change the way image tiles. The default value is `repeat`.

| `background-repeat` value | Description                               |
| :-----------------------: | ----------------------------------------- |
|         `repeat`          | Repeated both vertically and horizontally |
|        `no-repeat`        | No repeat                                 |
|        `repeat-y`         | Repeated vertically only                  |
|        `repeat-x`         | Repeated horizontally only                |



##### # CSS Border Style

**Border** can be applied to most of the HTML elements. Border includes three properties: 

- `border-style`
- `border-width`
- `border-color`

You can set the three properties respectively

```css
{
	border-style: solid;
	border-width: 5px;
	border-color: #0000FF;
}
```

or join them as a single `border` property:

```css
{
	border: solid 5px 0000FF;
}
```

Since the three properties are with different forms, the CSS analyser will interpret based on form. Hence the order is arbitrary.

If you want to hide the border, set `border-style: none`. The `border-width: 0` will look the same but may waste computation resource of browser.

A element has borders in four direction:

- `border-top`
- `border-bottom`
- `border-left`
- `border-right`

We can set them respectively and each can also be divided into `style`, `width` and `color` properties.

```css
{
	border-top-style: solid;
	border-top-width: 3px;
}
/* equivalent to */
{
	border-top: solid 3px;
}
```


