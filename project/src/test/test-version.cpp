#include <gtest/gtest.h>
#include <regex>
#include <version.hpp>

namespace stub {

TEST(version, test_format) {
  ASSERT_TRUE(regex_match(
      version::current().str(),
      std::regex(R"([0-9]+\.[0-9]+\.[0-9]{8}\.[0-9]{6})")));
}
}