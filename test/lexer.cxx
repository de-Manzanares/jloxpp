#include "Lexer.h"
#include "Token.h"
#include "TokenType.hpp"
#include <catch2/catch_all.hpp>

using tt = Token_Type;

std::vector<tt> extract_token_types(std::vector<Token> const &tokens) {
  std::vector<tt> token_types;
  token_types.reserve(tokens.size());
  for (auto const &token : tokens) {
    token_types.emplace_back(token.type());
  }
  return token_types;
}

std::unique_ptr<Lexer> lexer;
std::vector<Token> tokens;
std::vector<tt> tts;

bool test_tt(std::string const &test_input,
             std::vector<tt> const &expected_tts) {
  lexer = std::make_unique<Lexer>(test_input);
  tokens = lexer->lex_tokens();
  return expected_tts == extract_token_types(tokens);
}

/*
 *
 */
TEST_CASE("token types") {
  CHECK(test_tt("(", std::vector{tt::LEFT_PAREN, tt::loxEOF}));
  CHECK(test_tt(")", std::vector{tt::RIGHT_PAREN, tt::loxEOF}));
  CHECK(test_tt("{", std::vector{tt::LEFT_BRACE, tt::loxEOF}));
  CHECK(test_tt("}", std::vector{tt::RIGHT_BRACE, tt::loxEOF}));
  CHECK(test_tt(",", std::vector{tt::COMMA, tt::loxEOF}));
  CHECK(test_tt(".", std::vector{tt::DOT, tt::loxEOF}));
  CHECK(test_tt("-", std::vector{tt::MINUS, tt::loxEOF}));
  CHECK(test_tt("+", std::vector{tt::PLUS, tt::loxEOF}));
  CHECK(test_tt(";", std::vector{tt::SEMICOLON, tt::loxEOF}));
  CHECK(test_tt("/", std::vector{tt::SLASH, tt::loxEOF}));
  CHECK(test_tt("*", std::vector{tt::STAR, tt::loxEOF}));
  CHECK(test_tt("!", std::vector{tt::BANG, tt::loxEOF}));
  CHECK(test_tt("!=", std::vector{tt::BANG_EQUAL, tt::loxEOF}));
  CHECK(test_tt("=", std::vector{tt::EQUAL, tt::loxEOF}));
  CHECK(test_tt("==", std::vector{tt::EQUAL_EQUAL, tt::loxEOF}));
  CHECK(test_tt(">", std::vector{tt::GREATER, tt::loxEOF}));
  CHECK(test_tt(">=", std::vector{tt::GREATER_EQUAL, tt::loxEOF}));
  CHECK(test_tt("<", std::vector{tt::LESS, tt::loxEOF}));
  CHECK(test_tt("<=", std::vector{tt::LESS_EQUAL, tt::loxEOF}));
  CHECK(test_tt("identifier", std::vector{tt::IDENTIFIER, tt::loxEOF}));
  CHECK(test_tt("_identifier123_", std::vector{tt::IDENTIFIER, tt::loxEOF}));
  CHECK(test_tt("identi_f_ier123", std::vector{tt::IDENTIFIER, tt::loxEOF}));
  CHECK(test_tt("\"this is a string\"", std::vector{tt::STRING, tt::loxEOF}));
  CHECK(test_tt("\"2 line\nstring\"", std::vector{tt::STRING, tt::loxEOF}));
  CHECK(test_tt("7", std::vector{tt::NUMBER, tt::loxEOF}));
  CHECK(test_tt("72", std::vector{tt::NUMBER, tt::loxEOF}));
  CHECK(test_tt("72.876", std::vector{tt::NUMBER, tt::loxEOF}));
  CHECK(test_tt("and", std::vector{tt::AND, tt::loxEOF}));
  CHECK(test_tt("class", std::vector{tt::CLASS, tt::loxEOF}));
  CHECK(test_tt("else", std::vector{tt::ELSE, tt::loxEOF}));
  CHECK(test_tt("false", std::vector{tt::FALSE, tt::loxEOF}));
  CHECK(test_tt("fun", std::vector{tt::FUN, tt::loxEOF}));
  CHECK(test_tt("for", std::vector{tt::FOR, tt::loxEOF}));
  CHECK(test_tt("if", std::vector{tt::IF, tt::loxEOF}));
  CHECK(test_tt("nil", std::vector{tt::NIL, tt::loxEOF}));
  CHECK(test_tt("or", std::vector{tt::OR, tt::loxEOF}));
  CHECK(test_tt("print", std::vector{tt::PRINT, tt::loxEOF}));
  CHECK(test_tt("return", std::vector{tt::RETURN, tt::loxEOF}));
  CHECK(test_tt("super", std::vector{tt::SUPER, tt::loxEOF}));
  CHECK(test_tt("this", std::vector{tt::THIS, tt::loxEOF}));
  CHECK(test_tt("true", std::vector{tt::TRUE, tt::loxEOF}));
  CHECK(test_tt("var", std::vector{tt::VAR, tt::loxEOF}));
  CHECK(test_tt("while", std::vector{tt::WHILE, tt::loxEOF}));
}
