# C++ `bitset`

##### # Initialization

1. `bitset<n> b`: Initialize a bitset with length `n` and filled with 0.

2. `bitset<n> b(u)`: Initialize bitset `b` by `unsigned long long u`. If `n` exceeds the bits of `unsigned long long` (that is, exceeds 64), those high bits will be filled with 0.

3. `bitset<n> b(s, pos, m, zero, one)`: Initialize bitset `b` by `string s`, starting from `pos`, with length `m`. `s` can only contain `zero` an `one`.

    By default `pos` is 0, `pos` is `std::string::npos`, and `zero/one` are `'0'` and `'1'` respectively.

4. `bitset<n> b(cp, pos, m, zero, one)`: Similar to (3) but given a character array instead of `std::string`. If `m` is not given, `cp` must points to a C-style array, that is, the tailing `\0` must exist.



##### # C++ `bitset` Non-modification Method

| Method                              | Interpretation                                               |
| ----------------------------------- | ------------------------------------------------------------ |
| `b.any()`                           | if any bit is 1                                              |
| `b.any()`                           | if all bits are 1                                            |
| `b.none()`                          | if all bits are 0                                            |
| `b.count()`                         | count number of 1                                            |
| `b.size()`                          | count total bits                                             |
| `b.test(pos)`                       | if position `pos` is 1                                       |
| `b[pos]`                            | Access position `pos`.                                       |
| `b.to_ulong()`<br />`b.to_ullong()` | return a `unsigned long` value<br />or `unsigned long long` value |
| `b.to_string(zero, one)`            | return a string. `zero`/`one` are `0`/`1` by default         |



##### # C++ `bitset` Modification Method

| Method                          | Interpretation                                               |
| ------------------------------- | ------------------------------------------------------------ |
| `b.set(pos, v)`<br />`b.set()`  | set `pos` to `v`, `v=true` by default.<br />If no `pos` given, set all to 1. |
| `b.reset(pos)`<br />`b.reset()` | set pos to 0.<br />If not `pos` given, set all to 0.         |
| `os << b`                       | print `b` as 0/1 string.                                     |
| `is >> b`                       | read character 0/1 into `b`, <br />stop reading if the next character is not 0/1<br />or there is no enough space in `b`. |







