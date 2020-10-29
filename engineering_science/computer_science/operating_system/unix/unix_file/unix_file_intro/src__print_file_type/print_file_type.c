#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void err_ret(char* err_msg){ 
	write(STDERR_FILENO, err_msg, strlen(err_msg));
	exit(-1);
}


int main(int argc, char *argv[]){
	int i;
	struct stat buf;
	char *file_type;

	for (i = 1; i < argc; i++) {
		printf("%s:  ", argv[i]);
		if (lstat(argv[i], &buf) < 0) {
			err_ret("lstat error\n");
			continue;
		}
		if (S_ISREG(buf.st_mode)){
			file_type = "regular";
		} else if (S_ISDIR(buf.st_mode)) {
			file_type = "dictionary";
		} else if (S_ISCHR(buf.st_mode)) {
			file_type = "character special";
		} else if (S_ISBLK(buf.st_mode)) {
			file_type = "block special";
		} else if (S_ISFIFO(buf.st_mode)) {
			file_type = "fifo";
		} else if (S_ISLNK(buf.st_mode)) {
			file_type = "symbolic link";
		} else if (S_ISSOCK(buf.st_mode)) {
			file_type = "socket";
		} else {
			file_type = "** unknown mode **";
		}
		printf("%s\n", file_type);
	}
	exit(0);
}
