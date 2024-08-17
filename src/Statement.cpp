#include "Statement.hpp"
#include "Utils.hpp"
#include <format>
#include <iostream>
#include <string>
#include <vector>

Statement::Statement(const StatementType &statement_type,
                     const std::string &text)
    : statement_type(statement_type), text(text) {}

StatementType Statement::get_type() const { return statement_type; }
std::string Statement::get_text() const { return text; }
bool Statement::operator==(const Statement &other) const {
  return other.get_type() == get_type() && other.get_text() == get_text();
}

StatementType get_statement_type(const std::string &input_buffer) {
  // get first word from input buffer
  std::string word = split_string_on_whitespace(input_buffer)[0];

  auto it = STATEMENT_TEXT_TYPE_MAP.find(word);
  if (it == STATEMENT_TEXT_TYPE_MAP.end())
    return StatementType::STATEMENT_UNRECOGNIZED;

  return it->second;
}

Statement prepare_statement(const std::string &input_buffer) {
  StatementType statement_type = get_statement_type(to_lowercase(input_buffer));
  return Statement(statement_type, input_buffer);
}

void process_statement(const Statement &statement) {
  switch (statement.get_type()) {
  case StatementType::STATEMENT_SELECT: {
    // TODO(D1vyanshGupta): replace with actual implementation
    std::cout << "handle select statement\n";
    break;
  }
  case StatementType::STATEMENT_INSERT: {
    // TODO(D1vyanshGupta): replace with actual implementation
    std::cout << "handle insert statement\n";
    break;
  }
  default: {
    std::cout << std::format("Unrecognized command '{0}'.\n",
                             statement.get_text());
  }
  }
}
