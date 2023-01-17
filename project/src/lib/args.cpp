#include "args.hpp"
#include "version.hpp"
#include <iostream>

namespace stub {

args::args(cli_app &parser, std::ostream &out)
    : parser(parser), out(out) {
  populate();
}

void args::populate() {
  parser.add_flag(
      "-v,--version",
      [&](int _) { out << version::current() << std::endl; },
      "Version of this stub");
}

int args::parse(int argc, const char *const *argv) {
  return parser.parse(argc, argv);
}

}
