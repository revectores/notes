# Endianness

**Endianness** is the order or sequence of bytes of a word of digital data in computer memory. Endianness is primarily expressed as **big-endian** or **little-endian**. A big-endian system stores the **most significant byte** of a word at the smallest memory address. In contrast, little-endian system stores the least significant byte at the smallest address.

Endianness may also be used to describe the order in which the bits are transmitted over a communication channel. Big-endian in a communications channel transmits the most significant bits first.

It's quite easy to detect the endianness of computer by some tricks in programming language, for instance, use union in C:

```c
#include <stdio.h>

union {
	struct {
		short a;
		short b;
	} x;
	int y;
} u;


int main(){
	u.y = 0x12345678;
	printf(u.x.a == 0x5678 ? "Little Endian" : "Big Endian");
	return 0;
}
```

Source can be found [here](src__check_endianness/check_endianness.c).

