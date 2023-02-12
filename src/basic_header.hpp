// Created by aioli121 on 2/10/2023.

#pragma once

#include <string>
#include <memory>
#include <vector>
#include <format>

namespace dang {

    namespace util {

        // Returns one static instance of the empty string for usage where a const reference to "" is needed
        std::string const &get_static_empty_string() {
            static std::string const empty;
            return empty;
        }

        bool is_whitespace(int some_char) {
            return (some_char == ' '); // TODO add other whitespace
        }

        bool is_alpha(int some_char) {
            return (((some_char >= 'A') && (some_char <= 'Z'))
                    || ((some_char >= 'a') && (some_char <= 'z'))
                    || (some_char == '_'));
        }

        bool is_digit(int some_char) {
            return ((some_char >= '0') && (some_char <= '9'));
        }

        std::string inline_char(int some_char) {
            switch (some_char) {
                case '\t':
                    return "\\t";
                case '\n':
                    return "\\n";
                case EOF:
                    return "EOF";
                default:
                    return {static_cast<char>(some_char)};
            }
        }
    }

    namespace exceptions {

        class text_repr_empty: public std::exception {
        public:
            [[nodiscard]] char const *what() const noexcept override {
                return "A token with a text repr was instantiated with an empty string";
            }
        };

        class unhandled_character: public std::exception {
        public:
            unhandled_character(char const *state_name, std::string next_char_repr):
                    state_name(state_name),
                    next_char_repr(std::move(next_char_repr)) {
//                message = std::format("A state (\"{}\") was unable to handle a character ('{}')", state_name, next_char_repr);
                // TODO
            }
            [[nodiscard]] char const *what() const noexcept override {
//                return message.c_str();
                return "A state was unable to handle a character";
            }
        private:
            char const *state_name;
            std::string next_char_repr;
            std::string message;
        };

        class identifier_too_long: public std::exception {
        public:
            [[nodiscard]] char const *what() const noexcept override {
                return "An identifier was too long and exceeded the identifier buffer size";
            }
        };

    }

    enum class token_type {
        identifier,
        colon,
        equals,
        open_parenthesis,
        close_parenthesis,
        right_arrow,
        open_curly_bracket,
        integer,
        semicolon,
        close_curly_bracket,
    };

    class token {
    public:
        [[nodiscard]] virtual bool equals(token const &other) const {
            return (type == other.type);
        }
        [[nodiscard]] virtual std::string const &get_text_repr() const {
            return util::get_static_empty_string();
        }
    protected:
        explicit token(token_type const &type): type(type) {
            // nop
        }
    private:
        token_type const type;
    };

    class token_with_text_repr: public token {
    public:
        [[nodiscard]] std::string const &get_text_repr() const override {
            return text_repr;
        }
        [[nodiscard]] bool equals(token const &other) const override {
            return token::equals(other) && (text_repr == other.get_text_repr());
        }
    protected:
        explicit token_with_text_repr(token_type const &type, std::string text_repr):
                token(token_type::identifier),
                text_repr(std::move(text_repr)) {
            if (this->text_repr == "") {
                throw exceptions::text_repr_empty();
            }
        }
    private:
        std::string text_repr;
    };

    namespace tokens {

        class identifier: public token_with_text_repr {
        public:
            explicit identifier(std::string const &text_repr):
                    token_with_text_repr(token_type::identifier, text_repr) {
                // nop
            }
        };

        class colon: public token {
        public:
            colon(): token(token_type::colon) {
                // nop
            }
        };

        class equals: public token {
        public:
            equals(): token(token_type::equals) {
                // nop
            }
        };

        class open_parenthesis: public token {
        public:
            open_parenthesis(): token(token_type::open_parenthesis) {
                // nop
            }
        };

        class close_parenthesis: public token {
        public:
            close_parenthesis(): token(token_type::close_parenthesis) {
                // nop
            }
        };

        class right_arrow: public token {
        public:
            right_arrow(): token(token_type::right_arrow) {
                // nop
            }
        };

        class open_curly_bracket: public token {
        public:
            open_curly_bracket(): token(token_type::open_curly_bracket) {
                // nop
            }
        };

        class integer: public token_with_text_repr {
        public:
            explicit integer(std::string const &text_repr):
                    token_with_text_repr(token_type::integer, text_repr) {
                // nop
            }
        };

        class semicolon: public token {
        public:
            semicolon(): token(token_type::semicolon) {
                // nop
            }
        };

        class close_curly_bracket: public token {
        public:
            close_curly_bracket(): token(token_type::close_curly_bracket) {
                // nop
            }
        };

    }

    class token_stream {
    public:
        void add_token(std::unique_ptr<token> &&token_ptr) {
            stream.emplace_back(std::move(token_ptr));
        }
        [[nodiscard]] bool equals(token_stream const &other) const {
            auto local_iter = stream.begin();
            auto other_iter = other.stream.begin();

            while ((local_iter != stream.end()) && (other_iter != other.stream.end())) {
                auto const &local_token = **local_iter;
                auto const &other_token = **other_iter;
                if (! local_token.equals(other_token)) {
                    return false;
                }

                local_iter ++;
                other_iter ++;
            }

            return (local_iter == stream.end()) && (other_iter == other.stream.end());
        }
    private:
        std::vector<std::unique_ptr<token>> stream;
    };

    namespace lexer {
        class context;

