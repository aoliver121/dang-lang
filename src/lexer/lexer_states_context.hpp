//
// Created by alexa on 1/31/2023.
//

#ifndef DANG_LEXER_STATES_CONTEXT_HPP
#define DANG_LEXER_STATES_CONTEXT_HPP

#include "lexer_state.hpp"
#include "states/init.hpp"
#include "states/starts_with_letter.hpp"
#include "states/whitespace.hpp"
#include "states/colon.hpp"

namespace dang {
    class lexer_states_context {
    public:
        lexer_states_context();
        void handle_char(char const *ch);
        void change_state(lexer_state *new_state);

        lexer_states::init init;
        lexer_states::starts_with_letter starts_with_letter;
        lexer_states::whitespace whitespace;
        lexer_states::colon colon;
    private:
        lexer_state *current_state;
    };
}

#endif //DANG_LEXER_STATES_CONTEXT_HPP
