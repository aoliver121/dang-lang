//
// Created by alexa on 1/31/2023.
//

#ifndef DANG_STARTS_WITH_LETTER_HPP
#define DANG_STARTS_WITH_LETTER_HPP

#include "../lexer_state.hpp"
#include "../lexer_states_context.hpp"

namespace dang::lexer_states {
    class starts_with_letter: public lexer_state {
    public:
        explicit starts_with_letter(lexer_states_context *context);
        void set(char const *start_pos);
    private:
        void add_token_to_stream();
        bool handle_letter(char const *letter_ptr) override;
        bool handle_whitespace(char const *whitespace_ptr) override;
        bool handle_colon() override;

        char const *start_pos;
    };
}

#endif //DANG_STARTS_WITH_LETTER_HPP
