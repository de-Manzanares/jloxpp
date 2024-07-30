<div align="center">

## jloxpp (WIP)

</div>

A C++ implementation of the tree-walking interpreter for the "Lox" programming language from
*Crafting Interpreters* by Robert Nystrom.

For more information on [*Crafting
Interpreters*](https://craftinginterpreters.com/), visit [Bob Nystrom's repository](https://github.com/munificent/craftinginterpreters) which "contains the Markdown text of the book, [and] full implementations of both interpreters."

### In contrast with the original implementation:

- Identifiers may begin with, include, and end with any number of underscores.
    - This includes identifiers consisting entirely of underscores. Fun, huh?


- This implementation is not actually complete.

### Compiling

This project uses C++20 language features, the most compiler-restrictive of which being modules.
This project has been successfully compiled with: 

- Clang 18.1.8
- MSVC 19.40

For information on compiler support for C++ language features, see the 
[C++ compiler support](https://en.cppreference.com/w/cpp/compiler_support) page from 
[cppreference](https://en.cppreference.com/w/).
