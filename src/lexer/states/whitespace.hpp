//
// Created by alexa on 2/1/2023.
//

#ifndef DANG_WHITESPACE_HPP
#define DANG_WHITESPACE_HPP

#include "../lexer_state.hpp"
#include "../lexer_states_context.hpp"

namespace dang::lexer_states {
    class whitespace: public lexer_state {
    public:
        explicit whitespace(lexer_states_context *context);
        void handle_char(char const *ch) override;
    };
}

#endif //DANG_WHITESPACE_HPP
