#include <catch2/catch_all.hpp>
#include <regex>
#include <version.hpp>

namespace stub {

TEST_CASE("version", "[lib]") {
  REQUIRE(regex_match(
      version::current().str(),
      std::regex(R"([0-9]+\.[0-9]+\.[0-9]{8}\.[0-9]{6})")));
}
}