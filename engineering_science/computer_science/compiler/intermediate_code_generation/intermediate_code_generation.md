# Intermediate Code Generation

### 1. Motivation

$$
\newcommand{\ra}{\rightarrow}
$$

We introduce intermediate language to decouple front end and back end. This reduces workload. For any front end language all we have to do is to translate it into the intermediate language instead of connecting it into each back end language respectively, and vice versa.

A compiler may construct a sequence of intermediate representations. High-level representations are close to the source language and low-level representations are close to the target machine.

The choice or design of an intermediate representation vaires from compiler to compiler. For instance, C is a programming language, yet it is often used as an intermediate form because it is flexible, compiles into efficient machine code, and its compilers are widely available. The original C++ compiler consisted of a front end that generated C, treating a C compiler as a back end.

