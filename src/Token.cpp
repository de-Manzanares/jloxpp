#include "Token.h"

#include <iostream>
#include <utility>

//***************** PRIVATE IMPLEMENTATION *************************************

struct Token::impl {
  impl(Token_Type const &type, std::string lexeme, std::string literal,
       std::size_t const line)
      : _type(type), _lexeme(std::move(lexeme)), _literal(std::move(literal)),
        _line(line) {}

  Token_Type _type;     ///< type of token
  std::string _lexeme;  ///< word
  std::string _literal; ///< value, if any e.g. true, false, 5, etc
  std::size_t _line;    ///< line it lives on
};

//***************** PUBLIC IMPLEMENTATION **************************************

/// constructor
Token::Token(Token_Type const &type, std::string const &lexeme,
             std::string const &literal, std::size_t const line)
    : pimpl(std::make_shared<impl>(type, lexeme, literal, line)) {}

/// destructor
Token::~Token() = default;

/// to string
std::string Token::to_string() const {
  return std::to_string(static_cast<std::size_t>(pimpl->_type)) + " " +
         pimpl->_lexeme + pimpl->_literal;
}
