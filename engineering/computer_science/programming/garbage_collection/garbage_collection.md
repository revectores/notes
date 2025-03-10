there are two main category of garbage collection:

- tracing
- ref counting

paper [] shows that they are equiv.

the most trival tracing algorithm is mark-and-sweep algorithm, which STW and not extensible to concurrent case, considered unacceptable.

hence we add an extra layer (colored with gray)  then make a tri-color model:

- white object, is an object without ref path from root.
- black object, is an object that has ref path from root, and no ref to white object.
- gray object,  is an object that has ref path from root (whether it has ref to white object is undetermined)

and the trivial version applied to tri-color version can be directly derived from the mark-and-sweep.

the invariant 'no black object ref to white object' is called 'strong tri-color invariant', if we STW, the invariant is naturally perserved, but if we do not STW, some 'barrier' must be introduced to add extra color-adjusting action to each write op.


