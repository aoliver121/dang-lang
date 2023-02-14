// Created by aioli121 on 2/12/2023.

#pragma once

#include <istream>

#include "token/token_stream.hpp"

namespace dang::lexer {

    class context;

    class state {
    public:
        void handle_next_chars();
        explicit state(context &context);
    protected:
        // Loops through characters that maintain the state. Ret
        virtual int state_maintenance_loop();
        virtual void add_relevant_token(int next_char_as_int);
        
        context &context;
    };

    namespace states {

        class close_curly_bracket: public state {
        public:
            using state::state;
            void add_relevant_token(int next_char_as_int) override;
        };

        class close_parenthesis: public state {
        public:
            using state::state;
            void add_relevant_token(int next_char_as_int) override;
        };

        class colon: public state {
        public:
            using state::state;
            void add_relevant_token(int next_char_as_int) override;
        };

        class dash_branch: public state {
        public:
            using state::state;
            void add_relevant_token(int next_char_as_int) override;
        };

        class eof: public state {
        public:
            using state::state;
        };

        class equals_branch: public state {
        public:
            using state::state;
            void add_relevant_token(int next_char_as_int) override;
        };

        class letters: public state {
        public:
            using state::state;
            void add_relevant_token(int next_char_as_int) override;
        };

        class number_branch: public state {
        public:
            using state::state;
            void add_relevant_token(int next_char_as_int) override;
        };

        class open_curly_bracket: public state {
        public:
            using state::state;
            void add_relevant_token(int next_char_as_int) override;
        };

        class open_parenthesis: public state {
        public:
            using state::state;
            void add_relevant_token(int next_char_as_int) override;
        };

        class right_arrow: public state {
        public:
            using state::state;
            void add_relevant_token(int next_char_as_int) override;
        };

        class semicolon: public state {
        public:
            using state::state;
            void add_relevant_token(int next_char_as_int) override;
        };

        class whitespace: public state {
        public:
            using state::state;
        };

    }

    class state_manager {
    public:
        explicit state_manager(context &context);
        state_manager(state_manager const &) = delete;
        state_manager &operator=(state_manager const &) = delete;

        bool is_not_eof();
        state *get_current_state();
    private:
        state *current_state;

        states::close_curly_bracket close_curly_bracket_state;
        states::close_parenthesis close_parenthesis_state;
        states::colon colon_state;
        states::dash_branch dash_branch_state;
        states::eof eof_state;
        states::equals_branch equals_branch_state;
        states::letters letters_state;
        states::number_branch number_branch_state;
        states::open_curly_bracket open_curly_bracket_state;
        states::open_parenthesis open_parenthesis_state;
        states::right_arrow right_arrow_state;
        states::semicolon semicolon_state;
        states::whitespace whitespace_state;
    };

    class context {
    public:
        explicit context(std::istream &input_stream, token_stream &tokens);
        int get_next_char_as_int();
        void run();
        void add_token_to_stream(std::unique_ptr<token> next_token);
        state_manager &get_state_manager();
        std::string get_buffer_as_string();
    private:
        state_manager states;
        std::istream &input_stream;
        token_stream &tokens;
        std::vector<char> buffer;
    };

}