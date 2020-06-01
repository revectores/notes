# x86 Assembly Basic

### File Extension

Captial extension `.S` represents the assembly language file that still needs to be passed into a preprocessor, i.e. contains `include` command, denoted as `.sx` also, while `.s` represnts the pure assembly code that can be complied into object file (`.o` file) directly.



### Register

**Register** is the variable of CPU, but other than variable in the programming language, register used specific name to play specific function.

`ax, bx, cx, dx` and their extention are the most common-used register, which are assigned as the special function respectically:

- `ax`: **accumulator register**, used to store the middle result of sum or product.
- `bx`: **base register**, used to store the base address during the memory addressing process.
- `cx`: **counter register**, as the counter in `rep` and `loop` instruction.
- `dx`: **remainder register**, used to store the remainder of the integer division

`ax, bx, cx, dx` represent 16-bit register, each of them can be devided to the low bits parts (0~7 bits) and high bits part (8~15 bits), called `al` and `ah` for `ax` and similarly for the rest. The extended 32-bit `eax, ebx, ecx, edx` are most famous register in modern 32-bit machine, and 64-bit `rax, rbx, rcx, rdx`.







### Instruction

##### mov

Four types of `mov` instruction included: `movb, movw, movl, movq`.

- `movb`: move 1 bytes (8-bit).
- `movw`: move 1 word (2 bytes, 16-bit).
- `movl`: move 1 `long`, (2 words, 4 bytes, 32-bit)
- `movq`: move quad-words (4 words, 8 bytes ,64-bit).

Four typical usage of `mov`:

- Transfer value between register.

    ```assembly
    movl %eax, %edx;
    ```

    Notice that this operation means `%eax->%edx`, i.e. `%edx=%eax`, instead of vice versa.

- Assign a constant into the register

    ```assembly
    movl 0x0000ffff, %edx;
    ```

- 





# Unittest For x86 Assembly Basic

1. What's the difference between `.S` file and `.s` file?
2. Explain the usage of following register: `ax, bx, cx, dx`.
3. Explain the difference among `ax, eax, rax`.
4. Give the four types of `mov` instruction.

