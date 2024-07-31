<div align="center">

## lw-lm

</div>

`lw` - Lox Walker - A C++ implementation of the tree-walking interpreter for the
"Lox" programming language from *Crafting Interpreters* by Robert Nystrom.

`lm` - Lox Machine - A C++ implementation of the bytecode virtual machine for the
"Lox" programming language from *Crafting Interpreters* by Robert Nystrom.

For more information on
[*Crafting Interpreters*](https://craftinginterpreters.com/),
visit [Bob Nystrom's repository](https://github.com/munificent/craftinginterpreters)
which "contains the Markdown text of the book, [and] full implementations of both interpreters."

### Project Structure

```
.
├── lm            // lox machine (coming soon)
├
├── lw            // lox walker (work in progress)
│   ├── api           // module interface files
│   ├── impl          // module implementation files
│   └── test          // tests 
```

### Build From Source

#### Prerequisites

This project uses C++20 language features, the most tool-restrictive of which
being modules. To build this project from source, one would need:

- CMake version 3.28 or greater.
- Ninja version 1.11 or greater.
- A compiler with C++20 module support.
    - This author has used Clang 18.1.8 and MSVC 19.40

If you have Catch2 version 3 on your system, the tests will be built as well.

For information on compiler support for C++ language features, see the
[C++ compiler support](https://en.cppreference.com/w/cpp/compiler_support) page from
[cppreference](https://en.cppreference.com/w/).

#### Command Line Interface

```bash
git clone https://github.com/de-Manzanares/lw-lm.git
cd lw-lm
cmake -B build -G Ninja -D CMAKE_BUILD_TYPE=Release
ninja -C build -v
```

If the compilers found by CMake don't support modules, you may specify the
compilers to be used by replacing the above cmake command with

```bash
cmake -B build -G Ninja -D CMAKE_BUILD_TYPE=Release -D CMAKE_C_COMPILER=path/to/your/C/compiler -D CMAKE_CXX_COMPILER=path/to/your/C++/compiler
```

#### Integrated Development Environment

As an alternative, if you have an IDE with CMake support, you may clone the repository and select
the CMake targets from within the IDE. 

