// Created by aioli121 on 2/12/2023.

#pragma once

#include "token.hpp"

namespace dang::token_factory {

    std::unique_ptr<token_with_text> new_identifier(std::string text);
    std::unique_ptr<token_with_text> new_integer(std::string text);

    std::unique_ptr<token> new_colon();
    std::unique_ptr<token> new_equals();
    std::unique_ptr<token> new_semicolon();
    std::unique_ptr<token> new_open_parenthesis();
    std::unique_ptr<token> new_close_parenthesis();
    std::unique_ptr<token> new_open_curly_bracket();
    std::unique_ptr<token> new_close_curly_bracket();
    std::unique_ptr<token> new_right_arrow();

}
