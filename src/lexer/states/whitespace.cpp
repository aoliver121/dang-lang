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
