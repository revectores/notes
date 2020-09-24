# math.h

List of simple formalized function:

| Functions in `math.h`       | Functions Formula                    |
| --------------------------- | ------------------------------------ |
| `sin(x), cos(x), tan(x)`    | $\sin x, \cos x, \tan x$             |
| `asin(x), acos(x), atan(x)` | $\arcsin x, \arccos x \arctan x$     |
| `sinh(x), cosh(x), tanh(x)` | $\sinh x, \cosh x, \tanh x$          |
| `exp(x), log(x), log10(x)`  | $\text{e}^x, \ln x, \log x$          |
| `pow(x, y)`                 | $x^y$                                |
| `ldexp(x, n)`               | $x \cdot 2^n$                        |
| `sqrt(x)`                   | $\sqrt{x}$                           |
| `ceil(x), floor(x)`         | $\lfloor x \rfloor, \lceil x \rceil$ |
| `fabs(x)`                   | $|x|$                                |
| `fmod(x, y)`                | float remainder of $x/y$             |

- `modf(x, double* ip)` splits `x` into the integral and fraction part, stores in the `double* ip` and returned respectively. Both parts of with the same sign as `x`.
- 

Notice that almost all of the functions implemented in `<math.h>` are the float version, the corresponding int version might be found in `<stdlib.h>`, such as `abs(n), mod(n)`.

