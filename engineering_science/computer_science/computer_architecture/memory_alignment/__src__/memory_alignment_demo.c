#include <stdio.h>

struct {
	int16_t a;
	int32_t b;
	int16_t c;
} s;


int main(){
	printf("struct size: %lu\n", sizeof(s));
	printf("struct addr: %p\n", &s);
	return 0;
}

