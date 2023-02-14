// Created by aioli121 on 2/12/2023.

#include "token_factory.hpp"

namespace dang::token_factory {

    std::unique_ptr<token_with_text> new_identifier(std::string text) {
        return std::make_unique<token_with_text>(token_type::identifier, std::move(text));
    }

    std::unique_ptr<token_with_text> new_integer(std::string text) {
        return std::make_unique<token_with_text>(token_type::integer, std::move(text));
    }

    std::unique_ptr<token> new_colon() {
        return std::make_unique<token>(token_type::colon);
    }

    std::unique_ptr<token> new_equals() {
        return std::make_unique<token>(token_type::equals);
    }

    std::unique_ptr<token> new_semicolon() {
        return std::make_unique<token>(token_type::semicolon);
    }

    std::unique_ptr<token> new_open_parenthesis() {
        return std::make_unique<token>(token_type::open_parenthesis);
    }

    std::unique_ptr<token> new_close_parenthesis() {
        return std::make_unique<token>(token_type::close_parenthesis);
    }

    std::unique_ptr<token> new_open_curly_bracket() {
        return std::make_unique<token>(token_type::open_curly_bracket);
    }

    std::unique_ptr<token> new_close_curly_bracket() {
        return std::make_unique<token>(token_type::close_curly_bracket);
    }

    std::unique_ptr<token> new_right_arrow() {
        return std::make_unique<token>(token_type::right_arrow);
    }

}
