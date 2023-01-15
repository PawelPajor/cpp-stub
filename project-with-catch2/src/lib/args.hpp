#pragma once

// Doc: https://cliutils.github.io/CLI11/book
#include <CLI/CLI.hpp>

#include <ostream>
#include "cli_app.hpp"

namespace stub {

class args {
  cli_app &parser;
  std::ostream &out;

public:
  explicit args(cli_app &parser, std::ostream &out = std::cout);
  int parse(int argc, const char * const *argv);

private:
  void populate();

};
}
