#include <gtest/gtest.h>
#include <regex>
#include <version.hpp>

namespace stub {

TEST(test_foo, test_version) {
  std::stringstream stream;
  stream << version::current();
  const auto version = stream.str();
  ASSERT_TRUE(regex_match(
      version,
      std::regex(R"([0-9]+\.[0-9]+\.[0-9]{8}\.[0-9]{6})")));
}
}