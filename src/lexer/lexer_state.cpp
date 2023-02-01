//
// Created by alexa on 1/31/2023.
//

#include <iostream>
#include "lexer_state.hpp"

dang::lexer_state::lexer_state(lexer_states_context *context)
: context(context) {
    std::cout << __PRETTY_FUNCTION__ << " context=[" << context << "]\n";
}

void dang::lexer_state::handle_char(const char *ch) {
    std::cout << __PRETTY_FUNCTION__ << " ch=[" << (void *) ch << "]('" << *ch << "')\n";
    // TODO

    std::cerr << "ERROR " << __PRETTY_FUNCTION__ << " No handler for char '" << *ch << "'\n";
    std::exit(1);
}
