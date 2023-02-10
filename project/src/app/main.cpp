#include <entrance.hpp>

int main(int argc, const char** argv) {
  auto entrance = stub::entrance(argc, argv);
  return entrance.enter();
}
