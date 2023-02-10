#include <iostream>

// Doc: https://cliutils.github.io/CLI11/book
#include <CLI/CLI.hpp>

#include "entrance.hpp"
#include "version.hpp"

namespace stub {

int run() {
  // Enter into the tool logic here
  return 0;
}

entrance::entrance(int argc, const char *const *argv, std::ostream &out, std::ostream &err)
    : argc(argc), argv(argv), out(out), err(err) {}

int entrance::enter() {
  CLI::App cli_app;
  cli_app.set_version_flag("-v,--version", version::current().str());
  try {
    cli_app.parse(argc, argv);
  }
  catch (const CLI::ParseError &error) {
    return cli_app.exit(error, out, err);
  }

  return run();
}

}
