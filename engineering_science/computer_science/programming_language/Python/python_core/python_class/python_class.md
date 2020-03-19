# Class

### Operator Overloading

 prototype:

```python
from math import acos
class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __abs__(self):
        return ((self.x)**2 + (self.y)**2)**(1/2)

    def __add__(self,other):
        return Point(self.x + other.y, self.y - other.y)
    
    def __sub__(self, other):
        return Point(self.x - other.x, self.y - other.y)

    def __mul__(self, other):
        return self.x * other.x + self.y * other.y

    def getangle(self, other):
        return acos((self * other) / (abs(self) * abs(other)))
```

It's easy to understand that in python, operator overlaoding can be implement by magic method in the class definition.

