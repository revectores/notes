##### Example: `lseek` Seekable Check

```c
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
        printf("cannot seek\n");
    else
        printf("seek OK\n");
    exit(0);
}
```

Invoke this program:

```shell
$ ./a.out < /etc/passwd
seek OK
$ cat < /etc/passwd | ./a.out
connot seek
```



