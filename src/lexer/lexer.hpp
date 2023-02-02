//
// Created by alexa on 1/31/2023.
//

#ifndef DANG_LEXER_HPP
#define DANG_LEXER_HPP

#include "lexer_states_context.hpp"

namespace dang {
    // Lexes, sexes, and otherwise, perplexes
    class lexer {
    public:
        explicit lexer(char const *text);
        void lex();
    private:
        char const *text;
        lexer_states_context context;
    };
}

#endif //DANG_LEXER_HPP
