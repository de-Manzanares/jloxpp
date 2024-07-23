#include "Lox.h"

#include <iostream>

struct Lox::impl {
  /// we'll have to come back to this later
  static void run_file(std::string const &file) {
    std::cout << "running file: " << file << "\n";
  }

  /// workin on this for now
  static void run_prompt() {
    std::string const PROMPT = "lox> ";
    std::string line; // user input

    while (true) {
      std::cout << PROMPT;
      std::getline(std::cin, line);
      if (std::cin.eof()) { // "Ctrl + D"
        break;
      }
      run(line);
    }
  }

  static void run(std::string const &line) {
    std::cout << "Your line said: " << line << "\n";
  }
};

Lox::Lox() : pimpl(std::make_unique<impl>()) {}
Lox::~Lox() = default;

int Lox::main(int const argc, char const *argv[]) const {
  if (argc > 2) {
    std::cout << "Usage: jlox <script>\n";
    return 1;
  }
  if (argc == 2) {
    pimpl->run_file(argv[1]);
  } else if (argc == 1) {
    pimpl->run_prompt();
  }
  return 0;
}
