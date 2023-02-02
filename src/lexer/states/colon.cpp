//
// Created by alexa on 2/1/2023.
//

#include <iostream>
#include "../lexer_states_context.hpp"
#include "colon.hpp"

dang::lexer_states::colon::colon(dang::lexer_states_context *context)
: lexer_state(context) {
    std::cout << "\t" << __PRETTY_FUNCTION__ << "\tthis=[" << this << "], context=[" << context << "]\n";
}

void dang::lexer_states::colon::add_token_to_stream() {
    // TODO
}

bool dang::lexer_states::colon::handle_letter(const char *letter_ptr) {
    std::cout << "\t" << __PRETTY_FUNCTION__ << "\tletter_ptr=[" << (void *) letter_ptr << "]('" << *letter_ptr << "')\n";

    add_token_to_stream();

    auto &whitespace = context->whitespace;
    context->change_state(&whitespace);

    return true;
}

bool dang::lexer_states::colon::handle_whitespace(const char *whitespace_ptr) {
    std::cout << "\t" << __PRETTY_FUNCTION__ << "\twhitespace_ptr=[" << (void *) whitespace_ptr << "]('" << *whitespace_ptr << "')\n";

    add_token_to_stream();

    auto &whitespace = context->whitespace;
    context->change_state(&whitespace);

    return true;
}

bool dang::lexer_states::colon::handle_colon() {
    std::cout << "\t" << __PRETTY_FUNCTION__ << "\n";

    add_token_to_stream();

    // maintain state

    return true;
}
