#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int x, y;

int Max(int a, int b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}

int main() {
  cin >> x >> y;
  cout << Max(x, y) << endl;
  return 0;
}


