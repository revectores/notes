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
