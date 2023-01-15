#include "parse_args.hpp"
#include "command_line_arguments.hpp"

namespace stub {
int parse_args(int argc, const char **argv) {
  auto app = CLI::App("Stub description");
  auto args = command_line_arguments(std::cout, app);
  return args.parse(argc, argv);
}
}
