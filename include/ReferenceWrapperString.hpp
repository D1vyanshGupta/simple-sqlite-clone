#ifndef INCLUDE_REFERENCEWRAPPERSTRING_HPP_
#define INCLUDE_REFERENCEWRAPPERSTRING_HPP_

#include <cstddef>
#include <functional>
#include <string>

struct ReferenceWrapperStringHash {
  std::size_t operator()(
      const std::reference_wrapper<const std::string> &ref) const noexcept;
};

struct ReferenceWrapperStringEqual {
  bool operator()(
      const std::reference_wrapper<const std::string> &lhs,
      const std::reference_wrapper<const std::string> &rhs) const noexcept;
};

#endif // INCLUDE_REFERENCEWRAPPERSTRING_HPP_
