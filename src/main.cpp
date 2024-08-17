#include "IOUtils.hpp"
#include "MetaCommand.hpp"
#include "Statement.hpp"
#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include <string>

int main(int argc, char *argv[]) {
  std::string input_buffer;

  while (true) {
    print_prompt();

    try {
      read_input_from_stream(&input_buffer, std::cin);

      if (input_buffer == META_CMD_EXIT)
        exit(EXIT_SUCCESS);

      Statement statement = prepare_statement(input_buffer);
      process_statement(statement);

    } catch (const std::runtime_error &e) {
      exit(EXIT_FAILURE);
    }
  }

  return 0;
}
