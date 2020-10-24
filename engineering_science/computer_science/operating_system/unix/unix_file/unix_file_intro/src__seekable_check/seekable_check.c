#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*
$ ./a.out < /etc/passwd
seek OK
$ cat < /etc/passwd | ./a.out
connot seek
*/

int main(){
    if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
        printf("cannot seek\n");
    else
        printf("seek OK\n");
    exit(0);
}
