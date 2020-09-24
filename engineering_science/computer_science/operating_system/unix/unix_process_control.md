# Unix Process Control

##### 1. Process Identifer

The global unique **process identifer** is used to refer a process in Unix system. Use `getpid` and `getppid` to get the process identifer of the calling process and its parent process. Expect the process identifer, a process also has some other identifiers such as user id `uid`, effective user id `euid`, group id `gid`, effective group id `egid`. Those identifiers can be retrive by the following functions.

```c
#include <unistd.h>

pid_t getpid(void);
pid_t getppid(void);
uid_t getuid(void);
uid_t geteuid(void);
gid_t getgid(void);
gid_t getegid(void);
```

Some process identifers are specialized to specific processes. For example, in most of Unix implementations, pid 0 is the scheduler process `swapper`, which is actually not a real process. pid 1 is the `init` process, which is invoked by the kernel at the end of bootstrap procedure. Notice that `init` process is actually not a kernel process but a user process.

> In Mac OS X 10.4, the `init` process wa replaced with the `launchd` process, which performs the same set of tasks as init, but has expanded functionalty.



##### 2. `fork`

We create(duplicate) a new child process by `fork`:

```c
#include <unistd.h>
pid_t fork(void);
```

`fork` returns 0 in child, process ID of the child in parent, -1 on error.

We'll explain the behaviour of `fork` by a demo program, and also the common structure of a function that invokes `fork`:

```c
#include <stdio.h>
#incldue <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]){
    printf("hello world (pid:%d)\n", (int) getpid());
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0){
        printf("hello, I am child (pid:%d)\n",
               (int) getpid());
    } else {
        printf("hello, I am parent of %d (pid:%d)\n",
               rc, (int) getpid())
    }
    return 0; 
}
```

And the outputs are

```shell
hello world (pid: 10693)
hello, I am child (pid:10694)
hello, I am parent of 10694 (pid: 10693)
```

by invoking `fork`, the process was duplicated to create a child, and the child starts running from the line `int rc = fork()`(not from the beginning of function, and this is somewhat impossible actually...). At this line, one `fork` call generates two values: for the parent, `fork` returns the pid of child if success, and for the child, `fork` returns 0. Hence, the conditional statement about `rc` helps us distingulish whether its the parent or child process.

Notice that for the two different processes, the sequence of execution is not determinant, which is depends on the scheduling by CPU. As a result, the output for the given demo is not determined, the output from the child and the parent might exchange.

File [fork_file_sharing_example.md](fork_file_sharing_example.md) gives a more complex example relavent to the file descriptor sharing between parent process and its children, providing by APUE.

Due to the counterintuitive design of `fork`, the behaviour of the child process should be carefully taken care of. [a_fork_bug.md](a_fork_bug.md) gives an tricky bug (maybe not that tricky after we found it...) that caused by the misunderstanding about how `fork` works, raised during the development of shell.



##### 3. `wait`

For a parent process, `wait` will block itself until one of its child terminates. For example, in the demo given for `fork`, we can add `wait()` before the `printf` from parent, to make the parent do not print until the child has done.

If we need to wait for n-children, just make n times of  `wait` call, each termination of child process will only unblcok one of the `wait`.



##### 4. `exec`

`exec` replace the program running in current process with a new one. All the relavent data are replaced, without the PID, since no new process is created.

There are seven different `exec` functions with different arguments

```c
#include <unistd.h>

int execl(const char* pathname, const char* arg0, ... );
int execle(const char* pathname, const char* arg0, ..., char* const envp[]);
int execlp(const char* filename, const char* arg0, ...);

int execv(const char* pathname, char* const argv[]);
int execve(const char* pathname, char* const argv[], char* const envp[]);
int execvp(const char* filename, char* const argv[]);
```

The appeding letters hint the differences among these `exec`:

- The fifth letter `l` and `v` represents whether to use individual arguments or an pointer to the argument array.
- The appended `e` allows setting a new environment variables list for the new process instead of copying the current one directly, which can be considered as one approach of passing parameters.
- The appended `p` allows search for `filename` in the `PATH`, but this is not necessary, the absolute/relative directory can still be used in the `filename` argument.

The typical usage of `exec` is shown as the following demo

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        close(STDOUT_FIELNO);
        open("./p4.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
        char* myargs[3];
        myargs[0] = strdup("wc");
        myargs[1] = strdup("p4.c");
        myargs[2] = NULL;
        execvp(myargs[0], myargs);
	} else {
        int wc = wait(NULL);
    }    
}
```











