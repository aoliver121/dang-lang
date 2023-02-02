//
// Created by alexa on 2/1/2023.
//

#include <iostream>
#include "../lexer_states_context.hpp"
#include "whitespace.hpp"

dang::lexer_states::whitespace::whitespace(dang::lexer_states_context *context)
: lexer_state(context) {
    std::cout << "\t" << __PRETTY_FUNCTION__ << "\tthis=[" << this << "], context=[" << context << "]\n";
}

bool dang::lexer_states::whitespace::handle_letter(const char *letter_ptr) {
    std::cout << "\t" << __PRETTY_FUNCTION__ << "\tletter_ptr=[" << (void *) letter_ptr << "]('" << *letter_ptr << "')\n";

    auto &starts_with_letter = context->starts_with_letter;
    context->change_state(&starts_with_letter);
    starts_with_letter.set(letter_ptr);

    return true;
}

bool dang::lexer_states::whitespace::handle_whitespace(const char *whitespace_ptr) {
    std::cout << "\t" << __PRETTY_FUNCTION__ << "\twhitespace_ptr=[" << (void *) whitespace_ptr << "]('" << *whitespace_ptr << "')\n";

    // maintain state

    return true;
}

bool dang::lexer_states::whitespace::handle_colon() {
    std::cout << "\t" << __PRETTY_FUNCTION__ << "\n";

    auto &colon = context->colon;
    context->change_state(&colon);

    return true;
}
