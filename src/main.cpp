// Created by aioli121 on 2/10/2023.

#include <sstream>
#include <iostream>
#include <memory>
#include <utility>
#include <vector>

namespace dang {

    namespace util {

        // Returns one static instance of the empty string for usage where a const reference to "" is needed
        std::string const &get_static_empty_string() {
            static std::string const empty;
            return empty;
        }

    }

    namespace exceptions {

        class text_repr_empty: public std::exception {
        public:
            [[nodiscard]] char const *what() const noexcept override {
                return "A token with a text repr was instantiated with an empty string";
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
            if (text_repr == "") {
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

    token_stream lex(std::istream const &input_stream) {
        // TODO
        return {};
    }

}

bool lexer_test_1() {
    auto const input_text = "main := () -> exit_code: int32 { exit_code = 169; };";
    auto const input_stream = std::istringstream(input_text);

    auto expected_output = dang::token_stream();
    expected_output.add_token(std::make_unique<dang::tokens::identifier>("main"));
    expected_output.add_token(std::make_unique<dang::tokens::colon>());
    expected_output.add_token(std::make_unique<dang::tokens::equals>());
    expected_output.add_token(std::make_unique<dang::tokens::open_parenthesis>());
    expected_output.add_token(std::make_unique<dang::tokens::close_parenthesis>());
    expected_output.add_token(std::make_unique<dang::tokens::right_arrow>());
    expected_output.add_token(std::make_unique<dang::tokens::identifier>("exit_code"));
    expected_output.add_token(std::make_unique<dang::tokens::colon>());
    expected_output.add_token(std::make_unique<dang::tokens::identifier>("int32"));
    expected_output.add_token(std::make_unique<dang::tokens::open_curly_bracket>());
    expected_output.add_token(std::make_unique<dang::tokens::identifier>("exit_code"));
    expected_output.add_token(std::make_unique<dang::tokens::equals>());
    expected_output.add_token(std::make_unique<dang::tokens::integer>("169"));
    expected_output.add_token(std::make_unique<dang::tokens::semicolon>());
    expected_output.add_token(std::make_unique<dang::tokens::close_curly_bracket>());
    expected_output.add_token(std::make_unique<dang::tokens::semicolon>());

    auto const actual_output = dang::lex(input_stream);

    return actual_output.equals(expected_output);
}

int main() {
    std::cout << std::boolalpha << lexer_test_1() << "\n";
}
