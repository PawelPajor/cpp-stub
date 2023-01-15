#pragma once

#include <ostream>
#include "version.hpp"

namespace stub {

template<typename TApp>
class command_line_arguments {

public:

  command_line_arguments(std::ostream &os, TApp &app);
  int parse(int argc, const char **argv);

private:

  void populate();

  TApp &app;
  std::ostream &os;
};
}

#include "command_line_arguments.inl"