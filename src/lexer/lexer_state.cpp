//
// Created by alexa on 1/31/2023.
//

#include <iostream>
#include "lexer_state.hpp"

dang::lexer_state::lexer_state(lexer_states_context *context)
: context(context) {
    std::cout << __PRETTY_FUNCTION__ << "\tthis=[" << this << "], context=[" << context << "]\n";
}

void dang::lexer_state::handle_char(const char *char_ptr) {
    char const c = *char_ptr; // AIOLI - I assume copying to the stack is faster than using a reference.

    std::cout << __PRETTY_FUNCTION__ << "\tchar_ptr=[" << (void *) char_ptr << "]('" << c << "')\n";

    bool handled;

    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '_') {
        handled = handle_letter(char_ptr);
        if (handled) {
            return;
        }
    }

    switch (c) {
        // TODO add more whitespace chars
        case ' ':
            handled = handle_whitespace(char_ptr);
            if (handled) {
                return;
            }
            break;
        case ':':
            handled = handle_colon();
            if (handled) {
                return;
            }
            break;

    }

    std::cerr << "ERROR " << __PRETTY_FUNCTION__ << "\tNo handler for char '" << *char_ptr << "'\n";
    std::exit(1);
}

bool dang::lexer_state::handle_letter(const char *letter_ptr) {
    return false;
}

bool dang::lexer_state::handle_whitespace(const char *whitespace_ptr) {
    return false;
}

bool dang::lexer_state::handle_colon() {
    return false;
}
