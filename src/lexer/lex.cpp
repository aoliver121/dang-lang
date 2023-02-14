// Created by aioli121 on 2/12/2023.

#include "lex.hpp"
#include "context_and_state.hpp"

namespace dang {

    token_stream lex(std::istream &input_stream) {
        token_stream output_tokens;
        auto lexer_context = lexer::context(input_stream, output_tokens);
        lexer_context.run();
        return output_tokens;
    }

}