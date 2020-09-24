# JavaScript Data Type

### 1. Introduction

##### # Classification

Seven datatypes are included in JavaScript.

- Number, includes integer and float number.
- String.
- Boolean. `true` or `false`.
- Object, includes the `object`(narrowly speaking), `array`, and `function`.
- `undefined`.
- `null`.
- Symbol. `Symbol` data type is a new feature introduced in ECMAScript6, and we'll introduced in [Symbol](symbol.md).

Number, string and boolean are considered as the **primitive type**, and object are **complex type**, compounded of the primitive type variables. `undefined` and `null` are special data type occured in special cases.

Notice that `function` is considered as a type of object in JavaScript, hence it can be assigned to a variable, which contributes to flexibility of this language.



##### # Type Query

Three methods are provided in Javascript to query the type of a variable:

- `typeof` operator.
- `instanceof` operator.
- `Object.prototype.toString` method.

The `typeof` operator returns the data type of a variable **as a string**:

```JavaScript
typeof 123			// "number"
typeof "123"		// "string"
typeof true			// "boolean"
typeof typeof 123	// "string"

function f(){};
typeof f			// "function"
var f2 = function(){};
typeof f2			// "function"

typeof undefined;	// "undefined"
typeof null			// "object"
```

Specially, `typeof null == "object"`, which is derived by the histroical reason. In the first version of JavaScript only five data types are introduced, `null` is considered as a special type of object. Nowadays `null` is defined as a new data type, while the behaviour of `typeof null` is still kept for the compatibility.

Now let's apply `typeof` to array and object:

```javascript
obj = {1: 1, 2: 2, 3: 3};
arr = [1, 2, 3];

typeof obj;		// "object"
typeof arr;		// "object"
```

Notice that since array is considered as a special object internally, `typeof` operator will gives the same result as `object`. To distinguish them, use `instanceof` instead:

```javascript
obj instanceof Object;		// true
obj instanceof Array;		// false
arr instanceof Object;		// true
arr instanceof Array;		// true
```

`instanceof` operator determined whether a variable is an instance object of a class. As mentioned, JavaScript declares number, string, and boolean as the primitive type explicitly, that is, they are not considered as the instance of their "construtor class":

```javascript
1 instanceof Number		// false
"1" instanceof String	// false
true instanceof Boolean	// false

new Number(1) instanceof Number		// true
new String(1) instanceof String		// true
new Boolean(1) instanceof Boolean	// true
/* Type conversion takes place automatically here:
/ String(1) = String("1")
/ Boolean(1) = Boolean(true) */
```

