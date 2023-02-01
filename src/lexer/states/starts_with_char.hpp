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
        void handle_char(char const *ch) override;

        void set(char const *start_pos);
    private:
        char const *start_pos;
    };
}

#endif //DANG_STARTS_WITH_CHAR_HPP
