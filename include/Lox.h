#ifndef INCLUDE_LOX_H_
#define INCLUDE_LOX_H_

#include <memory>

/*
 * @brief Implementation of the lox language
 */
class Lox {
 public:
  /**
   * @brief Main entry
   * Usage: lox <filename> // runs file \n
   *        lox // runs repl
   */
  int main(int argc, char const *argv[]) const;
  Lox();  ///< constructor
  ~Lox(); ///< destructor

 private:
  struct impl;
  std::unique_ptr<impl> pimpl; ///< pointer to implementation
};

#endif // INCLUDE_LOX_H_
