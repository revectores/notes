# Click

### 1. Quickview

**Command Line Interface Creation Kit(click)** is a python package to construct the comand-line tools. Here shows the offical brief example of using `click` to construct a command:

```python
# !/usr/bin/python
# hello.py
import click

@click.command()
@click.option('--count', default=1, help='Number of greetings.')
@click.option('--name', prompt='Your name', help='The person to greet.')
def hello(count, name):
    """Simple program that greets NAME for COUNT times."""
	for x in range(count):
        click.echo('Hello %s' % name)
        
if __name__ == '__main__':
    hello()
```

