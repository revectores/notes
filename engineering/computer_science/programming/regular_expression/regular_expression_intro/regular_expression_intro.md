# Regular Expression

### 1. Core Syntax

##### # Basic Concept

**Regular expression(regex, re)** is the universal tool to match or replace text with specific pattern. The pattern is constructed by symbols based on some rules, stipulated by the syntax of regular expression. The universality and power has been proved since almost all the modern programming language has implemented the regular expression even its superset. Although the details of syntax might vary across programming languages, the rules of constructing patterns are unitive.

This document introduces the universal syntax of regular expression, you can refer to the notes about regular expression library in concerned programming languages for the language-specific syntax.

One should notice that some syntax only match **THE FIRST** text which meets the pattern, while other match **ALL** the substrings. Furthermore, some languages provide special machanism about precise control, such as specifying whether to ignore cases, match multilines, include special character sets, and so on. Most of the special mechanism are irrelavent to the core syntax of regular expression itself, while specified by specific languages respectively. For example, in Python we'll use `re.search` method to find the first matched substring, while use `re.findall` method to find all the matched substrings.



##### # Match Text

To match the text itself, i.e. the word `word`, just construct pattern as the text itself, that is, `word`. Notice that the regular expression is case sensitive by default, but as mentioned, we can set some option provided by the programming language interface to make the matching case-insensitive.

Some special characters/strings are reserved for constructing pattern, called **metacharacter**, for example, the dot `.` represents "any character", `\w` represent "letter or number". If the text happen to contain the metacharacters, a backslash `\` should be used to escape them, including the backslash itself.

Two approaches are introduced to match the non-printable characters:

- Use the ASCII code, octal and hexadecimal are both supported. For example, `\x0A` and `\012` represents `\r`, `\x09` and `\011` represents `\t`.
- Use the metacharacter.

    | Metacharacter |   Description   | Equivalent HEX Value |
    | :-----------: | :-------------: | :------------------: |
    |     `\t`      | Horizontal Tab  |        `\x09`        |
    |     `\f`      |    Form Feed    |        `\x12`        |
    |     `\n`      |    Line Feed    |        `\x0A`        |
    |     `\v`      |  Vertical Tab   |        `\x0B`        |
    |     `\r`      | Carriage Return |        `\x0D`        |
    
    

##### # Match Character Set

We can construct a **character set** using `[]`, to match any single character in this set. For example, set `[Ww]` will match the upper case or lower case `w`. hyphen `-` is supported to create **character interval** based on the **ASCII code order**, for example `[a-f] == [abcdef]`, `[0-5] = [012345]`. One common error is trying `[A-z]` to match all letters but actually there are six symbols between `Z` and `a` in ASCII table, the correct solution is `[A-Za-z]`, no extra symbol is needed between the two intervals.

By adding not symbol `^`, we could inverse the semantics of character set, that is, only those characters **NOT** in the character set will be matched.

Character `-` and `^` are special special metacharacter, which work as the metacharacter only inside the square brackets, hence there's no necessary to escape them outside the square brackets. On the contrary, other metacharacter only represents itself inside the square brackets, such as `.`, `\d`.

Notice that in the strict syntax of regular expression, for one of the paired meta characters, including single `[` or `]`, is still requires to be escaped, while this is not necessary for most of the modern implementations.



##### # Metacharacter of Character Set

Some metacharacters are provided to simplify the expression of common character set:

| Metacharacter |              Description              | Equivalent Character Interval |
| :-----------: | :-----------------------------------: | :---------------------------: |
|      `.`      |      Any character, except `\n`       |            `[^\n]`            |
|     `\d`      |              Any number               |            `[0-9]`            |
|     `\w`      | Any valid variable name (for most PL) |        `[0-9A-Za-z_]`         |
|     `\s`      |          Any blank character          |        `[\f\n\r\t\v]`         |
|      \D       |               Not `\d`                |           `[^0-9]`            |
|     `\W`      |               Not `\w`                |        `[^0-9A-Za-z_]`        |
|     `\S`      |               Not `\s`                |        `[^\f\n\r\t\v]`        |

Since the metacharacter `.` does not match LF, to match the REAL anycharacter, use pair of the counterparts instead: `[\s\S]`, `[\w\W]`, `[\d\D]`, which will pair all the characters.

[POSIX character class](POSIX_character_class.md) can be regarded as special metacharacters representing range, but this is not supported in all the programming languages.



##### # Match Repeatedly

Use paired brace to specify the repeat count/range to match the repeated pattern: `#[0-9A-Za-z]{6}` matches a RGB color value, `https{0, 1}` for TLS or not, and `ba{2, }!` for all the valid word in sheep' language.

There are equivalent metacharacters for special ranges:

| Metacharacter | Equivalent |
| :-----------: | :--------: |
|      `?`      |  `{0, 1}`  |
|      `*`      |  `{0, }`   |
|      `+`      |  `{1, }`   |



##### # Greedy Mode and Lazy Mode





