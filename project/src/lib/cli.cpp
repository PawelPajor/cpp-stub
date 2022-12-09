#include "cli.hpp"
#include "version.hpp"
#include <iostream>

namespace stub {
namespace {

void populate(CLI::App &app, std::ostream &os) {

  app.add_flag(
      "-v,--version",
      [&](int _) { os << version::current() << std::endl; },
      "Version of this stub");
}
}

cli::cli(std::ostream &os) : app("Stub description") {
  populate(app, os);
}

cli::cli() : cli(std::cout) {}

int cli::parse(int argc, const char **argv) {
  CLI11_PARSE(app, argc, argv);
  return 0;
}
}
