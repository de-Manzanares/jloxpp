#ifndef INCLUDE_TOKEN_H_
#define INCLUDE_TOKEN_H_

#include "TokenType.hpp"

#include <memory>
#include <string>
#include <variant>

typedef std::variant<std::string, double, bool> Token_Value;

class Token {
 public:
  Token(Token_Type const &type, std::string const &lexeme, ///< constructor
        Token_Value const &value, std::size_t line);
  ~Token(); ///< destructor

  //*************** PUBLIC METHODS *********************************************

  [[nodiscard]] std::string to_string() const; ///< stringify
  [[nodiscard]] Token_Type type() const;       ///< @returns token type

  //****************************************************************************

 private:
  struct impl;
  std::shared_ptr<impl> pimpl; ///< pointer to implementation
};

#endif // INCLUDE_TOKEN_H_
