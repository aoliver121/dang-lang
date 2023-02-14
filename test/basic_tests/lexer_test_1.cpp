// Created by aioli121 on 2/10/2023.

#include "gtest/gtest.h"

#include "lexer/lex.hpp"
#include "token/token_factory.hpp"
#include "token/token_stream.hpp"

TEST(Lexer, EnsureCorrectLexerResultOfSample1) {
    auto const input_text = "main := () -> exit_code: int32 { exit_code = 169; };";
    auto input_stream = std::istringstream(input_text);

    using namespace dang::token_factory;
    auto const expected_output = dang::token_stream {
        new_identifier("main").release(),
        new_colon().release(),
        new_equals().release(),
        new_open_parenthesis().release(),
        new_close_parenthesis().release(),
        new_right_arrow().release(),
        new_identifier("exit_code").release(),
        new_colon().release(),
        new_identifier("int32").release(),
        new_open_curly_bracket().release(),
        new_identifier("exit_code").release(),
        new_equals().release(),
        new_integer("169").release(),
        new_semicolon().release(),
        new_close_curly_bracket().release(),
        new_semicolon().release()
    };

    auto const actual_output = dang::lex(input_stream);

//    ASSERT_TRUE(actual_output.equals(expected_output));
// TODO
}
