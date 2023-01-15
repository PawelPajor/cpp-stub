#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <unordered_map>

#include <command_line_arguments.hpp>

namespace stub {

using ::testing::_;
using ::CLI::Error;
using ::CLI::Option;

class mock_cli_app {
public:

  using flag_callback_t = std::function<void(std::int64_t)>;
  using flag_map_t = std::unordered_map<std::string, std::tuple<flag_callback_t, std::string>>;

  mock_cli_app() {
    ON_CALL(*this, add_flag(_, _, _))
        .WillByDefault([this](auto n, auto c, auto d) -> Option * {
          flag_map.emplace(std::move(n), std::make_tuple(std::move(c), std::move(d)));
          return nullptr;
        });
  }

  MOCK_METHOD(Option *, add_flag, (std::string, flag_callback_t, std::string));
  MOCK_METHOD(void, parse, (int, const char *const *));
  MOCK_METHOD(int, exit, (const Error &), (const));

  flag_map_t flag_map;
};

TEST(test_command_line_arguments, test_parse) {
  std::stringstream stream;
  mock_cli_app mock_app;
  EXPECT_CALL(mock_app, add_flag(_, _, _)).Times(1);
  ON_CALL(mock_app, parse(_, _))
      .WillByDefault([](int c, const char *const *v) {
        ASSERT_EQ(c, 2);
        ASSERT_EQ(v[0], "app");
        ASSERT_EQ(v[1], "-v");
      });
  EXPECT_CALL(mock_app, parse(_, _)).Times(1);
  auto tested = command_line_arguments<mock_cli_app>(stream, mock_app);
  ASSERT_EQ(1, mock_app.flag_map.size());
  const auto &[callback, desc] = mock_app.flag_map["-v,--version"];
  callback(1);
  std::stringstream expected;
  expected << version::current() << std::endl;
  ASSERT_EQ(stream.str(), expected.str());
  ASSERT_EQ(desc, "Version of this stub");

  const char *argv[2];
  argv[0] = "app";
  argv[1] = "-v";
  tested.parse(2, argv);
}

}
