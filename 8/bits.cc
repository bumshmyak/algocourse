#include <iostream>

using namespace std;

int main() {
  int A = (1 << 1) + (1 << 3);
  int B = (1 << 2) + (1 << 3);
  int C = 0;

  // union
  C = A | B;

  // intersection
  C = A & B;

  // subtruction
  C = A & ~B;

  int bit = 2;
  // set bit
  A |= (1 << bit);

  // clear bit
  A &= ~(1 << bit);

  // test bit
  if (A & (1 << bit)) {
    // bit is set
  }

  // count bits
  int c = __builtin_popcount(A);
  
  return 0;
}
