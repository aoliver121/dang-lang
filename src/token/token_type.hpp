// Created by aioli121 on 2/12/2023.

#pragma once

namespace dang {

    enum class token_type {
        invalid,

        identifier,
        integer,

        colon,
        equals,
        semicolon,

        open_parenthesis,
        close_parenthesis,
        open_curly_bracket,
        close_curly_bracket,

        right_arrow,
    };

}
