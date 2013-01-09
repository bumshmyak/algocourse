#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int n;
  cin >> n;
  for (int msk = 0; msk < (1 << n); ++msk) {
    for (int i = 0; i < n; ++i) {
      if (msk & (1 << i)) {
        cout << 1;
      } else {
        cout << 0;
      }
    }
    cout << endl;
  }
  
  return 0;
}
