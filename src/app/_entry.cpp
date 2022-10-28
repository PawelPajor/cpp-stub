#include <cli.hpp>

int main(int argc, const char** argv) {
  stub::cli cli;
  return cli.parse(argc, argv);
}
