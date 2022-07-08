#include <iostream>
#include <version.hpp>

int main() {

  using namespace std;
  using namespace stub;

  cout << version::current() << endl;
  return 0;
}
