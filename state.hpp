//
// Created by alexa on 1/21/2023.
//

#ifndef DANG_STATE_HPP
#define DANG_STATE_HPP

#include "error.hpp"

class state {
    void handleAsciiChar(char ch) {
        if ((ch >= 'a' && ch <= 'z') || (ch == '_') || (ch >= 'A' && ch <= 'Z')) {
            handleLetter(ch);
            return;
        }
        switch (ch) {
            case ' ':
            case '\n':
            case '\t':
            case '\r':
                handleWhitespace();
                return;

            case ':':   handleColon();          return;
            case '=':   handleEquals();         return;
            case '(':   handleOpenParen();      return;
            case ')':   handleCloseParen();     return;
            case '{':   handleOpenCurly();      return;
            case '"':   handleDoubleQuote();    return;
            case ';':   handleSemicolon();      return;
            case '}':   handleCloseCurly();     return;
        }

        error("Failed to handle Ascii char", LEX_NO_CHAR_HANDLER);
    }

    virtual void handleLetter(char letter);
    virtual void handleWhitespace();
    virtual void handleColon();
    virtual void handleEquals();
    virtual void handleOpenParen();
    virtual void handleCloseParen();
    virtual void handleOpenCurly();
    virtual void handleDoubleQuote();
    virtual void handleSemicolon();
    virtual void handleCloseCurly();
};

#endif //DANG_STATE_HPP
