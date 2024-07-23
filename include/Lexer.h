#ifndef LEXER_H
#define LEXER_H

#include "Token.h"

#include <memory>
#include <vector>

class Lexer {
 public:
  explicit Lexer(std::string const &source = ""); ///< constructor
  ~Lexer();                                       ///< destructor

  //*************** PUBLIC METHODS *********************************************

  [[nodiscard]] std::vector<Token> lex_tokens() const; ///< lex the source

  //****************************************************************************

 private:
  struct impl;
  std::unique_ptr<impl> pimpl; ///< pointer to implementation
};

#endif // LEXER_H
