// Created by aioli121 on 2/12/2023.

#include "token_stream.hpp"

namespace dang {

    token_stream::token_stream(std::initializer_list<token const *> raw_tokens): stream(raw_tokens.begin(), raw_tokens.end()) {
        // nop
    }

    void token_stream::add_token(std::unique_ptr<token> next_token) {
        stream.emplace_back(std::move(next_token));
    }
}
