#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


int main(){
	close(1);
	int fd = open("output.txt", O_CREAT | O_WRONLY);
	FILE* f = fdopen(fd, "w");

	for (int i = 0; i < 2; i++){
		fork();
		printf("-\n");
	}
}
