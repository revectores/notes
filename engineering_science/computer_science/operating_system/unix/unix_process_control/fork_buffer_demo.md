# Fork Buffer Demo

Consider the two code snippets below:

[fork_printf_with_newline.c](__src__/fork_printf_with_newline.c)

```c
for (int i = 0; i < 2; i++){
  fork();
  printf("-\n");
}
```

[fork_printf_without_newline.c](__src__/fork_printf_without_newline.c)

```c
for (int i = 0; i < 2; i++){
  fork();
  printf("-");
}
```

The only difference is the tailing `\n`. How many `-` will the two programs print respectively? The intuitive answer is 6 for both cases based on the semantics of `fork`:

- In the first iteration, `fork()` creates one more process, and the two processes both execute `printf` once.
- In the second iteration, `fork()` creates two more processes, and the four processes all execute `printf` once.

This is true for the first snippet but not for the second. The output of second program contains 8 dash lines.

Why? `printf` **buffers** the output ([The specific size is implementation-dependent](https://stackoverflow.com/questions/10904067/in-c-whats-the-size-of-stdout-buffer)), then the buffer is copied from parent process to child. Hence for the second iteration, `fork()` creates two more processes, now the `stdout` buffers of all four processes are identical: one dash line.

Why buffer copy has no effect on the first snippet? Because in this case when the output stream goes towards the terminal, the default buffer rule is **line buffering**, which means a new line flushes the buffer implicitly. On the contrary, if the output stream goes towards file, where the rule is **full buffering**, the buffer will not be flushed:

[fork_printf_to_file.c](__src__/fork_printf_to_file.c)

```c
close(1);
int fd = open("output.txt", O_CREAT | O_WRONLY);
FILE* f = fdopen(fd, "w");

for (int i = 0; i < 2; i++){
  fork();
  printf("-\n");
}
```

We can always add `fflush()` to flush `stdout` explicitly to avoid this unexpected behaviour:

[fork_printf_without_newline_fflush.c](__src__/fork_printf_without_newline_fflush.c)

```c
for (int i = 0; i < 2; i++){
  fork();
  printf("-");
  fflush(stdout);
}
```

Or you can simply bypass the stupid `printf`. Output from wrapper of system call `write` will not be buffered:

[fork_write.c](__src__/fork_write.c)

```c
for (int i = 0; i < 2; i++){
  fork();
  write(1, "-", 1);
}
```
