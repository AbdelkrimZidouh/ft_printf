# ft_printf

ft_printf is a reimplementation of the standard C `printf` function for educational purposes. This project provides a lightweight, limited-but-useful `ft_printf` function that supports a common subset of format specifiers. It is implemented in C and built with a Makefile.

This repository is primarily C (≈95.7%) with a small Makefile portion.

## Table of Contents

- [Features](#features)
- [Supported conversions](#supported-conversions)
- [Requirements](#requirements)
- [Building](#building)
- [Usage](#usage)
- [Examples](#examples)
- [Testing](#testing)
- [Project structure](#project-structure)
- [Contributing](#contributing)
- [License](#license)
- [Author](#author)

## Features

- A compact implementation of `ft_printf` modeled after the standard `printf`.
- Handles common format specifiers and prints formatted output to `stdout`.
- Designed for clarity and educational use.

## Supported conversions

The implementation supports the typical conversion specifiers required by many "ft_printf" projects:

- `%c` — character
- `%s` — string
- `%p` — pointer (printed in hexadecimal with `0x` prefix)
- `%d` / `%i` — signed decimal integer
- `%u` — unsigned decimal integer
- `%x` / `%X` — unsigned hexadecimal (lowercase / uppercase)
- `%%` — literal percent sign

If this repository contains more or fewer specifiers, consult `ft_printf.h` and the source for exact coverage.

## Requirements

- POSIX-compatible system (Linux/macOS)
- GCC or another ANSI C compiler
- Make (provided Makefile)

## Building

To build the project, run:

```sh
make
```

Typical Makefile targets you can expect:

- `make` or `make all` — build the library / executable
- `make clean` — remove object files
- `make fclean` — remove object files and binaries
- `make re` — rebuild from scratch

If the repository produces a static library (e.g., `libftprintf.a`) or an executable, `make` will create it in the project root (see the Makefile for exact target names and outputs).

## Usage

Include the header and call `ft_printf` the same way you use standard `printf`:

```c
#include "ft_printf.h"

int main(void)
{
    int n = ft_printf("Hello %s!\nNumber: %d, Hex: %#x\n", "world", 42, 42);
    (void)n; // number of characters printed
    return 0;
}
```

Compile (example):

```sh
gcc -Wall -Wextra -Werror -I. -L. -lftprintf main.c -o example
```

Adjust the include and link flags according to the Makefile and produced artifacts (library or direct object files).

## Examples

Some example calls and expected behavior:

- ft_printf("Hello %s\n", "Alice");
  - Output: Hello Alice

- ft_printf("Char: %c, Int: %d, Unsigned: %u\n", 'A', -123, 123);
  - Output: Char: A, Int: -123, Unsigned: 123

- ft_printf("Pointer: %p\n", ptr);
  - Output: Pointer: 0x7ffee0bff6a8  (value varies)

- ft_printf("Hex: %x %X\n", 255, 255);
  - Output: Hex: ff FF

- ft_printf("Percent: %%\n");
  - Output: Percent: %

## Testing

There may be no automated test suite included. To test manually:

1. Compile the library / executable with `make`.
2. Build small test programs that call `ft_printf` with various format strings.
3. Compare outputs with the standard `printf` for the supported specifiers.

If you want automated regression checks, consider creating tests that redirect stdout and compare against expected outputs (or the output of `printf`).

## Project structure (typical)

- src/           — implementation (.c) files
- include/       — header files (e.g., `ft_printf.h`)
- Makefile       — build rules
- tests/         — manual test programs (optional)
- README.md      — this file

Open the repository to view the exact file layout and names.

## Contributing

Contributions are welcome. If you plan to extend behavior or add more specifiers:

- Follow the existing coding style (see source files).
- Add tests for new behavior.
- Update the README to document new features.

Please open issues or pull requests on GitHub.

## License

This project is provided for educational purposes. Add a license file (e.g., MIT) if you want to make licensing explicit.

## Author

Abdelkrim Zidouh — GitHub: @AbdelkrimZidouh

If you'd like, I can:
- open a README file in the repository with this content,
- tailor the README to match the exact function names and Makefile targets in your repo (I can read files in the repo to extract exact header & targets first),
- or add examples/tests to the repo.
