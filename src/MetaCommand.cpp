#include "MetaCommand.hpp"
#include <string>

bool is_meta_command(const std::string &input_buffer) {
  return input_buffer.at(0) == PERIOD;
}

MetaCommandResult process_meta_command(const std::string &input_buffer) {
  if (input_buffer == META_CMD_EXIT)
    return MetaCommandResult::META_COMMAND_SUCCESS;
  return MetaCommandResult::META_COMMAND_UNRECOGNIZED_COMMAND;
}
