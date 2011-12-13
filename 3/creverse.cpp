#include <iostream>

using std::cout;
using std::endl;
using std::cin;

void Swap(int& a, int& b) {
  int c;
  c = a;
  a = b;
  b = c;
}

void InputArray(int* a, int& n) {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
}

void OutputArray(int* a, int n) {
  for (int i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }
  cout << endl;
}

void Reverse(int* a, int n) {
  for (int i = 0; i < n / 2; i++) {
    Swap(a[i], a[n - i - 1]);
  }
}

int main() {
  int data[100];
  int n;
  InputArray(data, n);
  Reverse(data, n);
  OutputArray(data, n);
  return 0;
}
