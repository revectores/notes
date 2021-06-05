# Python Library `cppimport`

### `cppimport` Introduction

##### Core Workflow

`cppimport` is a python library used to connect to C++ extensions.

Here we use file [`somecode.cpp`](__src_plib_cppimport_demo/somecode.cpp) and the Python interactive shell to demonstrate this:

```cpp
#include <pybind11/pybind11.h>

namespace py = pybind11;

int square(int x) {
	return x * x;
}

PYBIND11_MODULE(somecode, m){
	m.def("square", &square);
}
/*
<%
setup_pybind11(cfg)
%>
*/
```

and run:

```python
>>> import cppimport
>>> somecode = cppimport.imp("somecode")
>>> somecode.square(9)
81
```

We can even import the C++ code like normal Python library, by adding `// cppimport` on the **first** line of C++ file. Then

```python
>>> import cppimport.import_hook
>>> import somecode
>>> somecode.square(9)
81
```
