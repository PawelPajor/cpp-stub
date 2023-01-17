#include <catch2/catch_all.hpp>

#include <entrance.hpp>
#include <version.hpp>

#include <string>
#include <tuple>
#include <vector>

namespace stub {

void validate(const char *flag, const char *expected) {
  // Arrange
  const char *argv[2];
  argv[0] = "app";
  argv[1] = flag;
  std::stringstream out;
  std::stringstream err;

  // Act
  const auto result = entrance(2, argv, out, err).enter();

  // Assert
  REQUIRE(result == 0);
  REQUIRE(out.str() == expected);
}

TEST_CASE("entrance", "[lib]") {
  validate("-v", (version::current().str() + '\n').c_str());
  validate("--version", (version::current().str() + '\n').c_str());
  const char *help_string =
      "Usage: app [OPTIONS]\n"
      "\n"
      "Options:\n"
      "  -h,--help                   Print this help message and exit\n"
      "  -v,--version                Display program version information and exit\n"
      "\n";
  validate("-h", help_string);
  validate("--help", help_string);
}
}