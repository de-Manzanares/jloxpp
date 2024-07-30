module;

#include <memory>
#include <string>

export module Lox;
import Lexer;

/*
 * @brief Implementation of the lox language
 */
export class Lox {
 public:
  Lox();                 ///< constructor
  ~Lox();                ///< destructor
  static bool had_error; ///< error flag

  /**
   * @brief Main entry \n
   * Usage: lox <filename> // runs file \n
   *        lox // runs repl
   */
  int main(int argc, char const *argv[]) const;

  static void error(std::size_t const &line, std::string const &message);

 private:
  struct impl;
  std::unique_ptr<impl> pimpl; ///< pointer to implementation
};
