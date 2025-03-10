# Linux Command - xargs

##### # Motivation

Some shell commands are designed to accept parameters from both [stdin]() or the parameters and can even hardly be distinguished sometimes, but this is not always the case. There is a huge difference between: The shell command is able to receive input from pipeline only if it accepts input from stdin.

For instance, if you want to search for some file with specific names and add them into track, you might want something like this

```shell
> find * -type f -name "*xargs*" | git add
Nothing specified, nothing added.
Maybe you wanted to say 'git add .'?
```

But this will not work since `git add` does not read from stdin. `xargs` provides help in this case, by converting the stdin to command parameters:

```shell
> find * -type f -name "*xargs*" | xargs git add
```

another example is the `echo` command:

```shell
> echo hello | echo

> echo hello | xargs echo
hello
```

