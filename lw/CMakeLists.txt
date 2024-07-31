add_library(_lw)
target_sources(_lw
        PUBLIC
        ${PROJECT_SOURCE_DIR}/lw/impl/Lexer.cpp
        ${PROJECT_SOURCE_DIR}/lw/impl/Lox.cpp
        ${PROJECT_SOURCE_DIR}/lw/impl/Token.cpp
        PUBLIC
        FILE_SET CXX_MODULES
        BASE_DIRS ${PROJECT_SOURCE_DIR}/lw/api
        FILES
        ${PROJECT_SOURCE_DIR}/lw/api/Lexer.cppm
        ${PROJECT_SOURCE_DIR}/lw/api/Lox.cppm
        ${PROJECT_SOURCE_DIR}/lw/api/Token.cppm
        ${PROJECT_SOURCE_DIR}/lw/api/TokenType.cppm)

add_executable(lw)
target_sources(lw
        PUBLIC
        ${PROJECT_SOURCE_DIR}/lw/impl/main.cpp)
target_link_libraries(lw _lw)
