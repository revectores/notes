# Memory Alignment



##### # Motivation

The CPU in modern computer hardware performs reads and writes to memory most efficiently when the data is **naturally aligned**, which generally means the data's memory address is a multiple of the data size.

To ensure natural alignment, it may be necessary to insert some **padding** between structure elements or after the last element of a structure.



##### # Implementation in Programming Language

Most of the modern programming languages implementations handle data alignment automatically, in this case some cares must be taken to remove surprise.

For instance, consider struct in C

```c
struct {
    int16_t a;
    int32_t b;
    int16_t c;
} s;
```

The total size of this struct will be 12 Bytes. This is due to two internel alignment:

```c
struct {
    int16_t a;
    char    _pad0[16];
    int32_t b;
    int16_t c;
    char    _pad1[16];
} s;
```

Note that the alignment base of entire struct itself is the field with maximum size (for array field, size of its element). For instance, in this case, the base address of struct has not to be multiples of `sizeof(s)` but multiples of `max(sizeof(int16_t), sizeof(int32_t)) = 4`.

Code for this demo is provided [here](__src__/memory_alignment_demo.c).

Same rules are also applicable for union.



##### # Impact

Memory alignment has deeply affected not only on programming (for instance, you cannot use `memcmp` to determine whether two struct are identity since there might be meaningless alignment bytes inside the struct) but also inside the C++ class model.

