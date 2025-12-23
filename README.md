*This project has been created as part of the 42 curriculum by azidouh*

# ft_printf

ft_printf is an educational reimplementation of the standard C `printf` function. It provides a compact, easy-to-read implementation that supports a useful subset of format specifiers commonly required in small projects and learning exercises.

This repository is primarily C (≈95.7%) and includes a Makefile to build the library/executable.

## Table of contents

- [Features](#features)
- [Supported conversions](#supported-conversions)
- [Limitations](#limitations)
- [Requirements](#requirements)
- [Build](#build)
- [Usage](#usage)
- [Examples](#examples)
- [Algorithm and Data Structure Explanation](#algorithm-and-data-structure-explanation)
- [Resources](#resources)


## Features

- Small, readable implementation of `ft_printf` for educational purposes.
- Prints formatted output to `stdout`.
- Returns the number of characters printed (same convention as `printf`).

## Supported conversions

The implementation supports the common conversion specifiers used in many "ft_printf" projects:

- `%c` — character
- `%s` — string (prints `(null)` or empty string depending on implementation if pointer is NULL)
- `%p` — pointer (printed as hexadecimal with `0x` prefix)
- `%d` / `%i` — signed decimal integer
- `%u` — unsigned decimal integer
- `%x` / `%X` — unsigned hexadecimal (lowercase / uppercase)
- `%%` — literal percent sign

## Limitations

- This implementation focuses on the core specifiers listed above. It may not support:
  - All flags (`-`, `+`, ` `, `0`, `#`)
  - Field width or precision handling for every specifier
  - Behavior for edge cases follows the implementation choices in source — consult the source files for exact behavior.


## Requirements

- POSIX-compatible system (Linux/macOS)
- C compiler (GCC or compatible)
- Make (project includes a Makefile)

## Build

To build the project:

```sh
make
```

Common Makefile targets:

- `make` or `make all` — build the library / executable
- `make clean` — remove object files
- `make fclean` — remove object files and binaries
- `make re` — rebuild from scratch

Example compile command for a test program using the produced library or object files:

```sh
cc -Wall -Wextra -Werror main.c libftprintf.a
```

(Adjust the link line if your Makefile produces different artifacts, e.g., a static library or an object file.)

## Usage

Include the public header and call `ft_printf` similarly to the standard `printf`:

```c
#include "ft_printf.h"

int main(void)
{
    int printed = ft_printf("Hello %s!\nNumber: %d, Hex: %x\n", "world", 42, 42);
    (void)printed; /* printed holds the number of characters output */
    return 0;
}
```

ft_printf returns the number of characters printed (or a negative value on error depending on implementation details in the source).

## Examples

- ft_printf("Hello %s\n", "Alice");
  - Output: Hello Alice

- ft_printf("Char: %c, Int: %d, Unsigned: %u\n", 'A', -123, 123);
  - Output: Char: A, Int: -123, Unsigned: 123

- ft_printf("Pointer: %p\n", ptr);
  - Output: Pointer: 0x7ffee0bff6a8 (actual value will vary)

## Algorithm and Data Structure Explanation

### Overview

The `ft_printf` implementation follows a simple yet efficient parsing and dispatch algorithm. The core logic consists of three main components:

1. **Main parser** (`ft_printf`)
2. **Format specifier dispatcher** (`ft_print_formatted`)
3. **Output functions** (various `ft_put*` functions)

### Algorithm Flow

```
ft_printf(format, ...)
    │
    ├─ Initialize va_list for variadic arguments
    │
    ├─ Iterate through format string
    │   │
    │   ├─ Regular character?  → Print directly with ft_putchar
    │   │
    │   └─ Found '%'? → Call ft_print_formatted with next character
    │       │
    │       └─ Dispatch based on specifier: 
    │           ├─ 'c' → ft_putchar(char)
    │           ├─ 's' → ft_putstr(char *)
    │           ├─ 'p' → ft_putptr(void *)
    │           ├─ 'd'/'i' → ft_putnbr_base(int, "0123456789")
    │           ├─ 'u' → ft_putnbr_base(unsigned, "0123456789")
    │           ├─ 'x' → ft_putnbr_base(unsigned, "0123456789abcdef")
    │           ├─ 'X' → ft_putnbr_base(unsigned, "0123456789ABCDEF")
    │           └─ '%' → ft_putchar('%')
    │
    └─ Return total characters printed
```

### Key Data Structures

#### 1. **va_list** (from `<stdarg.h>`)
The implementation uses the standard C variadic argument mechanism: 
- `va_start(args, fmt)` — Initialize argument pointer
- `va_arg(args, type)` — Extract next argument of specified type
- `va_end(args)` — Clean up argument list


## Resources

### Official Documentation

#### C Standard Library
- [printf man page](https://man7.org/linux/man-pages/man3/printf.3.html) - Complete reference for printf format specifiers
- [stdarg. h man page](https://man7.org/linux/man-pages/man3/stdarg.3.html) - Variadic function documentation
- [C99 Standard - 7.19.6.1](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n1256.pdf) - Official fprintf specification (PDF)

### Variadic Functions

- [GNU C Manual: Variadic Functions](https://www.gnu.org/software/libc/manual/html_node/Variadic-Functions.html)
- [cppreference: Variadic Functions](https://en.cppreference.com/w/c/variadic)
- [Learn C:  Variable Arguments](https://www.learn-c.org/en/Variable_Arguments)

**Key concepts covered in implementation:**
- `va_list` type for argument list
- `va_start(ap, last_arg)` - initialize argument pointer
- `va_arg(ap, type)` - retrieve next argument
- `va_end(ap)` - cleanup

### Number Base Conversion

- [GeeksforGeeks: Base Conversion](https://www.geeksforgeeks.org/convert-base-decimal-vice-versa/)
- [Khan Academy: Number Systems & Base Conversion](https://www.khanacademy.org/computing/computer-science/algorithms/algorithms-more-learning/a/number-bases)
- [Binary to Hexadecimal Conversion](https://www.rapidtables.com/convert/number/binary-to-hex.html)

**Relevant to:**
- `ft_putnbr_base()` - converts numbers to any base (decimal, hex, etc.)
- `ft_puthex()` - specialized hexadecimal conversion for pointers

### Format Specifiers

- [printf Format Specifiers Cheatsheet](https://alvinalexander.com/programming/printf-format-cheat-sheet/)
- [Format Specifiers in C](https://www.geeksforgeeks.org/format-specifiers-in-c/)
- [C printf Format Reference](https://cplusplus.com/reference/cstdio/printf/)

**Implemented specifiers:**
- `%c` - character
- `%s` - string
- `%p` - pointer
- `%d`, `%i` - signed decimal
- `%u` - unsigned decimal
- `%x`, `%X` - hexadecimal

### Recursion

- [Recursion in C](https://www.geeksforgeeks.org/recursion-in-c/)
- [Understanding Recursion](https://www.freecodecamp.org/news/understanding-recursion-in-programming/)

**Used in:**
- `ft_putnbr_base()` - recursive digit printing
- `ft_puthex()` - recursive hexadecimal conversion

### Memory and Pointers

- [Pointers in C](https://www.geeksforgeeks.org/c-pointers/)
- [Understanding Pointer Arithmetic](https://www.learncpp.com/cpp-tutorial/pointer-arithmetic-and-array-indexing/)
- [stdint.h Types](https://en.cppreference.com/w/c/types/integer) - `uintptr_t`, `unsigned long` for pointer conversion

**Relevant to:**
- `ft_putptr()` - printing pointer addresses
- Proper casting:  `void*` → `unsigned long`

### Testing Resources

- [42 File Checker](https://github.com/jgigault/42FileChecker) - Automated testing for 42 projects
- [ft_printf_tester](https://github.com/Tripouille/printfTester) - Community printf tester
- [printf-unit-test](https://github.com/cacharle/ft_printf_test) - Another popular tester

### 42 Network Resources

- [42 Docs - ft_printf](https://harm-smits.github.io/42docs/projects/ft_printf) - Project guide
- [42 Evaluators Guide](https://github.com/Binary-Hackers/42_Subjects) - Subject PDFs

### Additional Learning

- [Write system call](https://man7.org/linux/man-pages/man2/write.2.html) - Low-level output function used in implementation
- [ASCII Table](https://www.asciitable.com/) - Character reference for `%c` specifier
- [Two's Complement](https://www.cs.cornell.edu/~tomf/notes/cps104/twoscomp.html) - Understanding negative number representation

### Related 42 Projects

Building on ft_printf skills: 
- **ft_printf** ← *You are here*
- **get_next_line** - File reading with static variables
- **push_swap** - Algorithm optimization
- **pipex** - Process management and pipes

