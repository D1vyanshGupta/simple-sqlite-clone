#include "ReferenceWrapperString.hpp"

std::size_t ReferenceWrapperStringHash::operator()(
    const std::reference_wrapper<const std::string> &ref) const noexcept {
  return std::hash<std::string>()(ref.get());
}

bool ReferenceWrapperStringEqual::operator()(
    const std::reference_wrapper<const std::string> &lhs,
    const std::reference_wrapper<const std::string> &rhs) const noexcept {
  return lhs.get() == rhs.get();
}
