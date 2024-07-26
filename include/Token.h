#ifndef INCLUDE_TOKEN_H_
#define INCLUDE_TOKEN_H_

#include "TokenType.hpp"

#include <memory>
#include <string>

class Token {
 public:
  explicit Token(Token_Type const &type = Token_Type::NILL, ///< constructor
                 std::string const &lexeme = "",
                 std::string const &literal = "", std::size_t line = 0);
  ~Token(); ///< destructor

  //*************** PUBLIC METHODS *********************************************

  [[nodiscard]] std::string to_string() const; ///< stringify
  [[nodiscard]] Token_Type type() const;

  //****************************************************************************

 private:
  struct impl;
  std::shared_ptr<impl> pimpl; ///< pointer to implementation
};

#endif // INCLUDE_TOKEN_H_
