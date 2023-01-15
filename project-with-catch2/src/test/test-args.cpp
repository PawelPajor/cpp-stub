#include <catch2/catch_all.hpp>
#include <fakeit.hpp>

#include <args.hpp>
#include <version.hpp>

#include <string>
#include <tuple>
#include <vector>

namespace stub {

using std::string;
using std::stringstream;
using std::tuple;
using std::vector;
using namespace fakeit;

Mock <cli_app> make_mock() {
  Mock <cli_app> mock;
  When(Method(mock, parse)).Return(1);
  When(Method(mock, add_flag)).AlwaysDo([](auto name, auto callback, auto description) {});
  return mock;
}

TEST_CASE("args", "[lib]") {

  SECTION("add_flag") {

    // Arrange
    auto mock = make_mock();
    stringstream actual_stream;

    // Act
    args(mock.get(), actual_stream);

    // Assert
    auto verifier = [&](auto name, auto callback, auto description) -> bool {
      callback(1);
      stringstream expected_stream;
      expected_stream << version::current() << std::endl;
      return
          (name == "-v,--version") &&
          (description == "Version of this stub") &&
          (actual_stream.str() == expected_stream.str());
    };
    Verify(Method(mock, add_flag).Matching(verifier)).Exactly(1);
  }

  SECTION("parse") {

    // Arrange
    const char *argv[2];
    argv[0] = "app";
    argv[1] = "-v";
    stringstream stream;
    auto mock = make_mock();

    // Act
    const auto result = args(mock.get(), stream).parse(2, argv);

    // Assert
    REQUIRE(result == 1);
    REQUIRE(stream.str().empty());
    Verify(
        Method(mock, parse)
            .Matching([&](auto c, auto v) -> bool {return c == 2 && v == argv;}))
        .Exactly(1);
  }
}
}