# Python Object Model

### 1. Object

##### # Fundamental Attributes

All data in a Python program is represented by objects, or by relations between projects.

Every object has an **identity**, a **type**, and a **value**.

- An object's identity never changes once it has been created. `is` operator is provided to compare the identity of two objects. The `id()` function returns an integer representing its identity. For CPython, `id(x)` is the memory address of `x`.

- An object's type determines the operations the object supports, and also defines the possible values for objects of that type. The `type()` function returns an object's type. An object's type is also unchangeable, like its identity.

- There are two types of objects: Objects whose value can change are said to be **mutable**, otherwise **immutable**.

  The subtle part comes from the immutable container: The value of an immutable container object that contains a reference to a mutable object can change when the latter's value is changed; however the container is still considered immutable, because the collection of objects it contains cannot be changed.

