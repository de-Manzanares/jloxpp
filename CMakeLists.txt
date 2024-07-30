cmake_minimum_required(VERSION 3.28)
project(jloxpp)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_VERBOSE_MAKEFILE)

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Werror -Og -fprofile-arcs -ftest-coverage --coverage")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -O3 -DNDEBUG -flto=full -march=native")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fuse-ld=lld")

elseif (CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Og -fprofile-arcs -ftest-coverage --coverage")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -O3 -DNDEBUG -flto=full -march=native")

elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Werror -Og -fprofile-arcs -ftest-coverage --coverage")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -O3 -DNDEBUG -flto=auto -march=native")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fuse-linker-plugin")

elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set(CMAKE_CXX_FLAGS_DEBUG " ${CMAKE_CXX_FLAGS} /W4 /Od /Zi /MDd")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} /W4 /O2 /GL /MD")
    set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} /LTCG")
    set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "${CMAKE_SHARED_LINKER_FLAGS_RELEASE} /LTCG")
endif ()

add_executable(lox)

target_sources(lox PUBLIC
        ${PROJECT_SOURCE_DIR}/src/Lexer.cpp
        ${PROJECT_SOURCE_DIR}/src/Lox.cpp
        ${PROJECT_SOURCE_DIR}/src/main.cpp
        ${PROJECT_SOURCE_DIR}/src/Token.cpp
        PUBLIC
        FILE_SET CXX_MODULES
        FILES
        ${PROJECT_SOURCE_DIR}/include/Lexer.cppm
        ${PROJECT_SOURCE_DIR}/include/Lox.cppm
        ${PROJECT_SOURCE_DIR}/include/Token.cppm
        ${PROJECT_SOURCE_DIR}/include/TokenType.cppm
)

enable_testing()
include(CTest)

# add_subdirectory(test)
