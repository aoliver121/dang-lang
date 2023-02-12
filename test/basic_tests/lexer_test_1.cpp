// Created by aioli121 on 2/10/2023.

#include "gtest/gtest.h"
#include "basic_header.hpp"

TEST(LexerTest, EnsureCorrectLexerResultOfSample1) {
    auto const input_text = "main := () -> exit_code: int32 { exit_code = 169; };";
    auto input_stream = std::istringstream(input_text);

    auto expected_output = dang::token_stream();
    expected_output.add_token(std::make_unique<dang::tokens::identifier>("main"));
    expected_output.add_token(std::make_unique<dang::tokens::colon>());
    expected_output.add_token(std::make_unique<dang::tokens::equals>());
    expected_output.add_token(std::make_unique<dang::tokens::open_parenthesis>());
    expected_output.add_token(std::make_unique<dang::tokens::close_parenthesis>());
    expected_output.add_token(std::make_unique<dang::tokens::right_arrow>());
    expected_output.add_token(std::make_unique<dang::tokens::identifier>("exit_code"));
    expected_output.add_token(std::make_unique<dang::tokens::colon>());
    expected_output.add_token(std::make_unique<dang::tokens::identifier>("int32"));
    expected_output.add_token(std::make_unique<dang::tokens::open_curly_bracket>());
    expected_output.add_token(std::make_unique<dang::tokens::identifier>("exit_code"));
    expected_output.add_token(std::make_unique<dang::tokens::equals>());
    expected_output.add_token(std::make_unique<dang::tokens::integer>("169"));
    expected_output.add_token(std::make_unique<dang::tokens::semicolon>());
    expected_output.add_token(std::make_unique<dang::tokens::close_curly_bracket>());
    expected_output.add_token(std::make_unique<dang::tokens::semicolon>());

    auto const actual_output = dang::lex(input_stream);

    ASSERT_TRUE(actual_output.equals(expected_output));
}
