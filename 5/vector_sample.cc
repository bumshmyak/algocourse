#include <iostream>
#include <vector> // !!!

using std::cout;
using std::endl;
using std::cin;
using std::vector; // !!!

int main() {
  // general use
  {
    int n = 10;
    vector<int> a(n); // it's ctor, not a[n]!!!
  
    for (int i = 0; i < n; ++i) {
      a[i] = i * i;
    }
  
    a.push_back(3);
    a.push_back(4);
  
    int elements_count = a.size();
  }
  
  // empty check
  {
    vector<int> b;
    bool is_empty = b.empty();
  }
  
  // initialization
  {
    int n = 5;
    vector<int> c(n, 42); // set all elements to 42
    for (int i = 0; i < c.size(); ++i) {
      if (c[i] != 42) {
        cout << "should never happen" << endl;
        return 1;
      }
    }
  }
  
  return 0;
}
