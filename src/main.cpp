#include "IOUtils.hpp"
#include <constants.hpp>
#include <format>
#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include <string>

int main(int argc, char *argv[]) {
  std::string inputBuffer;

  while (true) {
    print_prompt();

    try {
      read_input_from_stream(&inputBuffer, std::cin);

      if (inputBuffer == EXIT_STRING)
        exit(EXIT_SUCCESS);

      std::string outString =
          std::format("Unrecognized command '{0}'.\n", inputBuffer);
      std::cout << outString;

    } catch (const std::runtime_error &e) {
      exit(EXIT_FAILURE);
    }
  }

  return 0;
}
