#pragma once

#include <iosfwd>
#include <ostream>

namespace stub {
struct version  {
  int major;
  int minor;
  const char *datestamp;
  const char *timestamp;

  std::string str() const;
  static version current();
  friend std::ostream &operator<<(std::ostream &os, const version &version);
};
}
