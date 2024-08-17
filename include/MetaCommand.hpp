#ifndef INCLUDE_METACOMMAND_HPP_
#define INCLUDE_METACOMMAND_HPP_

#include <string>

const char PERIOD = '.';
const char META_CMD_EXIT[] = ".exit";

enum class MetaCommandResult {
  META_COMMAND_SUCCESS,
  META_COMMAND_UNRECOGNIZED_COMMAND
};

bool is_meta_command(const std::string &input_buffer);

MetaCommandResult process_meta_command(const std::string &input_buffer);

#endif // INCLUDE_METACOMMAND_HPP_
