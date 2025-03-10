#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char** argv){
	// close(0);
    int fd = open("file", O_RDONLY);
    printf("%d", fd);
    return 0;
}