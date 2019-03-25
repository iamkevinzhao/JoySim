#ifndef COMMON_UTILS_H
#define COMMON_UTILS_H

#include <iterator>

struct EnumClassHash {
  template <typename T>
  std::size_t operator()(T t) const {
    return static_cast<std::size_t>(t);
  }
};

#endif // COMMON_UTILS_H
