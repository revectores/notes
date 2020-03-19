# Vim QA

##### # How to insert only one character and exit the insert mode instantly?

There's no native one-key shortcut for this, but you could use the combination of insert mode and replace mode and set a shortcut for them like this:

```vim
:nnoremap <Space> i_<Esc>r
```

This command makes <kbd>Space</kbd> key as the combination of four keys: 1)change into insert mode, 2)insert a underline character `_`, 3)exit the insert mode, and finally 4)enter the replace one-character mode. With the help of this shortcut, you can press <kbd>Space</kbd>, which jwill leave a blank to let you type your character.

Notice that this approach doens't support the `.` for repeating insertion, for this purpose you need to create more complex function. You can refer to the following links for more info:

> [https://vim.fandom.com/wiki/Insert_a_single_character](https://vim.fandom.com/wiki/Insert_a_single_character)



##### # How to reopen the window which be closed recently?

use `sp#` to reopen it horizontally or `:vs#` to reopen it vertially.



##### # What to do if my backspace doesn't work in insert mode?

Set `backspace` as

```shell
set backspace=indent,eol,start
```



