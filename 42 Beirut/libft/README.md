*This project has been created as part of the 42 curriculum by gbaghsar.*

## Description

This project consists of creating a custom C library `libft.a` that reimplements
commonly used standard C library functions. The goal is to gain a deeper
understanding of memory management, pointers, and library design in C.

### Library Description

The `libft` library is a static library that provides reimplementations
of essential functions from the C standard library, written from scratch.

The library provides reimplementations of standard C functions,
including:

- Memory handling (`ft_memset`, `ft_memcpy`, etc.)
- String manipulation (`ft_strlen`, `ft_strncmp`, etc.)
- Character checks (`ft_isalpha`, `ft_isdigit`, etc.)
- Linked list utilities

Each function follows the behavior defined in the POSIX standard
and includes error handling where applicable.

## Instructions

### Compilation

From the root of the repository, run:

```bash
make
```

This command compiles all source files and generates the static library
libft.a.

For additional commands, run:

```bash
make clean   – removes object files
make fclean  – removes object files and libft.a
make re      – rebuilds the library from scratch
```

### Usage

Include the library header in your source file:

```c
#include "libft.h"
```

Compile your program with the library:

```bash
cc {filename}.c libft.a
```

Then run the executable:

```bash
./a.out
```

## Resources

### References

- The C Programming Language – Kernighan & Ritchie
- GNU C Library Documentation
- man pages (`man malloc`, `man memcpy`, etc.)

### AI Usage

AI tools were used while working on this project to:

- Clarify edge cases related to standard C library behavior
- Review code logic for correctness and memory safety
- Assist in improving README clarity and structure
- Create mains for some of the functions

AI was not used to generate final implementations blindly; all code
was reviewed, adapted, and written intentionally by the author.

