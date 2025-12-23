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
- [Testing](#testing)
- [Contributing](#contributing)
- [License](#license)
- [Author](#author)

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
  - Length modifiers beyond the typical int/unsigned long handling required for the supported specifiers
- Behavior for edge cases follows the implementation choices in source — consult the source files for exact behavior.

If you plan to extend support (flags, width, precision, locale-aware formatting), please add tests and document the changes in this README.

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

## Testing

There is no automated test suite included by default. Suggested manual test approach:

1. Build the library/executable with `make`.
2. Create small test programs that call `ft_printf` with a variety of format strings and arguments.
3. Compare the output and return values with the standard `printf` for the supported specifiers.
   - A simple script that compiles and runs both the standard printf version and the ft_printf version and diffs their outputs is helpful.
4. Add unit tests or small programs to exercise edge cases: large integers, zero, negative numbers, NULL pointers for `%s`, etc.

If you add automated tests (make a `tests/` directory or use a testing framework), please include instructions to run them in this README.

## Contributing

Contributions are welcome. If you want to extend `ft_printf` or improve the project:

- Follow the existing coding style visible in the source files.
- Add tests that cover new behavior and edge cases.
- Update this README to document features you add (flags, width, precision, new specifiers).
- Open a pull request with a clear description of the changes and why they're needed.

Guidelines:
- Keep functions small and well-documented.
- Ensure code compiles with `-Wall -Wextra -Werror`.
- Prefer clarity and correctness over clever but opaque solutions.

## License

Specify a license for the repository if you want others to reuse or contribute. If you do not currently have a license, consider adding one (for example, MIT or BSD). Without an explicit license, reuse is restricted.

## Author

Abdelkrim Zidouh — GitHub: @AbdelkrimZidouh

---

If you'd like, I can:
- Tailor this README to be more concise or more detailed.
- Add a "How it works" section explaining the implementation approach.
- Produce example test programs and a small test script that diffs output against the system printf.

Which of these would you like next?
