set(CMAKE_CXX_STANDARD 23)

find_package(Catch2 3 QUIET)

if (Catch2_FOUND)

    add_executable(test-lexer
            lexer.cxx
            ../src/Token.cpp
            ../src/Lexer.cpp
            ../src/Lox.cpp)
    target_include_directories(test-lexer PRIVATE ../include)
    target_link_libraries(test-lexer PRIVATE Catch2::Catch2WithMain)

    include(CTest)
    include(Catch)

    add_test(NAME Test-Lexer COMMAND test-lexer)

endif ()
