#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>


int main(){
	int fd = open("\n\x0a", O_CREAT);
	close(fd);
}
