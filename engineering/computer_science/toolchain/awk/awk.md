# awk

##### # Usage

awk is a interpreted programming language that processing text file line-by-line, which usually used in the shell to accomplish simple field-based text processing task. There are two common usages of awk command

```shell
awk 'program' [file]
awk -f [program-file] [file]
```

By providing the option `-f`, we provide the awk script through a file, which avoid some compatibility problems when using the first inline form, the details is provided in [awk_inline_problems](awk_inline_problems). ==TODO: Create this.==

Another common approach is processing the output of some shell command through piping:

```shell
cmd | awk 'program'
```



##### # Format

The general format of awk program is

```awk
[pattern] [action]
```

The `[pattern]` specifies which lines should be processed by the given `[action]`. One of them can be omitted. If the `pattern` is omitted, every line of file will be processed; if the `action` is omitted, then awk will simply print the line obeys pattern.

For multiple `[pattern] [action]` combinations given in one file, awk will run them sequentially and independently. For example, the awk program file with content

```awk
#! /bin/awk -f

/12/ {print $0}
/21/ {print $0}
```

will print all the lines contains `12` or `21`, and those lines with both patterns will be printed twice.



##### # Field

Each line is contructed by many fields, seperated by space characters by default, and the seperator can be specified by assigning variable `FS`, or setting the `-F/--file-separator` option (which actually also change `FS`).

The special variables `$1, $2, $3 ` represents the fields, numbering starts from the left. Specially, the variable `$0` represents the entire line. Take an example,

```shell
ls -l | awk '{print $9 " " $3 " " $1}'
```

This will printed the 9th, 3rd, 1s field of the output of `ls -l`, which is the filename, owner's name, and `rwx` mode respectively.

Besides the constant, the field number can be provided by variable, for example, 





##### # `print`

The `print` statement print its following object.

```shell
awk '{print $0}' data
```

Since no pattern is provided, this print applied `print $0` to entire line, that is, print entire line. Hence this command actually print the entire file.



##### # Variables

variable can be used directly without assigned:

```awk

```



