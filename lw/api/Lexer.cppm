module;

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

export module Lexer;
export import Token;

export class Lexer {
 public:
  explicit Lexer(std::string const &source = ""); ///< constructor
  ~Lexer();                                       ///< destructor

  [[nodiscard]] std::vector<Token> lex_tokens() const; ///< lex the source

  static std::unordered_map<std::string, Token_Type>
      keywords; ///< keyword lookup

 private:
  struct impl;
  std::unique_ptr<impl> pimpl; ///< pointer to implementation
};
