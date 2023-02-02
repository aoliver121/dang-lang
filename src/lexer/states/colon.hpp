//
// Created by alexa on 2/1/2023.
//

#ifndef DANG_COLON_HPP
#define DANG_COLON_HPP

#include "../lexer_state.hpp"
#include "../lexer_states_context.hpp"

namespace dang::lexer_states {
    class colon: public lexer_state {
    public:
        explicit colon(lexer_states_context *context);
    private:
        void add_token_to_stream();
        bool handle_letter(char const *letter_ptr) override;
        bool handle_whitespace(char const *whitespace_ptr) override;
        bool handle_colon() override;
    };
}

#endif //DANG_COLON_HPP
