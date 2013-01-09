#include <iostream>
#include <vector>

using namespace std;

class DSU {
 public:
  DSU(int n);
  int Find(int x);
  int Union(int x, int y);

 private:
  vector<int> l;
};

DSU::DSU(int n) {
  l.resize(n);
  for (int i = 0; i < n; ++i) {
    l[i] = i;
  }
}
 
int DSU::Find(int x) {
  return x == l[x] ? x : (l[x] = Find(l[x]));
}

int DSU::Union(int x, int y) {
  l[Find(x)] = Find(y);
}

int main() {
  
  return 0;
}
