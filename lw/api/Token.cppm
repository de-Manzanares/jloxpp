module;

#include <memory>
#include <string>
#include <utility>
#include <variant>

export module Token;
export import Token_Type;

export typedef std::variant<std::string, double, bool> Token_Value;

export class Token {
 public:
  Token(Token_Type const &type, std::string const &lexeme, ///< constructor
        Token_Value const &value, std::size_t line);
  ~Token(); ///< destructor

  [[nodiscard]] std::string to_string() const; ///< stringify
  [[nodiscard]] Token_Type type() const;       ///< @returns token type

 private:
  struct impl;
  std::shared_ptr<impl> pimpl; ///< pointer to implementation
};
