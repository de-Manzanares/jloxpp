#include "Lexer.h"

#include "Lox.h"

#include <iostream>
#include <utility>
#include <vector>

//***************** PRIVATE IMPLEMENTATION *************************************

class Token;

struct Lexer::impl {
  /// constructor
  explicit impl(std::string source) : _source(std::move(source)) {}

  std::string _source;        ///< source code
  std::vector<Token> _tokens; ///< list of tokens we have generated
  std::size_t _start{};       ///< start of current lexeme
  std::size_t _current{};     ///< character we are currently considering
  std::size_t _line = 1;      ///< line we are lexing

  /// tokenize a single word/lexeme
  void lex_token() {
    switch (char const ch = advance()) {
      using tt = Token_Type;
    case '(':
      add_token(tt::LEFT_PAREN);
      break; // single character
    case ')':
      add_token(tt::RIGHT_PAREN);
      break;
    case '{':
      add_token(tt::LEFT_BRACE);
      break;
    case '}':
      add_token(tt::RIGHT_BRACE);
      break;
    case ',':
      add_token(tt::COMMA);
      break;
    case '.':
      add_token(tt::DOT);
      break;
    case '-':
      add_token(tt::MINUS);
      break;
    case '+':
      add_token(tt::PLUS);
      break;
    case ';':
      add_token(tt::SEMICOLON);
      break;
    case '*':
      add_token(tt::STAR);
      break;
    case '!':
      add_token(match('=') ? tt::BANG_EQUAL : tt::BANG);
      break;
    case '=':
      add_token(match('=') ? tt::EQUAL_EQUAL : tt::EQUAL);
      break;
    case '<':
      add_token(match('=') ? tt::LESS_EQUAL : tt::LESS);
      break;
    case '>':
      add_token(match('=') ? tt::GREATER_EQUAL : tt::GREATER);
      break;
    case '/':
      if (match('/')) { // the beginning of a comment
        while (!is_at_end() && peek() != '\n') {
          advance();
        }
        break;
      }
    case ' ':
    case '\r':
    case '\t':
      break; // ignore whitespace
    case '\n':
      ++_line; // count lines
      break;
    case '"': // string literal
      string_literal();
      break;
    default:
      if (std::isdigit(ch)) { // numeric literal
        numeric_literal();
        break;
      }
      Lox::error(_line, "Unexpected character.");
      break;
    }
  }

  /// consume a character and return it
  char advance() { return _source[_current++]; }

  void add_token(Token_Type const &type) { add_token(type, ""); }

  void add_token(Token_Type const &type, Token_Value const &value) {
    std::string text = _source.substr(_start, _current - _start);
    _tokens.emplace_back(type, text, value, _line);
  }

  /// have we consumed all the characters?
  [[nodiscard]] bool is_at_end() const { return _current >= _source.size(); }

  /// purposefully avoids consuming newline so that our switch can catch it
  /// and count the line
  [[nodiscard]] char peek(std::size_t const distance_from_current = 0) const {
    if (is_at_end()) {
      return '\0';
    }
    return _source[_current + distance_from_current];
  }

  /// store the entire string as the value of the tt::STRING
  void string_literal() {
    while (!is_at_end() && peek() != '"') {
      if (peek() == '\n') {
        ++_line; // lox supports multiline strings lol
      }
      advance();
    }
    if (peek() == '"') {
      advance();
      std::string const _string_literal = _source.substr(
          _start + 1, _current - _start - 2); // don't include "'s
      add_token(Token_Type::STRING, _string_literal);
    } else if (is_at_end()) {
      Lox::error(_line, "Unterminated string.");
    } else if (peek() == '\0') {
      Lox::error(_line, "Missing quotation mark \"");
    }
  }

  /// store the numeric literal as the value of the tt:NUMBER
  void numeric_literal() {
    while (std::isdigit(peek())) {
      advance();
    }
    // permit one decimal, but not at the end of a number e.g. "158."
    if (peek() == '.' && std::isdigit(peek(1))) {
      advance();
      while (std::isdigit(peek())) {
        advance();
      }
    }
    double _numeric_literal =
        std::stod(_source.substr(_start, _current - _start));
    add_token(Token_Type::NUMBER, _numeric_literal);
  }

  /// is the next character what we expect it to be?
  bool match(char const expected) {
    if (is_at_end() || _source[_current] != expected) {
      return false;
    }
    ++_current;
    return true;
  }
};

//***************** PUBLIC IMPLEMENTATION **************************************

Lexer::Lexer(std::string const &source) ///< constructor
    : pimpl(std::make_unique<impl>(source)) {}

Lexer::~Lexer() = default; ///< destructor

std::vector<Token> Lexer::lex_tokens() const { ///< tokenize the source code
  while (!pimpl->is_at_end()) {
    pimpl->_start = pimpl->_current;
    pimpl->lex_token();
  }

  // final EOF token
  pimpl->_tokens.emplace_back(Token_Type::loxEOF, "", "", pimpl->_line);
  return pimpl->_tokens;
}
