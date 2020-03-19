# Linux Commands Review

### 1. Manipulating File And Directories

1. Implement the following steps:
   - Going to home dictionary.
   - Create a new dictionary called `books`
   - In dictionary  `book`, Create dictionaries called `math`, `cs`, `psycho`.
   - 








### 2. Working With Commands

1. find out the type of the following commands and where the executable files locate:

   `ls, rm, cd, type, ll`

   - How many kinds of command types are there?

2. Use 4 methods to get help if you don't know how to use some commands. (1 to get the brief and 3 to get the detailed)

   - What's the differences between these methods?

3. How to find out some commands to deal with "floppy"?

4. Create a shortcut to do this:

   >  cd to folder `/usr`, and list all items in it, and then turn back.

   and then destory this shortcut.

   - How do you prevent your alias from covering the commands that existed? And why do we often purposefully do this?







### 3. Redirection

1. explain the redirection operator:

   `>, >>, <, 1>, 2>, 2>&1, &>`

   - Explain what command `tee` does.
   - How do you garbage the outputs?

2. Linked the packed video `movie.mpeg.001 movie.mpeg.002 ... movie.mpeg.099` to one file `movie.mpeg`.

3. What happened if you execute a single `cat` without the file provided? Why?

4. Explain the difference between `>` and `|`, use command `ls > less` as the example to show how dangerous it is to confuse with this two command. (And linux won't give you chance to fix this)

5. Show the commands(files) in `/usr/bin` and `/bin`, then delete the repeated items.

   - Show the 10th most frequently used commands in current user.

6. Find out all files in `/usr/bin` which contains string `zip`.

7. Create a file with some contents, then count the words/size of it.







### 4. Seeing The World As The Shell Sees It

1. Get all the files and hidden ones using `echo`.
   
2. How to calculate expression in `bash`?

3. Imagine you are a photographer and want to store photoes according to the month it took, from 2007 to 2009, create those empty folders for yourself.

   ```bash
   2007-01, 2007-02, 20007-03, ... 2009-12
   ```

4. Find out all the environmental variables. Find out current user name. Using `echo`.

5. Find out the types of files in testcase6.5.

6. Explain the differences between single quotes `''` and double quotes `""`.

7. Explain this:

   ```bash
   echo this is a     test
   # this is a test
   echo "this is a     test"
   # this is a      test
   ```

   Noticed that how the parameterization mechaism works in this instance.







### 5. Advanced Keyboard Tricks

1. Clear the screen.
2. Get the history list.
3. How to use the auto-finish mechanism?
4. Use `reverse-i-search` tool to search some command used to use and copy it to the current standard input instance.
5. Explain what is the meta key and why it exists.

