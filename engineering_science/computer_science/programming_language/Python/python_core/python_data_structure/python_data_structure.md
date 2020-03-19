# Python Data Structure

### 1. List

##### # List Iterator: `map`, `filter`, `reduce`

The functional-style map and filter keyword have more elegant and pythonic implementation in python as **list compenhension**, so its no necessary to use them actually. While reduce function is pretty useful indeed.

map prototype:

```python
items = range(6)
# map version
map(lambda x:x**2, items)	# [0,1,4,9,16,25]
# listcomp version
[x**2 for x in items]
```

filter prototype:

```python
items = range(-5,6)
# filter version
filter(lambda x:x<0, items)		# [-5,-4,-3,-2,-1]
# listcamp version
[x for x in items if x<0]
```

reduce prototype:

```python
items = range(1,6)
reduce(lambda x,y:x*y, items)	# 120
```

The funny part is that lambda and iterator can use any tpyes of data, even a function:

```python
mysum = lambda x: x+x
myproduct = lambda x: x*x
myfuns = [mysum,myproduct]
for i in range(5):
    A = map(lambda x: x(i), myfuns)
    print A
'''
[0, 0]
[2, 1]
[4, 4]
[6, 9]
[8, 16]
'''
```

