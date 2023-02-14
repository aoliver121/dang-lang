// Created by aioli121 on 2/12/2023.

#pragma once

#include "token.hpp"

namespace dang {

    class token_stream {
    public:
        token_stream() = default;
        token_stream(std::initializer_list<token const *> raw_tokens);
        void add_token(std::unique_ptr<token> next_token);
    private:
        std::vector<std::unique_ptr<token const>> stream;
    };

}
