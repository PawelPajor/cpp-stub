#include <catch2/catch_all.hpp>
#include <cli.hpp>
#include <version.hpp>

namespace stub {

TEST_CASE("cli", "[lib]") {

  SECTION("Parse version") {

    auto verify = [](const char *flag) {
      std::stringstream actual;
      cli tested(actual);
      const char *argv[2];
      argv[0] = "app";
      argv[1] = flag;
      const auto result = tested.parse(2, argv);
      REQUIRE(result == 0);
      std::stringstream expected;
      expected << version::current() << std::endl;
      REQUIRE(actual.str() == expected.str());
    };

    verify("-v");
    verify("--version");
  }
}
}