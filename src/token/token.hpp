// Created by aioli121 on 2/12/2023.

#pragma once

#include <string>

#include "token_type.hpp"

namespace dang {

    class token {
    public:
        explicit token(token_type const &type);
    private:
        token_type const type;
    };

    class token_with_text: public token {
    public:
        token_with_text(token_type const &type, std::string text);
    private:
        std::string const text;
    };

}
