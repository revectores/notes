# Linux Commnads Review Reference

### 1. Working With Commands

1. Use `type` command.

   - There're four basic command types in bash: bash builtin and bash keyword as the function provided by bash itself, besides executable file as the extend, and the `alias`. 

2. Use `whatis` to get the brief one-line description, and `man`, `info`, or `--help` parameter to get the specific infomation.

   - `man` command is a bulitin command, which means it's just used in bash but not other shell, while `info` is a tree-structrue files which is not limited on bash. `--help` is the document directly provided by the command, while not all commands are such kind.

3. `apropos floppy`

4. `alias some_alias='cd /usr; ls; cd -'`

   - We can avoided this by previously use the `type ` or `file` command to check.

     Sometimes we intentionally do the coverage to make the most-common usage more convenient, e.g. if we want to prevent the careless file manipulation, we can just force the infomation option `-i` always open:

     ```bash
     alias mv='mv -i'
     alias rm='rm -i'
     alias cp='rm -i'
     ```



##### Chapter 6 - Redirection

1. `>` redirects the output to file by writing mode while `>>` is the appending mode(so the latter one is safer), `<` redirects the file content to be the input.

   The output and the error info are considered different (although they both look the same at bash interface) and designed to go to the different abstract file on bash, `1>` means to redirect the output and `2>` means to redirect the error. By default the simple `>` symbol indicates `1>`. These two commands can be used at the same time to redirect info into the different files. If you want to redirect these two kinds of info into the same file, use this:

   ```bash
   ls 1>info.txt 2>&1
   # This is the same as
   ls &>info.txt
   ```

   - `tee` provides a machanism to get both the stdout and file-writing:

     ```bash
     ls tee info.txt
     ```

     Then the result of `ls` will both be shown on stdout and store in the file `info.txt` 

   - redirect it into `/dev/null`

2.  Use the `cat` command:

   ```bash
   cat movie.mpeg.* > moive.mpeg
   ```

   - As we know without the rediction operator, `cat` command can be used to open file, if you input a single `cat` without and filename provided, the system will consider this as open a special file: the stdin, which is, the current instance bash itself.

     As the result, after enter this, the bash will return nothing and "hang over" to wait your input, and output anything the same as what you've input, including the commands.

3. pipeline operator `|` use the last's command output to be the input of the next command, not interact with the command source file itself, while `>` make the next "file" to be the output of the left expression, which override the file. Here `ls > less` stores the output of ls in the file "`less`", if you are in `/usr/bin` now, then the original `less` file will be override.

4. Use `uniq` command:

   ```bash
   ls /usr/bin, /bin | uniq
   ```

   - `awk '{print $1}' ~/.bash_history | sort | uniq -c | sort -r | head -10`

5. Use `grep` to apply the regex:

   ```bash
   ls /usr/bin | grep zip
   ```

6. Use `wc` command.



##### Chapter 7 - Seeing The World As The Shell Sees It

1. `echo *`

   -  `echo *, .*`, `ls -A`

2. Use the arithmetic expansion:

   ```bash
   echo $(( (7+2) * 2 ))
   ```

3. Use the brace expansion:

   ```bash
   mkdir Photos; cd Photos; mkdir {2007..2009}-{01..12}
   rm {2007..2009}-{01..12} # Clean 
   ```

4.  

   ```bash
   printenv
   echo $USER
   ```

5. Use command expansion:

   ```bash
   cd /usr/bin; file $(ls | grep zip); cd -
   ```

6. Single quotes `''` is the strict mode, which disable all the possible expansion mechanism, while the double quotes `""` is softer which just disable a part of the expansion.

   - When we `echo ` something, actually the bash consider the input as a parameter list, which splited by space as normal, so the bash even don't have ability to recognize the different from multi-space from one-space, as the result, if quotes are not applied, the bash will just output one space for each delimiter.



##### Chapter 8 - Advanced Keyboard Tricks

1. `clear`
2. `history`
3. Click `tab`

5. Basically it's the historical reason: in the ancient 70s people normally use the terminal to connect to the remote computer, but the terminals are not standardized, as the result not all of them share the same `Alt` key as the meta key in bash, so the meta key become changable until today.