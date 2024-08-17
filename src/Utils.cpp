#include "Utils.hpp"
#include <_ctype.h>
#include <algorithm>
#include <cctype>
#include <regex>
#include <vector>

std::string to_lowercase(const std::string &input_buffer) {
  std::string output(input_buffer.length(), '\0');
  std::transform(input_buffer.begin(), input_buffer.end(), output.begin(),
                 [](unsigned char c) { return std::tolower(c); });
  return output;
}

std::vector<std::string>
split_string_on_whitespace(const std::string &input_buffer) {
  std::regex ws_re("\\s+");
  std::sregex_token_iterator iter(input_buffer.begin(), input_buffer.end(),
                                  ws_re, -1);
  std::sregex_token_iterator end;

  if (*iter == "")
    return std::vector<std::string>();

  return {iter, end};
}
