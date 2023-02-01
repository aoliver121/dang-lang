//
// Created by alexa on 1/31/2023.
//

#include <iostream>
#include "../lexer_states_context.hpp"
#include "starts_with_char.hpp"

dang::lexer_states::starts_with_char::starts_with_char(lexer_states_context *context)
: lexer_state(context) {
    std::cout << __PRETTY_FUNCTION__ << " context=[" << context << "]\n";
    start_pos = nullptr;
}

void dang::lexer_states::starts_with_char::handle_char(const char *ch) {
    std::cout << __PRETTY_FUNCTION__ << " ch=[" << (void *) ch << "]('" << *ch << "')\n";
    char const &c = *ch;

    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '_') {
        return;
    }

    switch (c) {
        case ' ':
            // TODO Append id token to stream

            auto &whitespace = context->whitespace;
            context->change_state(&whitespace);
            return;
    }

    std::cerr << "ERROR " << __PRETTY_FUNCTION__ << " No handler for char '" << *ch << "'\n";
    std::exit(1);
}

void dang::lexer_states::starts_with_char::set(const char *start_pos_) {
    std::cout << __PRETTY_FUNCTION__ << " start_pos=[" << (void *) start_pos_ << "] ('" << *start_pos_ << "')\n";
    start_pos = start_pos_;
}
