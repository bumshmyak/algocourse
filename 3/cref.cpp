#include <iostream>

using std::cout;
using std::endl;

void Swap(int& a, int& b) {
  int c;
  c = a;
  a = b;
  b = c;
}

int main() {
  int x, y;
  x = 1;
  y = 2;
  Swap(x, y);
  cout << x << ' ' << y << endl;
  return 0;
}
