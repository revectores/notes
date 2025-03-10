# Vue Basic

Let's demonstrate the most simple Vue web application:

```html
<div id="app">
  {{ message }}
</div>
```

```js
var app = new Vue({
  el: '#app',
  data: {
    message: 'Hello Vue!'
  }
})
```

Here we create a `Vue` object and bind it into an `app` that represented by an `div` element. That is, the content of that `div` will be rendered based on the value of property `message` in JavaScript.




