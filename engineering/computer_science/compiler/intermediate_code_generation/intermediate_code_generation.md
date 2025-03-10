# Intermediate Code Generation

### 1. Motivation

$$
\newcommand{\ra}{\rightarrow}
$$

We introduce intermediate language to decouple front end and back end. This reduces workload. For any front end language all we have to do is to translate it into the intermediate language instead of connecting it into each back end language respectively, and vice versa.

A compiler may construct a sequence of intermediate representations. High-level representations are close to the source language and low-level representations are close to the target machine.

The choice or design of an intermediate representation vaires from compiler to compiler. For instance, C is a programming language, yet it is often used as an intermediate form because it is flexible, compiles into efficient machine code, and its compilers are widely available. The original C++ compiler consisted of a front end that generated C, treating a C compiler as a back end.







### 2. Three-Address Code

##### # Definition of Three-Address Code

In three-address code, there is at most one operator on the right side of an instruction. No built-up arithmetic expressions are permitted. Thus we might translate `x + y * z` into the sequence of three-address code instructions like

```
t1 = y * z
t2 = x + t1
```

where `t1` and `t2` are compiler-generated temporary names.

Here are some common forms of three-address code, where `x, y, z` are addresses:

- `x = y op z`, where `op` is a binary operator.

- `x = op y`, where `op` is a unary operator.

- `x = y`.

- `x = y[i]`

- `x[i] = y`

- `x = &y`, `x = *y, *x = y`.

- `goto L`

- `if x goto L`

- `if x relop y goto L`, where `relop` is a relational operator.

- Specially, the procedure call `p(x1, x2, ..., xn)` are divided into sequence of three-address code

  ```
  param x1
  param x2
  ...
  param xn
  call p, n
  ```



##### # Representation of Three-Address Code

Three-address code can be represented by **quadruple**, **triple**, or **indirect triple**.

A quadruple constructs of four fields: `op`, `arg1`, `arg2` and `result`. Some of them might be omitted in special three-address code. Here are some examples

| Three-Address Code | Quadruple(op arg1 arg2 result) |
| :----------------: | :----------------------------: |
|    `x = y + z`     |           `+ y z x`            |
|   `x = minus y`    |         `minus y / x`          |
|     `param x`      |         `param / / x`          |

A a triple has no `result` field, the temporary variable reference is done by triple location.

Indirect triples consist of a listing of pointers to triples, rather than a listing of triples themselves.

> **Example: Representations of Three-Address Code**. Consider assignment expression
>
> ```
> a = b * (-c) + b * (-c)
> ```
>
> Three-address code:
>
> ```
> t1 = minus c
> t2 = b * t1
> t3 = minus c
> t4 = b * t3
> t5 = t2 + t4
> a  = t5
> ```
>
> Quadruples:
>
> |      |  op   | arg1 | arg2 | result |
> | :--: | :---: | :--: | :--: | :----: |
> |  0   | minus |  c   |      |   t1   |
> |  1   |   *   |  b   |  t1  |   t2   |
> |  2   | minus |  c   |      |   t3   |
> |  3   |   *   |  b   |  t3  |   t4   |
> |  4   |   +   |  t2  |  t4  |   t5   |
> |  5   |   =   |  t5  |      |   a    |
>
> Triples:
>
> |      |  op   | arg1 | arg2 |
> | :--: | :---: | :--: | :--: |
> |  0   | minus |  c   |      |
> |  1   |   *   |  b   | (0)  |
> |  2   | minus |  c   |      |
> |  3   |   *   |  b   | (2)  |
> |  4   |   +   | (1)  | (3)  |
> |  5   |   =   |  a   | (4)  |
>
> Indirect triples:
>
> | Line number | Instructions |
> | :---------: | :----------: |
> |     35      |     (0)      |
> |     36      |     (1)      |
> |     37      |     (2)      |
> |     38      |     (3)      |
> |     39      |     (4)      |
> |     40      |     (5)      |

