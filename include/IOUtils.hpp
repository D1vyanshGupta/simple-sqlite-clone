#ifndef INCLUDE_IOUTILS_HPP_
#define INCLUDE_IOUTILS_HPP_

#include <__fwd/istream.h>
#include <string>

void print_prompt();

void read_input_from_stream(std::string *input_buffer, std::istream &istream);

#endif // INCLUDE_IOUTILS_HPP_
