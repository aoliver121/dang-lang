//
// Created by alexa on 1/31/2023.
//

#include <iostream>
#include "../lexer_states_context.hpp"
#include "init.hpp"

dang::lexer_states::init::init(lexer_states_context *context)
: lexer_state(context) {
    std::cout << "\t" << __PRETTY_FUNCTION__ << "\tthis=[" << this << "], context=[" << context << "]\n";
}

bool dang::lexer_states::init::handle_letter(const char *letter_ptr) {
    std::cout << "\t" << __PRETTY_FUNCTION__ << "\tletter_ptr=[" << (void *) letter_ptr << "]('" << *letter_ptr << "')\n";

    auto &starts_with_char = context->starts_with_char;
    context->change_state(&starts_with_char);
    starts_with_char.set(letter_ptr);

    return true;
}

bool dang::lexer_states::init::handle_whitespace(const char *whitespace_ptr) {
    std::cout << "\t" << __PRETTY_FUNCTION__ << "\twhitespace_ptr=[" << (void *) whitespace_ptr << "]('" << *whitespace_ptr << "')\n";

    // nop

    return true;
}

