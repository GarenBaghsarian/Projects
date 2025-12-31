_This project has been created as part of the 42 curriculum by gbaghsar._

# ft_printf

## Description

The **ft_printf** project consists of reimplementing a simplified version of the C standard library function `printf`.  
The goal is to gain a deeper understanding of **variadic functions**, **format parsing**, **type handling**, and **low-level output management** in C.

This implementation supports a subset of the original `printf` format specifiers and reproduces its behavior as closely as possible while respecting the constraints of the 42 curriculum.

## Supported Conversions

- `%c` : single character
- `%s` : string (as defined by the common C convention)
- `%p` : void \* pointer argument has to be printed in hexadecimal format
- `%d` / `%i` : a decimal/integer (base 10) number
- `%u` : unsigned decimal (base 10) number
- `%x` : hexadecimal (base 16) lowercase format
- `%X` : hexadecimal (base 16) uppercase format
- `%%` : percent sign

## Instructions

### Compilation

Compile the library using:

```bash
make
```

This will generate a static library named `libftprintf.a`.

### Usage

Include the header and link the library when compiling your program:

```c
#include "ft_printf.h"
```

```bash
gcc main.c libftprintf.a
```

Example usage:

```c
ft_printf("Pointer address: %p\n", ptr);
ft_printf("Number: %d, Hex: %x\n", 42, 42);
```

## Algorithm and Data Structure Explanation

### Overall Approach

The implementation follows these main steps:

1. **Format String Parsing**
   The format string is scanned character by character.

   - If a normal character is encountered, it is printed directly.
   - If a `%` is found, the following character determines the conversion type.

2. **Variadic Argument Handling**
   The `stdarg.h` macros (`va_start`, `va_arg`, `va_end`) are used to retrieve arguments dynamically based on the detected conversion specifier.

3. **Dispatcher Logic**
   Each format specifier is mapped to a dedicated function (`ft_putchar`, `ft_putstr`, `ft_putnbr`, `ft_putptr`, etc.), ensuring modular and readable code.

### Pointer Conversion (`%p`)

- The pointer is cast to an **unsigned integer type large enough to store an address**.
- The value is printed in hexadecimal using a recursive base conversion.
- A `"0x"` prefix is added to match the behavior of the standard `printf`.
- A null pointer prints `(nil)`.

This approach avoids undefined behavior while remaining compatible with both 32-bit and 64-bit architectures.

### Data Structures

- **No dynamic data structures** (lists, trees, etc.) are required.
- The project relies on:

  - Recursive functions for number-to-string conversion.
  - Simple counters to track the number of printed characters.
  - Stack-based recursion for hexadecimal output.

This keeps memory usage minimal and predictable.

## Resources

### Documentation & References

- `man printf`
- `man stdarg`
- GNU C Library documentation
- cppreference.com (printf & variadic functions)

### AI Usage

AI tools were used **strictly for learning and clarification purposes**, including:

- Understanding variadic functions and format parsing
- Debugging type conversion and pointer-related issues
- Improving code readability and correctness
- Providing all the edge cases to ensure compatibility with `printf`

All implementation decisions, debugging, and final code writing were done manually.

## Notes

- This project respects all 42 constraints (no forbidden functions, no global variables).
- Behavior was tested against the official testers and compared with the system `printf`.
