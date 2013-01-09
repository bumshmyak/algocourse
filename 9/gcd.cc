#include <iostream>

using namespace std;

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

int gcd_nonrec(int a, int b) {
  while (b) {
    int r = a % b;
    a = b;
    b = r;
  }
  return a;
}

void gcd_extended(int a, int b, int& d, int& x, int& y) {
  if (b == 0) {
    d = a, x = 1, y = 0;
  } else {
    int x1, y1;
    gcd_extended(b, a % b, d, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
  }
}

int main() {

  return 0;
}
