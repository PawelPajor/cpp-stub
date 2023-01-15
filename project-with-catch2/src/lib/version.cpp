#include "version.hpp"
#include "stringify.h"

namespace stub {

version version::current() {
  return version{0, 1, XSTR(DATESTAMP), XSTR(TIMESTAMP)};
}

std::ostream &operator<<(std::ostream &os, const version &version) {
  return os << version.major
     << '.' << version.minor
     << '.' << version.datestamp
     << '.' << version.timestamp;
}
}