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




### Testing Resources
- [Francinette]([https://github.com/xicodomingues/francinette]) - popular tester


