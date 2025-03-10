#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main(){
	int fd;

	if ((fd = creat("file.hole"), FILE_MODE) < 0){
		perror("creat error");
		exit(1);
	}
}