//
// Created by alexa on 1/31/2023.
//

#include <iostream>
#include "../lexer_states_context.hpp"
#include "init.hpp"

dang::lexer_states::init::init(lexer_states_context *context)
: lexer_state(context) {
    std::cout << __PRETTY_FUNCTION__ << " context=[" << context << "]\n";
}

void dang::lexer_states::init::handle_char(char const *ch) {
    std::cout << __PRETTY_FUNCTION__ << " ch=[" << (void *) ch << "]('" << *ch << "')\n";
    char const &c = *ch;

    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '_') {
        auto &starts_with_char = context->starts_with_char;
        context->change_state(&starts_with_char);
        starts_with_char.set(ch);
        return;
    }

    std::cerr << "ERROR " << __PRETTY_FUNCTION__ << " No handler for char '" << *ch << "'\n";
    std::exit(1);
}
