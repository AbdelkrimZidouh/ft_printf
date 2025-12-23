*This project has been created as part of the 42 curriculum by azidouh*

# ft_printf

ft_printf is an educational reimplementation of the standard C `printf` function. It provides a compact, easy-to-read implementation that supports a useful subset of format specifiers commonly require[...]

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
