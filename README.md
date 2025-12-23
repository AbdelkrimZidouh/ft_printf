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

- ft_printf("Hex: %x %X\n", 255, 255);
  - Output: Hex: ff FF

- ft_printf("Percent: %%\n");
  - Output: Percent: %





