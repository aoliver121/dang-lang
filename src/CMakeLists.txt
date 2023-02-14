# Created by aioli121 on 2/10/2023.

set(src_files
        main.cpp
        token/token.cpp
        token/token_factory.cpp
        token/token_stream.cpp
        lexer/lex.cpp lexer/context_and_state.cpp)

add_executable(Dang ${src_files})