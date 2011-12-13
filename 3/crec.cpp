#include <iostream>

using std::cout;
using std::endl;

int f(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * f(n - 1);
  }
}

int main() {
  cout << f(3) << endl;
  return 0;
}
