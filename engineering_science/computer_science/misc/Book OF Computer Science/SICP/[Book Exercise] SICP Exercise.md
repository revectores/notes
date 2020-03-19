

### Chapter 1

##### Exercise 1.1

```lisp
10	12	8	3	6
/	/	19	#f	4
16	6	16
```



##### Exercise 1.2

``` lisp
(/ (+ 5 4 (- 2 (- 3 (+ 6 (/ 4 5))))) (* 3 (- 6 2) (- 2 7)))
```



##### Exercise 1.3

```lisp
(define (<= x y)
    (not (> x y))
)

(define (add_max_two x y z)
    (cond ((and (<= x y) (<= x z)) (+ y z))
     	  ((and (<= y x) (<= y z)) (+ x z))
     	  (else (+ x y))
     )
)
```



##### Exercise 1.4

According the symbol of b to determine the operator in the expression, to make a plus the absolute value of b.



##### Exercise 1.5

 If the interpreter works as applicative order, then it will first try to determine the value of p in the expression

```lisp
(test 0 (p))
```

In which case it will fall into the infinite loop cause the p is defined as itself. The interpreter will break down.

In contrast, if the interpreter works as normal order, the p will not be cared until it's necessary, so it replace the function test as:

```lisp
(if (= 0 0) 0 (p))
```

It's the final status because nothing could be replace by its definition again, so the interpreter decide to evaluate by order, in this case the predicate expression is evaluated first, it gives out #t, so next expression needed to be evaluate is 0, and we don't need to find out what the value of p is anymore, which avoids the deadly loop.

In short, if the interpreter works as normal order, it returns 0, otherwise if it works as applicative order, it breaks down.



##### Exercise 1.6

The different between if and Eva Lu Ator's new-if has a little but critical difference(at least in this tail recursion situation): The **special form** "if" provide a mechanism (in applicative order) which allows us to determine the value of predicate expression first and do not have to evaluate the two parameters both. It gives the interpreter the ability to stop evaluating the second recursion. But the self-defined new-if is different , although it works well in the simple case indeed. Once we create a recursion, according to the procedure introduced in 1.1.3, the interpreter will have to evaluate all the 3 parameters first, which caused a deadly loop.

The key of this problem is that the Lisp provides severals of **special forms**, in this Exercise we learn about that the special forms implemented in Lisp is not only syntactic sugar, but might be the only way sometimes. (The define statement is too special to not make people feeling awesome)

BTW, what if an interpreter uses normal order? As far as we considered if an interpreter implemented by normal order strectly, it will not allow the tail recursion to exist at all, no matter using special form "if" or the self-defined "new-if", caused by the infinite requests to expand the expression. (except it make a special case on the if statement on purpose, but breaks the basic definition of normal order)



##### Exercise 1.7

If the root is very small, then the predetermined tolerance will be too large to ignore. For example, 0.0001^2 = 0.000 000 1, if we used 0.001 as the tolerance, the program might give out 0.0011 as the result, which is 11 times than the right answer, or it will be -0.009, even producing a negative number. Both case is absolutely intolerable.

In regard to the big number, normally the interpreter is not supported to infinite precision. For Example in Lisp once the number is large enough it will be expressed by scientific notation instead, meanwhile detecting a small difference will be impossible:

```lisp
(define a 1e+30)
(define b 1e+30)
(= a b)				;#t
(define c (+ b 1))
(= b c)				;#t
(- b c)				;0
```

In order to record the last guess we need to add a new parameter to the definition of function sqrt-iter.

```Lisp
(define (sqrt-iter guess last-guess x)
	(if (good-enough? guess last-guess x)
    	guess
    	(sqrt-iter (improve guess x) guess x))
    )
)
```

The new guess is evaluated by improve function, as the result the guess becomes the "last-guess", which was passed into the recursion function.  We don't have to change the definition of "improve" function because it's not related to the last-guess. And then we change the rule to decide the end of loop:

```lisp
(define (good-enough? guess last-guess x)
	(< (abs (/ (- guess last-guess) guess)) 0.001)
)
```

Now we use 1.0 and 2.0 as the initial guess and last-guess (make sure that this two won't be judge as "good-enough" at first)

```lisp
(define (sqrt x)
	(sqrt-iter 1.0 2.0 x)
)
```

The complete code is stored in Appendix C.



##### Exercise 1.8

​	

