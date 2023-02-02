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
        bool handle_letter(const char *letter_ptr) override;
        bool handle_whitespace(const char *whitespace_ptr) override;
        bool handle_colon() override;
    };
}

#endif //DANG_WHITESPACE_HPP
