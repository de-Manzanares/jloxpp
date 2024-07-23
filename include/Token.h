#ifndef TOKEN_H
#define TOKEN_H

#include "TokenType.hpp"

#include <memory>

class Token {
 public:
  explicit Token(Token_Type const &type = Token_Type::NILL, ///< constructor
                 std::string const &lexeme = "",
                 std::string const &literal = "", std::size_t line = 0);
  ~Token(); ///< destructor

  //*************** PUBLIC METHODS *********************************************

  [[nodiscard]] std::string to_string() const; ///< stringify

  //****************************************************************************

 private:
  struct impl;
  std::shared_ptr<impl> pimpl; ///< pointer to implementation
};

#endif // TOKEN_H
