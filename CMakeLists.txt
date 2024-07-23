cmake_minimum_required(VERSION 3.28)
project(jloxpp)

set(CMAKE_CXX_STANDARD 23)

add_executable(lox
        src/main.cpp
        src/Lox.cpp
        src/Token.cpp
        src/Lexer.cpp)
target_include_directories(lox PRIVATE include)
