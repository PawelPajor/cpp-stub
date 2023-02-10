#pragma once

#include <iostream>

namespace stub {

class entrance {
  int argc;
  const char * const *argv;
  std::ostream &out;
  std::ostream &err;

public:
  entrance(int argc, const char * const *argv, std::ostream &out = std::cout, std::ostream &err = std::cerr);
  int enter();
};
}
