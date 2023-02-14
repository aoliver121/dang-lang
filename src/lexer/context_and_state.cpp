// Created by aioli121 on 2/12/2023.

#include "context_and_state.hpp"
#include "token/token_factory.hpp"

namespace dang::lexer {

    void state::handle_next_chars() {
        int next_char_as_int = state_maintenance_loop();

        add_relevant_token(next_char_as_int);
    }

    state::state(lexer::context &context): context(context) {
        // nop
    }

    int state::state_maintenance_loop() {
        // No looping in the base case
        return context.get_next_char_as_int();
    }

    void state::add_relevant_token(int next_char_as_int) {
        // nop
    }

    context::context(std::istream &input_stream, token_stream &tokens): input_stream(input_stream), tokens(tokens), states(*this) {
        // nop
    }

    int context::get_next_char_as_int() {
        return input_stream.get();
    }

    void context::add_token_to_stream(std::unique_ptr<token> next_token) {
        tokens.add_token(std::move(next_token));
    }

    state_manager &context::get_state_manager() {
        return states;
    }

    std::string context::get_buffer_as_string() {
        return {buffer.begin(), buffer.end()};
    }

    void context::run() {
        while (states.is_not_eof()) {
            states.get_current_state()->handle_next_chars();
        }
    }

    state_manager::state_manager(context &context):
            current_state(&whitespace_state),
            close_curly_bracket_state(context),
            close_parenthesis_state(context),
            colon_state(context),
            dash_branch_state(context),
            eof_state(context),
            equals_branch_state(context),
            letters_state(context),
            number_branch_state(context),
            open_curly_bracket_state(context),
            open_parenthesis_state(context),
            right_arrow_state(context),
            semicolon_state(context),
            whitespace_state(context) {
        // nop
    }

    bool state_manager::is_not_eof() {
        return current_state != &eof_state;
    }

    state *state_manager::get_current_state() {
        return current_state;
    }

    void states::close_curly_bracket::add_relevant_token(int next_char_as_int) {
        context.add_token_to_stream(token_factory::new_close_curly_bracket());
    }

    void states::close_parenthesis::add_relevant_token(int next_char_as_int) {
        context.add_token_to_stream(token_factory::new_close_parenthesis());
    }

    void states::colon::add_relevant_token(int next_char_as_int) {
        context.add_token_to_stream(token_factory::new_colon());
    }

    void states::dash_branch::add_relevant_token(int next_char_as_int) {
        // TODO
    }

    void states::equals_branch::add_relevant_token(int next_char_as_int) {
        // TODO
    }

    void states::letters::add_relevant_token(int next_char_as_int) {
        // TODO check if keyword
        context.add_token_to_stream(token_factory::new_identifier(context.get_buffer_as_string()));
    }

    void states::number_branch::add_relevant_token(int next_char_as_int) {
        // TODO
    }

    void states::open_curly_bracket::add_relevant_token(int next_char_as_int) {
        context.add_token_to_stream(token_factory::new_open_curly_bracket());
    }

    void states::open_parenthesis::add_relevant_token(int next_char_as_int) {
        context.add_token_to_stream(token_factory::new_open_parenthesis());
    }

    void states::right_arrow::add_relevant_token(int next_char_as_int) {
        context.add_token_to_stream(token_factory::new_right_arrow());
    }

    void states::semicolon::add_relevant_token(int next_char_as_int) {
        context.add_token_to_stream(token_factory::new_semicolon());
    }
}