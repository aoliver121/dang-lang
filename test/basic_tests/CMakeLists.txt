# Created by aioli121 on 2/10/2023.

include_directories(
        ${gtest_src_dir}/include
        ${gtest_src_dir}
)

set(src_files
        lexer_test_1.cpp
        ../../src/token/token.cpp
        ../../src/token/token_factory.cpp
        ../../src/token/token_stream.cpp
        ../../src/lexer/lex.cpp
        ../../src/lexer/context_and_state.cpp)

add_executable(Run_Basic_Dang_Tests ${src_files})

target_link_libraries(Run_Basic_Dang_Tests gtest gtest_main)
