# Jinja

### 1. Basic Syntax

##### # Typical Structure

Here is the typical content of a jinja template

```jinja2
<!DOCTYPE html>
<html lang="en">
<head>
    <title>My Webpage</title>
</head>
<body>
    <ul id="navigation">
    {% for item in navigation %}
        <li><a href="{{ item.href }}">{{ item.caption }}</a></li>
    {% endfor %}
    </ul>

    <h1>My Webpage</h1>
    {{ a_variable }}

    {# a comment #}
</body>
</html>
```

There are four types of symbols in Jinja.

- `{% %}` for statement, like `for, while` statement.
- `{{ }}` for expression, `{{ a_variable }}` for example.
- `{# #}` for comment.
- `# ##` for line statement.



##### # Variable

The variable can be accessed by `{{ var_name }}` syntax. Use



