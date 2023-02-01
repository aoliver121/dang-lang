//
// Created by alexa on 1/31/2023.
//

#include <iostream>
#include "lexer.hpp"

dang::lexer::lexer(const char *text)
: text(text)
, context() {
    std::cout << __PRETTY_FUNCTION__ << " text=[" << (void *) text << "](\"" << text << "\")\n";
}

void dang::lexer::lex() {
    std::cout << __PRETTY_FUNCTION__ << "\n";
    for (char const *ch = text; ch && (*ch != '\0'); ch ++) {
        context.handle_char(ch);
    }
}
