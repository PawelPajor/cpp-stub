#pragma once

// Doc: https://cliutils.github.io/CLI11/book
#include <CLI/CLI.hpp>

namespace stub {

template<typename TApp>
command_line_arguments<TApp>::command_line_arguments(std::ostream &os, TApp &app)
    : app(app), os(os) {
  populate();
}

template<typename TApp>
int command_line_arguments<TApp>::parse(int argc, const char **argv) {
  try {
    app.parse(argc, argv);
  } catch (const CLI::ParseError &e) {
    return app.exit(e);
  }
  return 0;
}

template<typename TApp>
void command_line_arguments<TApp>::populate() {

  app.add_flag(
      "-v,--version",
      [&](int _) { os << version::current() << std::endl; },
      "Version of this stub");
}
}
