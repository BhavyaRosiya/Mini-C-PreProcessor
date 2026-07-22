# Mini C Preprocessor in C

## Overview
This project implements a simplified version of the C preprocessor. It simulates some of the operations performed by the C compiler during the preprocessing stage before actual compilation.

The project is developed entirely in C using file handling, string manipulation, and modular programming techniques.

## Features
- Macro substitution using #define
- Function-like macro substitution
- Header file inclusion using #include
- Nested header file inclusion
- Comment removal
- Source code transformation before compilation
- Multi-file project structure
- Makefile support

- ## Technologies Used

- C Programming
- File Handling
- String Manipulation
- Dynamic Memory Management
- Multi-file Programming
- Makefile
- Git & GitHub

- ## Project Structure

```text
mini-c-preprocessor/
│
├── src/
│   ├── main.c
│   ├── macro.c
│   ├── include.c
│   ├── comment.c
│   └── utils.c
│
├── include/
│   └── preprocessor.h
│
├── input/
│   └── input.c
│
├── output/
│   └── output.i
│
├── Makefile
├── README.md
└── .gitignore
```
## How to Build
make

## How to Run
./exe input.c

**or**

```bash
./a.out input.c

*(Depending on your executable name.)*

## Supported Preprocessor Directives

| Directive | Supported |
|-----------|:---------:|
| `#define` | Yes |
| Macro without Arguments | Yes |
| `#include` | Yes |
| Nested Header Files | Yes |
| Comment Removal | Yes |

