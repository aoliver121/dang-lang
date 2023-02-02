//
// Created by alexa on 1/31/2023.
//

#include <iostream>
#include "lexer_states_context.hpp"

dang::lexer_states_context::lexer_states_context()
: current_state(&init)
, init(this)
, starts_with_letter(this)
, whitespace(this)
, colon(this) {
    std::cout << __PRETTY_FUNCTION__ << "\tthis=[" << this << "]\n";
}

void dang::lexer_states_context::handle_char(const char *char_ptr) {
    std::cout << __PRETTY_FUNCTION__ << "\tchar_ptr=[" << (void *) char_ptr << "]('" << *char_ptr << "')\n";
    current_state->handle_char(char_ptr);
}

void dang::lexer_states_context::change_state(lexer_state *new_state) {
    std::cout << __PRETTY_FUNCTION__ << "\tnew_state=[" << new_state << "])\n";
    current_state = new_state;
}
