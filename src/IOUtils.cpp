#include "IOUtils.hpp"
#include "constants.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

void print_prompt() { std::cout << CMD_PREFIX; }

void read_input_from_stream(std::string *input_buffer, std::istream &istream) {
  std::getline(istream, *input_buffer);

  if ((*input_buffer).length() == 0) {
    throw std::runtime_error(ERROR_READING_INPUT_STREAM);
  }
}
