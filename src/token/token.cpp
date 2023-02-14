// Created by aioli121 on 2/12/2023.

#include "token.hpp"

namespace dang {

    token::token(token_type const &type): type(type) {
        // nop
    }

    token_with_text::token_with_text(token_type const &type, std::string text): token(type), text(std::move(text)) {
        // nop
    }

}
