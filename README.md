# Task Manager CLI

A lightweight, CLI task management utility(to-do list) written in C++20. 
---

## Features

- **Interactive REPL Interface**: Stream-safe command loop with input validation (handles buffer overflow and invalid input cleanly).
- **Aligned ASCII Table View**: Formatted terminal output using standard I/O manipulators (`<iomanip>`) with ANSI escape colors for priority tiers (High, Medium, Low).
- **Flexible Sorting**: Sort tasks (dynamically) by priority or completion status using strict weak ordering.
- **Persistent Storage**: Automatic CSV file persistence saved directly to the user's home directory (`~/.tasks.csv`), enabling execution from any working directory.
- **Automated Testing Suite**:  Unit test coverage powered by Catch2 v3.
- **System-Wide Installation**: Native CMake installation target for Linux environments.

---

## Tech Stack & Architecture

- **Language**: Modern C++ (C++20)
- **Compiler**: GCC / Clang
- **Build System**: CMake ($\ge$ 3.20)
- **Test Framework**: Catch2 (fetched automatically via CMake `FetchContent`)

### Project Layout

```text
task_manager/
├── CMakeLists.txt         # Modular build config (core lib, CLI, tests, install)
├── include/
│   ├── Task.hpp           # Data structures, enums, serialization signatures
│   └── TaskManager.hpp    # Business logic & vector storage API
├── src/
│   ├── Task.cpp           # Parsing, string transformations, serialization
│   ├── TaskManager.cpp    # CRUD operations, sorting, ASCII formatting
│   └── main.cpp           # CLI interactive loop & application lifecycle
└── tests/
    └── test_main.cpp      # Automated Catch2 unit tests
