#include "Token.h"

#include <iostream>
#include <utility>

//***************** PRIVATE IMPLEMENTATION *************************************

struct Token::impl {
  impl(Token_Type const &type, std::string lexeme, Token_Value value,
       std::size_t const line)
      : _type(type), _lexeme(std::move(lexeme)), _value(std::move(value)),
        _line(line) {}

  Token_Type _type;    ///< type of token
  std::string _lexeme; ///< word
  Token_Value _value;  ///< value, if any e.g. true, false, 5, etc
  std::size_t _line;   ///< line it lives on
};

//***************** PUBLIC IMPLEMENTATION **************************************

/// constructor
Token::Token(Token_Type const &type, std::string const &lexeme,
             Token_Value const &value, std::size_t const line)
    : pimpl(std::make_shared<impl>(type, lexeme, value, line)) {}

/// destructor
Token::~Token() = default;

/// to string
std::string Token::to_string() const {
  std::string value;
  std::string const stringified =
      std::to_string(static_cast<std::size_t>(pimpl->_type)) + " " +
      pimpl->_lexeme;

  if (std::holds_alternative<std::string>(pimpl->_value)) {
    value = std::get<std::string>(pimpl->_value);
  }
  if (std::holds_alternative<double>(pimpl->_value)) {
    value = std::to_string(std::get<double>(pimpl->_value));
  }
  if (std::holds_alternative<bool>(pimpl->_value)) {
    std::get<bool>(pimpl->_value) == true ? value = "true" : value = "false";
  }

  return stringified + " " + value;
}

Token_Type Token::type() const { return pimpl->_type; }
