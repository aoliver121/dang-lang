#include <iostream>

#include "lexer/lexer.hpp"

int main() {
    char const *text = "main := () { built_in_print(\"Hello, world!\"); };";
    dang::lexer lexer(text);
    lexer.lex();
    std::cout << "Finished dang::lexer::lex()";
    return 0;
}
