# Linux Command `ls`

##### # `ls ` Usage

`ls` list directory contents, by default list the current directory.



##### # `ls` Sort

`ls` sort files alphabetically by default. `--sort` and multiple equivalent options is provided to specify the sort method:

| `--sort` method    | Option Equivalent | Interpretation                                  |
| ------------------ | :---------------: | :---------------------------------------------- |
| `--sort=none`      |       `-U`        | Do not sort. list the entry in directory order. |
| `--sort=size`      |       `-S`        | Sort by file size.                              |
| `--sort=time`      |       `-t`        | Sort by modification time, newest first.        |
| `--sort=version`   |       `-v`        | Natural sort of version numbers within text.    |
| `--sort=extension` |       `-X`        | Sort alphabetically by entry extension          |



##### # `ls` Filter

By default, the `ls` command does not list those hidden files starting with a dot. Use `-A` List all entries except `.` and `..`, and `-a` includes them all.

`-d` list the information of directory itself instead of list all contents.



##### # `ls` Filename Escape

If there are non-printable(nongraphic) characters in filename, by default `?` will be display, use `-b` or `--escape` to print them as the C-style escape characters.

> Note that FreeBSD (and macOS) support `-b` as the same interpretation but not `--escape`, and a extra option `-B` print directly the octal code instead of C-style escaping. For instance, display `\012` instead of `\n`.
>
> Instead, for Linux `-B` is used to exclude the backup files (files tailing with `~`).

Use [create_nonprintable_filename.c](src__create_nonprintable_filename/create_nonprintable_filename.c) to create a file containing nonprintable character to check this.





