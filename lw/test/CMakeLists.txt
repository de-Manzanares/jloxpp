set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/test/lw)

add_executable(test-lexer)
target_sources(test-lexer
        PUBLIC
        ${PROJECT_SOURCE_DIR}/lw/test/lexer.cxx)
target_link_libraries(test-lexer
        PRIVATE
        _lw
        Catch2::Catch2WithMain)

include(CTest)
include(Catch)

add_test(NAME Test-Lexer COMMAND test-lexer)
