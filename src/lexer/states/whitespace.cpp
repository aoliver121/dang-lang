//
// Created by alexa on 2/1/2023.
//

#include <iostream>
#include "../lexer_states_context.hpp"
#include "whitespace.hpp"

dang::lexer_states::whitespace::whitespace(dang::lexer_states_context *context)
: lexer_state(context) {
    std::cout << __PRETTY_FUNCTION__ << " context=[" << context << "]\n";
}

void dang::lexer_states::whitespace::handle_char(const char *ch) {
    std::cout << __PRETTY_FUNCTION__ << " ch=[" << (void *) ch << "]('" << *ch << "')\n";

    std::cerr << "ERROR " << __PRETTY_FUNCTION__ << " No handler for char '" << *ch << "'\n";
    std::exit(1);
}
