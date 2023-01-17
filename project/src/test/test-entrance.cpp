#include <gtest/gtest.h>

#include <entrance.hpp>
#include <version.hpp>

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
  ASSERT_TRUE(result == 0);
  ASSERT_TRUE(out.str() == expected);
}

TEST(entrance, test_enter) {
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