#include <iostream>

using namespace std;

const int MAXN = 1000;

int a[MAXN];
int n, k;

void output() {
  for (int i = 0; i < n; ++i) {
    cout << a[i];
  }
  cout << "\n";
}

void enumerate_all(int pos) {
  if (pos == n) {
    output();
  } else {
    for (int i = 0; i < k; ++i) {
      a[pos] = i;
      enumerate_all(pos + 1);
    }
  }
}

void enumerate_kry(int pos, int ones_left) {
  if (ones_left == 0 || ones_left == n - pos) {
    for (int i = pos; i < n; ++i) {
      a[i] = (ones_left != 0);
    }
    output();
  } else {
    a[pos] = 0;
    enumerate_kry(pos + 1, ones_left);
    a[pos] = 1;
    enumerate_kry(pos + 1, ones_left - 1);
  }
}

int main() {
  cin >> n >> k;
  enumerate_kry(0, k);
  
  cout << flush;
  
  return 0;
}
