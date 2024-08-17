#include "MetaCommand.hpp"
#include "constants.hpp"
#include "gtest/gtest.h"
#include <string>

TEST(IsMetaCommand, ReturnsTrueForMetaCommand) {
  // setup input buffer
  std::string input_buffer(1, PERIOD);
  input_buffer += "string";

  // assert return value is true
  EXPECT_TRUE(is_meta_command(input_buffer));
}

TEST(IsMetaCommand, ReturnsFalseForNotMetaCommand) {
  // setup input buffer
  std::string input_buffer = "string";

  // assert return value is false
  EXPECT_FALSE(is_meta_command(input_buffer));
}

TEST(ProcessMetaCommand, ReturnsSuccesForValidMetaCommand) {
  // setup input buffer
  std::string input_buffer = META_CMD_EXIT;

  // assert return value is true
  EXPECT_EQ(process_meta_command(input_buffer),
            MetaCommandResult::META_COMMAND_SUCCESS);
}

TEST(ProcessMetaCommand, ReturnsSuccesForInvalidMetaCommand) {
  // setup input buffer
  std::string input_buffer = "string";

  // assert return value is false
  EXPECT_EQ(process_meta_command(input_buffer),
            MetaCommandResult::META_COMMAND_UNRECOGNIZED_COMMAND);
}
