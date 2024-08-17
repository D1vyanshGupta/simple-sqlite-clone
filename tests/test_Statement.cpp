#include "Statement.hpp"
#include "gtest/gtest.h"
#include <string>

// define the parameterized test fixture class
class GetStatementTypeParameterizedTest
    : public ::testing::TestWithParam<std::pair<std::string, StatementType>> {};

// instantiate the test case with different parameter values
INSTANTIATE_TEST_SUITE_P(
    , GetStatementTypeParameterizedTest,
    ::testing::Values(
        std::make_pair(std::string("select * from table;"),
                       StatementType::STATEMENT_SELECT),
        std::make_pair(std::string("insert into table values (1, 2, 3);"),
                       StatementType::STATEMENT_INSERT),
        std::make_pair(std::string("invalid command;"),
                       StatementType::STATEMENT_UNRECOGNIZED)));

TEST_P(GetStatementTypeParameterizedTest, ) {

  auto [input_string, expected_statement_type] = GetParam();
  auto actual_statement_type = get_statement_type(input_string);
  EXPECT_EQ(actual_statement_type, expected_statement_type);
}

// define the parameterized test fixture class
class PrepareStatementParameterizedTest
    : public ::testing::TestWithParam<std::pair<std::string, StatementType>> {};

// instantiate the test case with different parameter values
INSTANTIATE_TEST_SUITE_P(
    , PrepareStatementParameterizedTest,
    ::testing::Values(
        std::make_pair(std::string("select * from table;"),
                       StatementType::STATEMENT_SELECT),
        std::make_pair(std::string("insert into table values (1, 2, 3);"),
                       StatementType::STATEMENT_INSERT),
        std::make_pair(std::string("invalid command;"),
                       StatementType::STATEMENT_UNRECOGNIZED)));

TEST_P(PrepareStatementParameterizedTest, ) {

  auto [input_string, expected_statement_type] = GetParam();
  Statement expected_statement =
      Statement(expected_statement_type, input_string);

  Statement actual_statement = prepare_statement(input_string);
  EXPECT_EQ(actual_statement, expected_statement);
}
