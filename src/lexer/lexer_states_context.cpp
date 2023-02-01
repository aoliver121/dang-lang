//
// Created by alexa on 1/31/2023.
//

#include <iostream>
#include "lexer_states_context.hpp"

dang::lexer_states_context::lexer_states_context()
: current_state(&init)
, init(this)
, starts_with_char(this)
, whitespace(this) {
    std::cout << __PRETTY_FUNCTION__ << "\n";
}

void dang::lexer_states_context::handle_char(const char *ch) {
    std::cout << __PRETTY_FUNCTION__ << "ch=[" << (void *) ch << "]('" << *ch << "')\n";
    current_state->handle_char(ch);
}

void dang::lexer_states_context::change_state(lexer_state *new_state) {
    std::cout << __PRETTY_FUNCTION__ << " new_state=[" << new_state << "])\n";
    current_state = new_state;
}
