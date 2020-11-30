# C `pthread`

##### # `pthread` Demo

The typical workflow of C `pthread`:

```{.c .numberLines startFrom="1"}
#include <stdio.h>
#include <assert.h>
#include <pthread.h>


void *mythread(void *arg){
    printf("%s\n", (char*)arg);
    return NULL;
}

int main(int argc, char* argv[]){
    pthread_t p1, p2;
    int rc;
    printf("main: begin\n");
    rc = pthread_create(&p1, NULL, mythread, "A"); assert(rc == 0);
    rc = pthread_create(&p2, NULL, mythread, "B"); assert(rc == 0);

    rc = pthread_join(p1, NULL); assert(rc == 0);
    rc = pthread_join(p2, NULL); assert(rc == 0);

    printf("main: end\n");
    return 0;
}
```

where two functions are included, `pthread_create` for create new thread, `pthread_join` for waitting thread.

Thte prototype of `pthread_create`:

```C
int pthread_create(
    pthread_t*            thread,
    const pthread_attr_t* attr,
    void*                 (*start_routine)(void *),
    void*                 arg
);
```

- The created thread structure will be stored at `thread`.
- `attr` specifies some attributes for the new created thread, default configuration is applied if it's set to `NULL`.
- function pointer `start_routine` is the function that will be executed by new thread.
- `arg` is the arguments passing to `start_routine`.

The prototype of `pthread_join`:

```c
int pthread_join(
    pthread_t thread,
    void**    value_ptr
)
```

The join function wait for `thread` to finish to continue.






##### # `pthread` Race Condition





