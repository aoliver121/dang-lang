//
// Created by alexa on 1/31/2023.
//

#include <iostream>
#include "../lexer_states_context.hpp"
#include "starts_with_letter.hpp"

dang::lexer_states::starts_with_letter::starts_with_letter(lexer_states_context *context)
: lexer_state(context) {
    std::cout << "\t" << __PRETTY_FUNCTION__ << "\tthis=[" << this << "], context=[" << context << "]\n";
    start_pos = nullptr;
}

void dang::lexer_states::starts_with_letter::add_token_to_stream() {
    // TODO
}

void dang::lexer_states::starts_with_letter::set(const char *start_pos_) {
    std::cout << __PRETTY_FUNCTION__ << "\tstart_pos=[" << (void *) start_pos_ << "] ('" << *start_pos_ << "')\n";
    start_pos = start_pos_;
}

bool dang::lexer_states::starts_with_letter::handle_letter(const char *letter_ptr) {
    std::cout << "\t" << __PRETTY_FUNCTION__ << "\tletter_ptr=[" << (void *) letter_ptr << "]('" << *letter_ptr << "')\n";

    // maintain state

    return true;
}

bool dang::lexer_states::starts_with_letter::handle_whitespace(const char *whitespace_ptr) {
    std::cout << "\t" << __PRETTY_FUNCTION__ << "\twhitespace_ptr=[" << (void *) whitespace_ptr << "]('" << *whitespace_ptr << "')\n";

    add_token_to_stream();

    auto &whitespace = context->whitespace;
    context->change_state(&whitespace);

    return true;
}

bool dang::lexer_states::starts_with_letter::handle_colon() {
    std::cout << "\t" << __PRETTY_FUNCTION__ << "\n";

    add_token_to_stream();

    auto &colon = context->colon;
    context->change_state(&colon);

    return true;
}