# Created by aioli121 on 2/10/2023.

include_directories(
        ${gtest_src_dir}/include
        ${gtest_src_dir}
)

add_executable(Run_Basic_Dang_Tests
        lexer_test_1.cpp)

target_link_libraries(Run_Basic_Dang_Tests gtest gtest_main)
