#include "Utils.hpp"
#include "gtest/gtest.h"
#include <string>
#include <utility>
#include <vector>

class ToLoweraseParameterizedTest
    : public ::testing::TestWithParam<std::pair<std::string, std::string>> {};

INSTANTIATE_TEST_SUITE_P(
    , ToLoweraseParameterizedTest,
    ::testing::Values(std::make_pair("UPPERCASE", "uppercase"),
                      std::make_pair("lowercase", "lowercase")),
    [](const testing::TestParamInfo<ToLoweraseParameterizedTest::ParamType>
           &info) {
      auto test_param = info.param;
      auto input_string = test_param.first;
      if (input_string == "UPPERCASE") {
        return std::string("LowercasesUppercaseString");
      }
      return std::string("LowercaseStringIsUnchanged");
    });

TEST_P(ToLoweraseParameterizedTest, ) {
  auto [input_string, expected_string] = GetParam();
  auto actual_string = to_lowercase(input_string);
  EXPECT_EQ(actual_string, expected_string);
}

// define parameterized test fixture class for SplitStringOnWhitespace (SSOW)
class SplitStringOnWhitespaceParameterizedTest
    : public ::testing::TestWithParam<
          std::pair<std::string, std::vector<std::string>>> {};

// instantiate the test case with different parameter values
INSTANTIATE_TEST_SUITE_P(
    , SplitStringOnWhitespaceParameterizedTest,
    ::testing::Values(
        std::make_pair(
            std::string("the quick brown fox jumped over the lazy dog"),
            std::vector<std::string>{"the", "quick", "brown", "fox", "jumped",
                                     "over", "the", "lazy", "dog"}),
        std::make_pair(std::string(""), std::vector<std::string>{})),
    [](const testing::TestParamInfo<
        SplitStringOnWhitespaceParameterizedTest::ParamType> &info) {
      auto test_param = info.param;

      if (test_param.first.length() > 0) {
        return std::string("SplitsNonEmptyString");
      }
      return std::string("ReturnsEmptyVectorForEmptyString");
    });

TEST_P(SplitStringOnWhitespaceParameterizedTest, ) {
  auto [input_string, expected_vec] = GetParam();
  auto actual_vec = split_string_on_whitespace(input_string);
  EXPECT_EQ(actual_vec, expected_vec);
}
