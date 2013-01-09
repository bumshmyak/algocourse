#include <iostream>

using std::cout;
using std::endl;

void PrintSeparator(char c, int n) {
  for (int i = 0; i < n; i++) {
    cout << c;
  }
  cout << endl;
}

int main() {
  PrintSeparator('#', 20);
  return 0;
}
