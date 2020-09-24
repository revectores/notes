# Vim Autocmd

### 1. Create Autocommand

##### # General Format

The general format of autocmd are

```vim
:au[tocmd] [group] {event} {pat} [++once] [++nested] {cmd}
```

For those files meet pattern `{pat}`, when the event `{event}` is triggered, execute the command specified by `{cmd}`. Regex is supported in the pattern field.

For example

```vim
:autocmd BufRead *.txt		set expandtab
```

This will `set expandtab`, for all `*.txt` file when opened.

The common events include

- `BufNewFile`, starting to edit a file that doesn't exist.
- `BufRead`, starting to edit a new buffer, after reading the file
- `BufWrite`, starting to write the whole buffer to a file.
- `FileType`, when the `filetype` option ahs been set.

You can refer the vim `help autocmd` for complete events list.

The event and pattern field can both be the comma separated list, for example, we usually want to execute the same process when create a new file or open an exist file, we use `BufNewFile, BufRead` to receive both events:

```vim
autocmd BufNewFile, BufRead *.proc set filetype=proc
```

The `[++once]` option makes the command one-shot, that is, will be removed right after the first execution.







### 2. List Autocommand

The commands 

```vim
:au[tocmd] {event} {pat}
:au[tocmd] {event}
:au[tocmd] * {pat}
```

will list the autocommands that meet the corresponding event and/or pattern.







### 3. Execute Autocmmand

We can actively execute the command by

```vim
:do[autocmd] {event} [fname]
```

which will execute the autocommand given by the `{event}` and `[fname]`. By default, the parameter `[fname]` is the current filename. While this can also be applied when the current filename does not match the pattern but matched by `[fname]`.

Notice that it is permitted to write a `doautocmd` in an `autocmd`, that is, we can create the autocommand for one pattern based on another pattern. This might lead to endless loop by constructing nested autocommand carelessly.