In most of the modern programming language, the type checker is designed as function or method instead of operator, you can refer [this question](https://stackoverflow.com/questions/2449254/what-is-the-instanceof-operator-in-javascript) to find the reason why JavaScript design them as the **operator**.







### 2. Null and Undefined

##### # Definition

`null` is considered as "empty", like the null pointer in C or null object in Java, we usually assigned a value as `null` explicitly if we want to set it as empty. On the contrary, `undefined`, as named, represents "undefined", any variable you try to get value, but has not been defined or assigned, will be assigned to `undefined` automatically.

Generally, `null` is the empty value in program-level, assigned by the programmer actively, while `undefined` is the empty value in system-level, be assigned by the complier passively. Normally, you should never assign `undefined` to any variable yourself manually.

Practically, the value `undefined` occured in the following cases:

- The variable is declared by not assigned.

    ```javascript
    var i;
    i;		// undefined
    ```

- Try to achieve the nonexistent property of an object.

    ```javascript
    obj = {a: 1, b: 2, c: 3};
    obj.d;	// undefined
    ```

    Potential error might hide in this behaviour, altougth getting the nonexistent property returns `undefined`, which not cause a error, but the object usually constructs hierarchy, in that case, you might try to refer the property of `undefined`:

    ```javascript
    book = {
        name: "Javascript Tutorial",
        first_author: {
            first_name: 'Robert',
        	second_name: 'Lewis'
        },
    };
    book.second_author.first_name;
    // TypeError: book.second_author is undefined
    ```

- The parameter of function is not provided.

    ```javascript
    function fun(x){
        return x;
    }
    fun(); 	// undefined
    ```

- The returned value of a function without `return` statement.

    ```javascript
    function fun(x){}
    fun();	// undefined
    ```



##### # Data Conversion

When the conversion to `Number()` is called, `null` acts as `0`, while `undefined` acts as `NaN`:

```javascript
Number(null)		// 0
null + 1			// 1
Number(undefined)	// NaN
undefined + 1		// NaN
```

Both of them are considered as `false` when converted into `false`:

```javascript
Boolean(null)		// false
Boolean(undefined)	// false
```







### 3. Boolean

A value is regarded as `false` if and only if its one of `false`, `0`, `NaN`, `""`, `null`, `undefined`.

Different from most of other languages, the empty object `{}` or empty array `[]` in JavaScript, is regarded as `true`. That is, every object or array is regarded as `true`, no matter whether its empty.







### 4. Number

##### # All in IEEE-754

There is no integer in JavaScript, internally:

```javascript
1 === 1.0	// true
```

That is, all the numbers are stored as the 64-bit float point number. As known, [IEEE 754]() gurantees that it is impossible to do the float point computation precisely:

```javascript
0.1 + 0.2 == 0.3	// false
0.1 + 0.2			// 0.30000000000000004
0.3 - 0.2			// 0.09999999999999998
0.3 / 0.1			// 2.9999999999999996
```

[Here](https://juejin.im/post/5b90e00e6fb9a05cf9080dff) gives the details to get the magic value `0.30000000000000004` manually.

To simulate the normal integer computation, JavaScript converts the 64-bit float point value into 32-bit integer first, while this mechanism is only activated for integers.

Based on [IEEE 754](), there are two zeros: `+0` and `-0`, in most cases they behave the same, except when in the denominator:

```javascript
1/(+0)		// Infinity
1/(-0)		// -Infinity
```

which gives `+Infinity` and `-Infinity` respectively.



##### # Number System

Number literal for hex `0x`, bin `0b` and oct `0o` is provided:

```javascript
0xff		// 255
0o377		// 255
0b11111111	// 255
```

Before ES6, the number with leading `0` will be regarded as oct, expect `8` or `9` is included in the digits:

```javascript
099		// 99
077		// 63
```

This ambiguity may cause problems, hence this representation has been abandoned in ES6 (and the strict mode of ES5).





##### # Infinity

Infinity是一个特殊的数, 表示超出了JS的处理范围, 但它仍然属于`number`类型: 

```javascript
>>> typeof(Infinity)
"number"

// We can create Infinity by this:
>>> 1e+308
1e+308

>>> 1e+309
Infinity

>>> 1/0
Infinity

// We can also directly create an Infinity, it's fine:
>>> Infinity
Infinity

// Notice that JavaScript is case-sensitive:
>>> infinity
ReferenceError: infinity is not defined
```

Infinity可以理解成超出了最大数的表示范围, 我们可以用-Infinity表示超出最小数的表示范围, 像这样: 

```javascript
>>> -6/0
-Infinity

// "-Infinity + Infinity" returns NaN instead of 0.
>>> -Infinity + Infinity
NaN

// Besides this, almost any operation on Infinify will not change its value:
>>> Infinity+1
Infinity
>>> -Infinity/3
-Infinity
```





##### # NaN

`NaN`意为"Not a Number", 但是事实上它在JS中仍然是`number`类型的一员. 当我们尝试对数字进行某些不应该进行的操作(但不是溢出错误, 那会导致Infinity)时, 就会收获一个`NaN`:

```javascript
>>> var x = 10 * "f";
>>> x
NaN

>>> NaN + 1
NaN
```







### 5. String

JavaScript字符串可以使用单引号或双引号括起, 不过在Web客户端环境下建议在JS中使用单引号来标志字符串, 这是因为JS常常需要和HTML进行交互, 而HTML中的属性值通常需要用双引号括起, 使用单引号可以避免嵌套时的麻烦(例如引号使用的不统一或者频繁的转义). 

和大部分语言类似, 如果要在字符串内部使用和两端相同的引号, 就必须使用反斜杠`\`对其进行转义, 而字符串中原本存在的反斜杠本身也必须被转义. 对常规字符进行转义可以得到具有特殊含义的字符: 例如换行符`\n`, 回车符`\r`, unicode化字符`\u`等等.





### 6. Array

可以通过直接赋值或`new Array`两种方式创建一个数组

```javascript
let empty_array = [];
let arr1 = [1, 2, 3];
let arr2 = new Array(1, 2, 3);
```











