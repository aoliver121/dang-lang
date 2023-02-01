//
// Created by alexa on 1/31/2023.
//

#ifndef DANG_STARTS_WITH_CHAR_HPP
#define DANG_STARTS_WITH_CHAR_HPP

#include "../lexer_state.hpp"
#include "../lexer_states_context.hpp"

namespace dang::lexer_states {
    class starts_with_char: public lexer_state {
    public:
        explicit starts_with_char(lexer_states_context *context);
        void set(char const *start_pos);
    private:
        bool handle_letter(char const *letter_ptr) override;
        bool handle_whitespace(char const *whitespace_ptr) override;

        char const *start_pos;
    };
}

#endif //DANG_STARTS_WITH_CHAR_HPP
