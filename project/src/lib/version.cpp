#include <sstream>
#include "version.hpp"
#include "stringify.h"

namespace stub {

version version::current() {
  return version{LIB_VERSION_MAJOR, LIB_VERSION_MINOR, XSTR(DATESTAMP), XSTR(TIMESTAMP)};
}

std::ostream &operator<<(std::ostream &os, const version &version) {
  return os << version.major
     << '.' << version.minor
     << '.' << version.datestamp
     << '.' << version.timestamp;
}

std::string version::str() const {
  std::stringstream stream;
  stream << *this;
  return stream.str();
}
}