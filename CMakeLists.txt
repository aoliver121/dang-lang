cmake_minimum_required(VERSION 3.24)
project(Dang)

set(CMAKE_CXX_STANDARD 23)

add_executable(Dang src/main.cpp src/lexer/lexer.cpp src/lexer/lexer_states_context.cpp src/lexer/lexer_state.cpp src/lexer/states/init.cpp src/lexer/states/starts_with_char.cpp src/lexer/states/whitespace.cpp)
