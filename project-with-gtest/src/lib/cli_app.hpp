#pragma once

#include <CLI/App.hpp>
#include <CLI/Error.hpp>
#include <functional>

namespace stub {
class cli_app {
public:
  using callback_t = std::function<void(std::int64_t)>;
  virtual ~cli_app() = default;
  virtual void add_flag(std::string name, callback_t callback, std::string description) = 0;
  virtual int parse(int argc, const char *const *argv) = 0;
};

class cli_app_wrapper : public cli_app {
  CLI::App &app;
  std::ostream &out;
  std::ostream &err;

public:

  explicit cli_app_wrapper(CLI::App &app, std::ostream &out = std::cout, std::ostream &err = std::cout)
    : app(app), out(out), err(err) {}

  void add_flag(std::string name, callback_t callback, std::string description) override {
    app.add_flag(std::move(name), std::move(callback), std::move(description));
  }

  int parse(int argc, const char *const *argv) override {
    try {
      app.parse(argc, argv);
    } catch (const CLI::ParseError &error) {
      return app.exit(error, out, err);
    }
    return 0;
  }

};
}
