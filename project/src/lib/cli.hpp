#pragma once

// Doc: https://cliutils.github.io/CLI11/book
#include <CLI/CLI.hpp>

#include <ostream>

namespace stub {

class cli {

public:

  cli();
  explicit cli(std::ostream &os);
  int parse(int argc, const char **argv);

private:

  CLI::App app;
};
}
