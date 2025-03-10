# Compiler Introduction

##### # Definition of Compiler

A compiler is a comptuer program that translates computer code written in one programming language (the **source language**) into another langugae(the **target langauge**).

An **interpreter**, however, directly execute the operations specified in the source program on inputs supplied by user.



##### # Structure of Compiler

Roughly there are two process of compiling: **analysis(front end)** and **synthesis(back end)**.

- The analysis part breaks up the source program into constituent pieces and imposes a grammatical structure on them. It then uses this structure to create an intermediate representation of the source program. A **symbol table** is built to collect infomation.
- The synthesis part constructs the desired target program from the intermediate representation and the information in the symbol table.

Each part are constructed by a seqeunce of **phases**, each of which transforms one representation of the source program to another. Here is a typical sequence phases:

1. **Lexical analysis**
2. **Syntax analysis (Parsing) **
3. **Semantic analysis**
4. **Intermediate code generation**
5. **Machine-independent code optimization**
6. **Code generation**
7. **Machine-dependent code optimization**

