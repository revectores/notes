# Serialization and Deserialization

### 1. Serialization: JSON.Stringify() Function

Refer [document of JSON.stringify()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/JSON/stringify) for details about serialization.



##### # Basic Usage

`JSON.stringify()` method serializes JavaScript object into JSON string:

```javascript
let obj = {
    data: {
        name: "robert",
        age: 20,
    },
    msg: "success",
    code: 200,
};
console.log(JSON.stringify(obj));
// {"data":{"name":"robert","age":20},"msg":"success","code":200}
// Here we use console.log as the wrapper to avoid the fussy escaping symbols.
```



##### # Value Conversion

due to the purpose of JSON - transferring data across languages, some properties will be filtered automatically during the serialization, included `undefined`, `function`, and `Symbol`.

There are three cases of converting `undefined`, `function` and `Symbol` based on the position of them:

1. Raw type conversion, converted into `undefined`:

    ```javascript
    console.log(JSON.stringify(undefined));			// undefined
    console.log(JSON.stringify(()=>{return;}));		// undefined
    console.log(JSON.stringify(Symbol('symbol')));	// undefined
    ```

2. Within the object, omitted:

    ```javascript
    let obj = {
        name: "robert",
        age: undefined,
        say_hi: ()=>{return;},
        id_card: Symbol('robert')
    };
    console.log(JSON.stringify(obj));
    // {"name":"robert"}
    ```

3. Placed in an `array`, `null` will takes place the corresponding position:

    ```javascript
    let obj = {
        my_array: ["robert", undefined, ()=>{return;}, Symbol('robert')]
    };
    console.log(JSON.stringify(obj));
    // {"my_array":["robert",null,null,null]}
    ```

Besides, two special number type, i.e. `NaN` and `Infinity`, in JavaScript will be converted into `null`:

```javascript
console.log(JSON.stringify("NaN"));			// null
console.log(JSON.stringify("Infinity"));	// null
```

Finally, the wrapped primitive instances will be converted into the primitive values:

```javascript
console.log(JSON.stringify(new String('str')))	// "str"
console.log(JSON.stringify(new Boolean(true)))	// true
console.log(JSON.stringify(new Number(1)))		// 1
```



##### # Parameters

The second parameter of `JSON.stringify()` gives an array that specify those wanted properties, or gives a function to manually process every `(key, value)` pair when serialization. For example, to only select the name and age property from the object:

```javascript
let person = {
    name: "robert",
    age: 20,
    interests: ["coding", "reviewing"],
    girlfriend: null,
    say_hello: ()=>{console.log("hello!")}
};

JSON.stringify(person)
// {"name":"robert","age":20,"interests":["coding","reviewing"],"girlfriend":null}

JSON.stringify(person, ['name', 'age']);
// {"name":"robert","age":20}
```

We can also pass a function to do the preprocess:

```javascript
JSON.stringify(person, (key, value)=>{
    return (value !== person) && (typeof value === 'object') ? undefined : value;
});
// {"name":"robert","age":20}
```

Notice that the iterator will be executed hierarchically, and the top level object (`person` object in this case) will also be considered as a `value`, hence we add `value !== person` condition to keep to top-level object.

As noticed, after the execution of our preprocessor function, the value conversion mechanism will still take responsibility, that's why we can set property to `undefined` to hide them. On the contrary, we can also adjust the property with invisible value into visible, for example, convert the function object into its definition string:

```javascript
JSON.stringify(person, (key, value)=>{
    if(typeof value === 'function'){
        return Function.prototype.toString.call(value);
    }
    return value;
})
// {"name":"robert","age":20,"interests":["coding","reviewing"],"girlfriend":null,"say_hello":"()=>{console.log(\"hello!\")}"}
```



##### # `toJSON` Method

`toJSON` method overrides the default behaviour of the object when serialized:

```javascript
let person = {
    name: 'robert',
    age: '20',
    toJSON: ()=>{return ['robert', '20']},
};

JSON.stringify(person);
// ["robert","20"]

JSON.stringify(wrapper: {person: person})
// {"wrapper":{"person":["robert","20"]}}
```