        class state {
        public:
            virtual void handle_next_chars() = 0;
        protected:
            explicit state(context *context): context(context) {
                // nop
            }
            context *context;
        };

        namespace states {
            class whitespace: public state {
            public:
                explicit whitespace(lexer::context *context): state(context) {
                    // nop
                }
                void handle_next_chars() override;
            };
            class eof: public state {
            public:
                explicit eof(lexer::context *context): state(context) {
                    // nop
                }
                void handle_next_chars() override {
                    throw exceptions::unhandled_character("eof", util::inline_char(EOF));
                }
            };
            class identifier: public state {
            public:
                explicit identifier(lexer::context *context): state(context) {
                    next_element = buffer.begin();
                }
                void handle_next_chars() override;
                void reset_and_add_first_char(int first_char) {
                    next_element = buffer.begin();
                    *next_element = static_cast<char>(first_char);
                    next_element ++;
                }
                void append_char(int next_char) {
                    if (next_element == buffer.end()) {
                        throw exceptions::identifier_too_long();
                    }

                    *next_element = static_cast<char>(next_char);
                    next_element ++;
                }
                std::string get_str() {
                    if (next_element == buffer.end()) {
                        throw exceptions::identifier_too_long();
                    }

                    *next_element = '\0';
                    return {buffer.begin(), buffer.end()};
                }
            private:
                std::array<char, 256> buffer;
                decltype(buffer)::iterator next_element;
            };
            class colon: public state {
            public:
                explicit colon(lexer::context *context): state(context) {
                    // nop
                }
                void handle_next_chars() override;
            };
        }

        class inplace_states_container {
        public:
            explicit inplace_states_container(context *context):
                    whitespace_state(context),
                    eof_state(context),
                    identifier_state(context),
                    colon_state(context)
                     {
                // nop
            }
            inplace_states_container(inplace_states_container const &) = delete;
            inplace_states_container &operator=(inplace_states_container const&) = delete;

            states::whitespace *get_whitespace_state() {
                return &whitespace_state;
            }
            states::eof *get_eof_state() {
                return &eof_state;
            }
            states::identifier *get_identifier_state() {
                return &identifier_state;
            }
            states::colon *get_colon_state() {
                return &colon_state;
            }
        private:
            states::whitespace whitespace_state;
            states::eof eof_state;
            states::identifier identifier_state;
            states::colon colon_state;
        };

        class context {
        public:
            context(std::istream &input_stream, token_stream &token_stream):
                    input_stream(input_stream),
                    token_stream(token_stream),
                    states_container(this) {
                current_state = states_container.get_whitespace_state();
            }
            void update_state(state *new_state) {
                current_state = new_state;
            }
            int get_next_char() {
                return input_stream.get();
            }
            void add_token_to_stream(std::unique_ptr<token> &&next_token) {
                token_stream.add_token(std::move(next_token));
            }
            void run() {
                state *eof_state = get_states().get_eof_state();
                while (current_state != eof_state) {
                    current_state->handle_next_chars();
                }
            }
            inplace_states_container &get_states() {
                return states_container;
            }
        private:
            std::istream &input_stream;
            token_stream &token_stream;
            state *current_state;
            inplace_states_container states_container;
        };

        void states::whitespace::handle_next_chars() {
            auto next_char = context->get_next_char();
            auto next_char_as_char = (char) next_char; // TODO remove - this is for debug view only

            // TODO make sure this isn't infinite
            while (util::is_whitespace(next_char)) {
                // ignore character and proceed
                next_char = context->get_next_char();
                next_char_as_char = (char) next_char; // TODO remove - this is for debug view only
            }

            auto &states = context->get_states();

            if (next_char == EOF) {
                context->update_state(states.get_eof_state());
                return;
            }
            if (util::is_alpha(next_char)) {
                states::identifier *identifier_state = states.get_identifier_state();
                context->update_state(identifier_state);
                identifier_state->reset_and_add_first_char(next_char);
                return;
            }
            if (next_char == ':') {
                context->update_state(states.get_colon_state());
                return;
            }

            // TODO

            throw exceptions::unhandled_character("whitespace", util::inline_char(next_char));
        }

        void states::identifier::handle_next_chars() {
            auto next_char = context->get_next_char();
            auto next_char_as_char = (char) next_char; // TODO remove - this is for debug view only

            while (util::is_alpha(next_char) || util::is_digit(next_char)) {
                append_char(next_char);

                next_char = context->get_next_char();
                next_char_as_char = (char) next_char; // TODO remove - this is for debug view only
            }

            context->add_token_to_stream(std::make_unique<tokens::identifier>(get_str()));

            auto &states = context->get_states();

            if (next_char == EOF) {
                context->update_state(states.get_eof_state());
                return;
            }

            if (util::is_whitespace(next_char)) {
                context->update_state(states.get_whitespace_state());
                return;
            }

            // TODO

            throw exceptions::unhandled_character("identifier", util::inline_char(next_char));
        }


        void states::colon::handle_next_chars() {
            auto next_char = context->get_next_char();
            auto next_char_as_char = (char) next_char; // TODO remove - this is for debug view only

            context->add_token_to_stream(std::make_unique<tokens::colon>());

            // TODO

            throw exceptions::unhandled_character("colon", util::inline_char(next_char));
        }
    }

    token_stream lex(std::istream &input_stream) {
        token_stream token_stream;
        lexer::context context(input_stream, token_stream);
        context.run();
        return token_stream;
    }

}