# Python Core

### 1. Function

##### # Function Definition





##### # Lambda Function

lambda prototype:

```python
x = lambda a: a+10
print x(1)		# 15
```

Basically lambda function is a short expression of a equivlent definition block. And the call syntax of them are totally the same, we can't tell which type of definition it used if we just look at the caller.



The fun part is the nesting of lambda and definition syntax:

```python
# def version
def myTimer(n):
	return lambda x: x*n
myDoubler = myTimer(2)
print myDoubler(3)		# 6
```

While only using lambda to nest will make the syntax a little tricky:

```python
# pure-lambda version
myTimer = lambda x,n: x*n
myDoubler = lambda x: myTimer(x,2)
print myDoubler(3)		# 6
```

In the def version, myTimer can be easily understand as a **lambda generater**, cause it returns a lambda expression, but the pure-lambda version makes the purpose not so clear.

