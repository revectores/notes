# Vim

### 1. Environment

You can check your version of `vim` by `vim --version` in shell, or `:ve` from the command line in vim. Besides the version, these two commands also provide the modifications of features and paths of the configuration file, like user `.vimrc` file. The current version we're using is `Vim 8.1`, and the features illustrated in this file is based on this version.

The default position of the `.vimrc` file in Linux is `$HOME/.vimrc`.







### 2. Navigation

In this section we introduce four kinds of method to moving around in a single file, including the basic cursor moving, word-wise navigation, find by character in current line, and finally some other useful moving shortcuts. Sometimes we might find we cloud moving by searching, which will be included in the search&replace section.



##### Cursor Move

Use `h`, `j`, `k`, `l` to move the cursor around, one **real** row or column at a time. There're no arrow keys in the old computer so this approach is developed, nowadays the arrow keys are also supported but the efficiency of vim way is far more faster since you don't have to move your hand away.

Remember DO NOT move your right hand one step to the left to make the `hjkl` keys each covered by a finder. As a matter of fact, the key `h` is rarely used because of the other word-wise navigation key.

You can map the arrow keys to `<Nop>` to force yourself get used to the vim way:

```vimrc
noremap <Up> <Nop>
noremap <Down> <Nop>
noremap <Left> <Nop>
noremap <Right> <Nop>
```

Notice that this mapping only disables the naviation in normal mode but still keep them avaliable in insert mode and the command line mode. The usage of arrow keys in normal mode is not forbidden, but if the arrow keys seem unconvient you can map the <c+hjkl> to do the function like 

After you get used to this you can map them to some more useful functions.



##### Word-Wise Navigation

Word-wise move provided as four keys: `w` and `b` to move to the next/previous beginning(the first character) of word, and `e` and `ge` to move to the next/previous last character of word.

Vim distinguishs the two concepts about `word` and `WORD`, a `WORD` is a sequence of ANY non-blank characters, seperated by blanks. `word` is defined similar as the variable naming rule: a word is a sequence of the combination of letters, digits, and underscores, OR, a sequence of OTHER non-blank characters seperated by blanks. This is say that, unlike the WORD, the only seperator of WORD is blank, a sequence of letter/digit/underscore, can be seperated by any OTHER character, and consider as a word.

To illustrate this, consider the expression `((var_a + var_b) * var_c)`, five `WORD` are encountered: `((var_a`, `+`, `var_b)`, `*`, `var_c)`. This is quite strange to combine the bracket and the variable name as a entity, which brings inconvience when we want to operate on them(i.e. use `diW` to delete). While as the perspective of`word`, since `(` is encountere as "other character", it is devided from the variables: `((`, `var_a`, `+`, `var_b`, `)`, `*`, `var_c`, `)`, now the operation is more convinent.




##### Find by Inline Character

`f{char}` jumps to next occurance of character `char`, any inputable character will do.

`t{char}` jumps to the one character before `char`.

The uppercase version `F{char}` and `T{char}` are provided to jumps to the previous occurance.

If you found that you've not achieve the character you want, use `;` to jump to the next occurance, or if you go too far, use the comma `,` to go back.

In practice, you must get a feel about the frequecy of characters in your context to get the best efficiency. i.e. in the english context, `e` usually might be the most-common char, so you should avoid using `fe`, on the contrary, `fz` is quite useful. You can refer to the Morse-code to find out the frequency, and might build a tool to count the preference of yourself.

Except the word character `[a-zA-Z]`, the punctuation mark is also pretty useful during navigation.



##### Shortcuts

If you want to move half the window or a window like in the `less`, the correspondent shorcuts are simply added `Ctrl` , which are `c-u`, `c-d`, `c-f`, and `c-b`.

Adjusting the position of screen without move the cursor is also possible: Press `zz` to make the current line the middle of the window, and `zt` to place the current line the top of the window, `zb` placesd it as the bottom of the window.








### 3. Jump Across Files

##### Window split

Use `sp[lit] ` and `vsp[lit]` command to split the window horizantally or vertically, or use the shortcuts `^W+s` and `^W+v`. By default the new window is a copy of the current window, you can also add the filename as the parameter to open the correspondent file, i.e, `sp filename.md`.

After the window is split, use `^W+hjkl` to jump among the windows based on the location relation. Also you can press `^W^W` to jump sequently.



##### Find file

Vim supports finding a file in the `path` variable(notice that this is the vim var instead of the global environment variable). To make your file to be found by the vim `find` command, first add the target dictionary into `path`:

```vimrc
set path+=dict_path/**
```

Here the double asterisk `**` indicates search the subdictionary recursively. Notice that the double quotes are not allowed in this sytax, and the space in path seems to be unsupported(to passby this bug you can create a soft link pointted to your target folder).

After the folder is added in your path, use `:find filename` so you can find and open the file. Auto completion by `Tab` is supported when typing the filename.

A common requirement is to open the founded file in a split window, this is supported by the `sf` command, and you need to use `vert sfind` to do it vertically, you can add a cabbrev to make this more naturally:

```vimrc
cabbrev vsf vert sfind
```







### 3. Mode Switch

##### Basic Mode

Generally, there're three basic mode in vim: normal mode, insert mode and visual mode, the normal mode is the default, where you can execute commands from this mode; insert mode is where you can edit the text; and visual mode is used to selected a section of text and latter you can operate on them.

Here are how to switch these three mode from one to another: When you are in the normal mode, use `i` to switch to the insert mode, and use `v` to switch to the visual mode. You can use `Esc` key to exit other modes and return to the normal mode at any time. Besides, there're several commands that switch to the insert mode with some extra behaviours:

1. Use `o` or `O` to a new line in the bottom/top, and switch into insert mode.

2. Use `a` or `A` to move the cursor in the next of current character, or the end of the line, and switch into insert mode.

3. Use `I` to move the cursor in the beginning of the current line, and switch into insert mode.



##### Replace Mode

There's a special insert mode called replaced mode, in which mode when you enter a character you will not push the text in the current position forward but replace them instead. The function is the same as the key `Inesrt` in the modern keyboard.

There're two keys to insert replace mode: `r` or `R`. Press `r` allows you to edit one character and after editing you'll be send back to the normal mode again. Press `R` makes you keep replacing until you press `Esc` to manually exit the replace mode.







### 5. Vim Settings

Use `set all` to show all the setting and their values in vim.

Add a `?` mark after the setting name, like `set command?`, to show the current value of it:

```shell
:set tabstop?			# 4
:set relativenumber?	# norelativenumber
```

Notice that the vim setting is different from the global variables, to show the variables you need to `echo :variable_name` or use `let` command to show all the variables.



##### Indent

Use `set tabstop` and `set shiftwidth` to set the indent of vim, by default it's 8, usually we'll set them to 4 to fit the common IDE.



##### Line Number Display

Use  `set nu[mber]` and `set nonu[mber]` to show and hide the line number. Use `set relativenumber/rnu` and `norelativenumber/nornu` to show and hide relative number.






