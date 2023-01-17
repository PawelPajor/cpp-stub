#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <args.hpp>
#include <version.hpp>

namespace stub {

class cli_app_mock : public cli_app {
public:
  MOCK_METHOD(void, add_flag, (std::string name, callback_t callback, std::string description), (override));
  MOCK_METHOD(int, parse, (int argc, const char * const *argv), (override));
};


TEST(args, add_flag) {
  // todo: implement me
}

TEST(args, parse) {
  // todo: implement me
}
}
