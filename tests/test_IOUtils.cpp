#include "IOUtils.hpp"
#include <format>
#include <gtest/gtest.h>
#include <sstream>
#include <stdexcept>
#include <string>

TEST(ReadInput, HandlesValidInput) {
  // setup input buffer
  std::string inputBuffer;

  // populate prepare mock data
  std::string lineOne = "line1";
  std::string lineTwo = "line2";
  std::string mockData = std::format("{0}\n{1}", lineOne, lineTwo);

  // init string stream with mockData
  std::istringstream inputStream(mockData);

  // read mockData from stream
  read_input_from_stream(&inputBuffer, inputStream);

  // assert string before newline was correctly read
  EXPECT_EQ(inputBuffer, lineOne);
}

TEST(ReadInput, ThrowsRuntimeErrorForInvalidInput) {
  // setup input buffer
  std::string inputBuffer;

  // populate prepare mock data
  std::string invalidData = "\n";

  // init string stream with mockData
  std::istringstream inputStream(invalidData);

  // assert runtime exception is throws

  // cppcheck-suppress unknownMacro
  EXPECT_THROW(read_input_from_stream(&inputBuffer, inputStream);
               , std::runtime_error);
}
