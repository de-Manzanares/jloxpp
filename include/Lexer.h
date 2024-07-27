#ifndef INCLUDE_LEXER_H_
#define INCLUDE_LEXER_H_

#include "Token.h"

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

class Lexer {
 public:
  explicit Lexer(std::string const &source = ""); ///< constructor
  ~Lexer();                                       ///< destructor
  static std::unordered_map<std::string, Token_Type>
      keywords; ///< for keyword lookup

  //*************** PUBLIC METHODS *********************************************

  [[nodiscard]] std::vector<Token> lex_tokens() const; ///< lex the source

  //****************************************************************************

 private:
  struct impl;
  std::unique_ptr<impl> pimpl; ///< pointer to implementation
};

#endif // INCLUDE_LEXER_H_
