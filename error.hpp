//
// Created by alexa on 1/21/2023.
//

#ifndef DANG_ERROR_HPP
#define DANG_ERROR_HPP

#include <string>
#include <iostream>

void error(std::string description, int error_code) {
    std::cerr << description;
    std::exit(error_code);
}

#define LEX_ERROR_MIN       (1000)
#define LEX_NO_CHAR_HANDLER (1001)
#define LEX_ERROR_MAX       (1999)

#endif //DANG_ERROR_HPP
