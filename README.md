# TextDictionary-ADT

## Overview

This project is a C++ implementation of a text dictionary abstract data type (ADT) that reads words from an input file, indexes them, and tracks their occurrences and line numbers. It involves custom implementations of various data structures, including linked lists, to manage words and line numbers. The project provides insights into C++ memory management, pointers, and basic data structures.

## Features

- **Indexed Word Dictionary**: Stores words, line numbers, and frequencies from the input text.
- **Custom Data Structures**: Uses linked lists and dynamic arrays for internal data management.
- **C++ Memory Management**: Demonstrates handling of pointers and dynamic memory.
- **Operator Overloading**: Supports intuitive syntax for interacting with data structures.
- **File Input and Output**: Reads from a file and outputs results in an organized format.

## Getting Started

### Prerequisites

- **C++ Compiler**: A C++11-compatible compiler.
- **CMake**: If using the provided CMakeLists.txt file.

### Building the Project

To compile the project using CMake:

```bash
mkdir build
cd build
cmake ..
make
