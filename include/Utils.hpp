#ifndef INCLUDE_UTILS_HPP_
#define INCLUDE_UTILS_HPP_

#include <string>
#include <vector>

std::string to_lowercase(const std::string &input_buffer);

std::vector<std::string>
split_string_on_whitespace(const std::string &input_buffer);

#endif // INCLUDE_UTILS_HPP_
