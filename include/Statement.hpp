#ifndef INCLUDE_STATEMENT_HPP_
#define INCLUDE_STATEMENT_HPP_

#include "ReferenceWrapperString.hpp"
#include <functional>
#include <string>
#include <unordered_map>
#include <utility>

const std::string STATEMENT_SELECT = "select";
const std::string STATEMENT_INSERT = "insert";

enum class StatementType {
  STATEMENT_SELECT,
  STATEMENT_INSERT,
  STATEMENT_UNRECOGNIZED
};

class Statement {

private:
  StatementType statement_type;
  std::string text;

public:
  Statement(const StatementType &statement_type, const std::string &text);
  StatementType get_type() const;
  std::string get_text() const;

  bool operator==(const Statement &other) const;
};

const std::unordered_map<std::reference_wrapper<const std::string>,
                         StatementType, ReferenceWrapperStringHash,
                         ReferenceWrapperStringEqual>
    STATEMENT_TEXT_TYPE_MAP = {
        {STATEMENT_SELECT, StatementType::STATEMENT_SELECT},
        {STATEMENT_INSERT, StatementType::STATEMENT_INSERT},
};

StatementType get_statement_type(const std::string &input_bufer);

Statement prepare_statement(const std::string &input_buffer);

void process_statement(const Statement &statement);

#endif // INCLUDE_STATEMENT_HPP_
