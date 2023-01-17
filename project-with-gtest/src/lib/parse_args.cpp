#include <CLI/App.hpp>

#include "args.hpp"
#include "parse_args.hpp"

namespace stub {
int parse_args(int argc, const char *const *argv) {
  CLI::App app("Stub description");
  cli_app_wrapper parser(app);
  return args(parser).parse(argc, argv);
}
}
