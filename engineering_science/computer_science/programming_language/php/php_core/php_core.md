# PHP Core

### 1. Introduction

##### # Usage

```php
<html><body>
<?php echo "<p>This is a php-generated paragraph.</p>" ?>
<body></html>
```

**PHP(Personal Home Page): Hypertext Processor** is used as a web-content renderer, and widely used in the industry environment. The example above shows that the php script can be directly injected into a html page (by using indentifer `<?php` and `?>` ), and will be executed by the php complier to be the html code. From the user's side this is showed as:

```html
<html><body>
<p>This is a php-generated paragraph.</p>
<body></html>
```

Where the parameter of `echo` is printed to the page. Noticed that if a page is pure php code then the end identifer `?>` can be omitted.

The framework of PHP includes Laravel, Symfony, Yii, and so on.



##### # Basic Syntax

The comment syntax is C-style.

```php
// This is an inline comment
#  This is also.
/* Multiline
	 Comment */
```



