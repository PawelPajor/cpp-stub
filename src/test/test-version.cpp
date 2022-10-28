#include <catch2/catch_all.hpp>
#include <regex>
#include <version.hpp>

namespace stub {

TEST_CASE("version", "[lib]") {
  std::stringstream stream;
  stream << version::current();
  const auto version = stream.str();
  REQUIRE(regex_match(
      version,
      std::regex(R"([0-9]+\.[0-9]+\.[0-9]{8}\.[0-9]{6})")));
}
}