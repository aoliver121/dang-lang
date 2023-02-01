//
// Created by alexa on 1/31/2023.
//

#ifndef DANG_INIT_HPP
#define DANG_INIT_HPP

#include "../lexer_state.hpp"
#include "../lexer_states_context.hpp"

namespace dang::lexer_states {
    class init: public lexer_state {
    public:
        explicit init(lexer_states_context *context);
        void handle_char(char const *ch) override;
    };
}

#endif //DANG_INIT_HPP
