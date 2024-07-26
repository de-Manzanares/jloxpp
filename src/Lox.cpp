#include "Lox.h"

#include "Lexer.h"

#include <iostream>
#include <vector>

//***************** PRIVATE IMPLEMENTATION *************************************

struct Lox::impl {
  /// we'll have to come back to this later
  static void run_file(std::string const &file) {
    std::cout << "running file: " << file << "\n";
    if (had_error) {
      exit(1);
    }
  }

  /// prompt the user and run the code
  /// @note repl doesn't count lines ... a newline character never makes it
  /// downstream
  static void run_prompt() {
    std::string const PROMPT = "lox> ";
    std::string line; // user input

    while (true) {
      std::cout << PROMPT;
      std::getline(std::cin, line);
      if (std::cin.eof()) { // "Ctrl + D", "Ctrl + Z"
        std::cout << '\n';
        break;
      }
      run(line);
      had_error = false; // reset error flag -- don't crash repl lol
    }
  }

  /// run the code
  static void run(std::string const &line) {
    Lexer lexer(line);

    // for now, just print the tokens
    for (std::vector<Token> const tokens = lexer.lex_tokens();
         auto const &token : tokens) {
      std::cout << token.to_string() << '\n';
    }
  }

  static void error(std::size_t const line, std::string const &message) {
    report(line, "", message);
  }

  static void report(std::size_t const line, std::string const &where,
                     std::string const &message) {
    std::cerr << "[line " + std::to_string(line) + "] Error" + where + ": " +
                     message;
    std::cerr << std::endl;
    had_error = true;
  }
};

//***************** PUBLIC IMPLEMENTATION **************************************

bool Lox::had_error = false;

Lox::Lox() : pimpl(std::make_unique<impl>()) {}

Lox::~Lox() = default;

int Lox::main(int const argc, char const *argv[]) const {
  if (argc > 2) {
    std::cout << "Usage: lox <script>\n";
    return 1;
  }
  if (argc == 2) {
    pimpl->run_file(argv[1]);
  } else if (argc == 1) {
    pimpl->run_prompt();
  }
  return 0;
}

/// for lower classes to report an error
void Lox::error(std::size_t const &line, std::string const &message) {
  impl::error(line, message);
}
