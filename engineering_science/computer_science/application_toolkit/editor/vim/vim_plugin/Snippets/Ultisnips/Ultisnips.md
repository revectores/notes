[toc]

# Ultisnips

### 1. Environment

By default, `Ultisnips` search the snippets in dictionary `~/.vim/Ultisnips`, ==todo: read about the loading mechanism, add path config method== and search the correspondent file for the file type which you're editing, E.G. The snippets which preferred to be triggered only in the context of a file with type `ruby`, it should be placed at file `ruby.snippets`, or `ruby_*.snippets`.

Also, you can create a folder for a file type, E.G. all the file, regardless of the name and the extension, in other word, any file fits the pattern `~/.vim/Ultisnips/ruby/*` is applied to `ruby` file.

The snippets applied to all types of file should be put in `all.snippets`. And you can craete a folder `all` also.

Reference table:

| Snippets Filename | File Type |
| :---------------: | :-------: |
|   ruby.snippets   |   ruby    |
| markdown.snippets | markdown  |
|    c.snippets     |     c     |
|   c_my.snippets   |     c     |
|        c/a        |     c     |
|   c/b.snippets    |     c     |
|   all.snippets    |    all    |
|       all/a       |    all    |

Notice that the file type is **NOT** the extension name, although sometimes they are the same. E.G. By default, the type of file with extension `.md` is `markdown` instead of `md`. This mapping from extension name to file type is maintained by vim itself, but you can still use [`:set filetype`](../vim.md) to change the type of current file at anytime.



### 2. Basic Syntax

##### # Comment

The comment is a line leading with `#`, the same as all configuration file.



##### # Create Snippets

The syntax to define a snippet is shown following:

```snippet
snippet TRIGGER_WORD ["DESCRIPTION"] [OPTIONS]
... context here
endsnippet
```

Where we use a `sinppet/endsnippet` pair to mark the beginning and end of a snippet.  `trigger_word` is the word that will be expand and replaced by snippet.

Regardless of the `OPTIONS`, For example, if you want to create a snippet for insert your name:

```snippet
snippet name "My name"
Robert Lewis
endsnippet
```

Here name is the trigger-word, when you type `name` in vim, then press `<tab>`, the trigger-word will be replace by the content of the snippet, which is `Robert Lewis`.

There's one thing that worth noticing: there shouldn't be any empty line or tab unless you're placing them intentionally. Any character(except for the special blocks like code) will be considered as the output, including the empty line and tab. The `\n` in the end of last line (before `endsnippet`) will be token care of and choped by the parser.



##### # Special Trigger Word

The trigger word with space is permitted, but in this case you need to use the quotes or **ANY PAIRED SYMBOL** to declare that they're the individual. E.G.

```snippet
snippet "name with space" "description"
```

```snippet
snippet |name with space| "description"
```

When the non-quotes mark is used, it's convinent to create the trigger word with space and quotes itself:

```snippet
snippet |"name with space and quotes"| "description"
```



##### # Options

There're several options for defining the behaviour of the snippet:

1. Expand Condition

    - `b` makes it only expands if it's the **FIRST WORD** of line. In another word, before the word there is only allowed to be spaces or none.
    - `i`  makes it can be expanded even inside a word.
    - `w` makes it expanded only if the snippet matched are a single word.

2. Trigger Requirement

    - `A` makes it auto-expanded without the press the trigger key.

3. Content Control

4. 

==todo: finish explaination about the options==



##### # `entends`

The `extends` command will include the snippets from specified filetypes, E.G.

```snippet
extends c, cpp
```

This will make all the snippets for filetype `c` and `cpp` be avaliable for the current type. It's similar as the `#include` or `import` method in other language.







### 3. Commands and Configuration

Here we illustrate the commands used when you're using vim, and the configuration variables associates with them.

##### # `UltiSnipsEdit`

This command open the correpsondent snippet file of the one you're editing. The way how the new window is opened determined by the variable `g:UltiSnipsEditSplit`.





##### # Key Mapping Config

There're four shortcuts config for `ultisnips`:

- `UltiSnipsExpandTrigger`, to expand the commands by given trigger key, this is set as `<tab>` by default.
- `UltiSnipsJump(Forward|Backward)Trigger`, set the shortcut to move forward/backward among the ==stops==.
- `UltiSnipsListSnippets`, ==todo: find out what it is.==







### 3. Script Support

##### # Shell Script

Ultisnips supports shell execution. Specifically, it stores the code into a temporary file and execute that file by `sh` shell, and the standard output(which will print to the shell terminal in normal) becomes the output of the snippet. Use paired `` to insert shell command, which can be inline or multiline.

```snippet
snippet date
Today is `date +%y.%m.%d`.
endsnippet
```

Since the shell can call the other program with the help of shebang tag, this actually support any executable program call, including another shell:

```snippet
snippet fish_call
`
#!/usr/local/bin/fish
fish_greeting
`
endsinppet
```

Besides this general approach, you can use some marks to run specific language and with some special supports, includes the `!v` for vimscript and `!p` for python code.



##### # VimScript

Use !v mark to use vim script:

```snippet
snippet indent "Show the indent of current line."
Indent is: `!v indent(".")`.
endsnippet
```



##### # Python Script

Python interpolation is by far the most powerful. You can use the general approach and add shebang `#!/user/bin/python` but the `!p` approach provides some tools to help process the context and generate the output more naturally, which will be imported in the beginning of the code block. The most important one this the introduce of `snip` object, which is the instance of `UltiSnips.TextObjects.SnippetUtil` , and the most significant property of it is `snip.rv`, which will become the output of snippet, takes place of the standard output stream. 

```snippet
snippet py_snippet
`!p snip.rv = 'Hello!' `
endsnippet
```

Besides, there're some properties appended to the snip object:

1. Text Context
	- `snip.rv` is returned text of the snippet.

2. File Environment
	- `snip.fp` is the path of current file.
	- `snip.fn` is the current filename.
	- `snip.basename` is the current filename with extension removed.
	- `snip.ft` is the current filetype.

`snip` object implemented `mkline(line="", indent=None)` method to add a newline into the result. `+=` operator of `snip` is also overloaded to implement this function. To control the default indent without providing it each time in `mkline` method, `shift(amount=1)`, `unshift(amount=1)` and `reset_indent()` method are provided. `<<` and `>>` operator of `snip` are overloaded, which are equvilant to `shift` and `unshift`. 

Besides the `snip.mkline` method and those help control the indent, there's another method `snip.opt(var, default)` to retrieve the value of environment variable of vim. If the variable `var` has been set, it returns the value of `var`, otherwise it returns `default`.

There might be multiple python code blocks in one snippets, and once the varialbe defined, it can be used in the following any blocks:

```snippet
snippet mutliple_blocks 
`!p a = 1`
a is `snip.rv = a`
a+1 is `!p snip.rv = a + 1 `
endsnippet
```

Several frequently used packages are imported automatically, includes `vim`, `os`, `string`, `re` and `random`. Of course you can import any other python packages you like. After `Vim7.4`, You can place user-defined module into `~/.vim/pythonx` then it can be imported as those standard library in `PATH`.



##### # Global Script
You can place global script at the beginning of snippet file, and the function and variable defined inside it will be avaliable in any snippets in the file:

```snippet
global !p
def greeting():
	return 'hello'
endglobal

snippet greet
`!p snip.rv = greeting()`
endsnippet
```

Combined with the usage of `~/.vim/pythonx` path, we can create module and import them in any snippet files.


