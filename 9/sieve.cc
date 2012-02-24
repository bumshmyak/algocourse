#include <iostream>

using namespace std;

const int LIM = 100001;

bool prime[LIM];

void sieve(int n) {
  prime[1] = false;
  for (int i = 2; i <= n; ++i) {
    prime[i] = true;
  }
  
  for (int i = 2; i * i <= n; ++i) {
    if (prime[i]) {
      for (int j = i * i; j <= n; j += i) {
        prime[j] = false;
      }
    }
  }
}

int main() {
  int n = 100;
  sieve(n);
  for (int i = 1; i <= n; ++i) {
    if (prime[i]) {
      cout << i << ' ';
    }
  }
  cout << endl;

  return 0;
}
