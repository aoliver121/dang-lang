//
// Created by alexa on 1/31/2023.
//

#ifndef DANG_LEXER_STATE_HPP
#define DANG_LEXER_STATE_HPP

namespace dang {
    class lexer_states_context;

    class lexer_state {
    public:
        explicit lexer_state(lexer_states_context *context);
        virtual void handle_char(char const *ch) = 0;
//    protected:
        lexer_states_context *context;
    };
}

#include "lexer_states_context.hpp"

#endif //DANG_LEXER_STATE_HPP
