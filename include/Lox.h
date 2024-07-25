#ifndef INCLUDE_LOX_H_
#define INCLUDE_LOX_H_

#include <memory>
#include <string>

/*
 * @brief Implementation of the lox language
 */
class Lox {
 public:
  Lox();                 ///< constructor
  ~Lox();                ///< destructor
  static bool had_error; ///< error flag

  //*************** PUBLIC METHODS *********************************************

  /**
   * @brief Main entry \n
   * Usage: lox <filename> // runs file \n
   *        lox // runs repl
   */
  int main(int argc, char const *argv[]) const;

  static void error(std::size_t const &line, std::string const &message);
  //****************************************************************************

 private:
  struct impl;
  std::unique_ptr<impl> pimpl; ///< pointer to implementation
};

#endif // INCLUDE_LOX_H_
