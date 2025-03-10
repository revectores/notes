# Linux Command `man`

There are 8 **sections** in `man` in standard:

1. Executable program or shell command.
2. System call (function provided by the kernel).
3. Librarary call (function provided within program library).
4. Special file (in [`/dev`]() ususally).
5. File formats and conventions (e.g. [`/etc/passwd`]()).
6. Games.
7. Miscellaneous (including macro packages and conventions, e.g. `man(7)`, `groff(7)`).
8. System administration commands.

When there are manual entries with same names in different sections, man will return the first entry it found. For instance, there are `exit` command on section 1 (shell), section 2 (system call `_exit` and `_Exit`) and section 3 (library function `exit`). Use `man exit` gives the first entry about the shell. To select the section explicitly, add a section number after man, such as `man 2 exit`.

