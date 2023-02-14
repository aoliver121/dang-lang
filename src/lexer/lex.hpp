// Created by aioli121 on 2/12/2023.

#pragma once

#include "token/token_stream.hpp"

namespace dang {

    token_stream lex(std::istream &input_stream);

}