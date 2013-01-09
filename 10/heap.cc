#include <iostream>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <queue>

using namespace std;

class Heap {
 public:
  Heap();
  void push(int v);
  void pop();
  int top();
  
  bool empty() {
    return a.size() == 1;
  }
  
 private:
  vector<int> a;

  void sift_up(int n);
  void sift_down(int n);
};

Heap::Heap() {
  a.push_back(0);
}

void Heap::sift_up(int n) {
  while (n > 1 && a[n] > a[n / 2]) {
    swap(a[n], a[n / 2]);
    n /= 2;
  }
}

void Heap::push(int v) {
  a.push_back(v);
  int n = a.size() - 1;
  sift_up(n);
}

void Heap::sift_down(int n) {
  while (2 * n < a.size()) {
    if (2 * n + 1 < a.size()) {
      int mx = n;
      if (a[2 * n] > a[mx]) {
        mx = 2 * n;
      }
      if (a[2 * n + 1] > a[mx]) {
        mx = 2 * n + 1;
      }
      if (mx != n) {
        swap(a[n], a[mx]);
        n = mx;
      } else {
        break;
      }
    } else {
      if (a[2 * n] > a[n]) {
        swap(a[2 * n], a[n]);
        n = 2 * n;
      } else {
        break;
      }
    }
  }
}

void Heap::pop() {
  assert(!empty());
  swap(a[1], a[a.size() - 1]);
  a.pop_back();
  sift_down(1);
}

int Heap::top() {
  assert(!empty());
  return a[1];
}

int main() {
  const int N = 10;
  const int M = 10;
  vector<int> r(N);
  for (int i = 0; i < N; ++i) {
    r[i] = rand() % M;
    cout << r[i] << ' ';
  }
  cout << endl;

  Heap h;
  
  for (int i = 0; i < N; ++i) {
    h.push(r[i]);
  }

  for (int i = 0; i < N; ++i) {
    cout << h.top() << ' ';
    h.pop();
  }
  cout << endl;

  assert(h.empty());

  priority_queue<int> q;
  for (int i = 0; i < N; ++i) {
    h.push(r[i]);
    q.push(r[i]);
    assert(h.top() == q.top());
  }

  for (int i = 0; i < N; ++i) {
    assert(h.top() == q.top());
    h.pop();
    q.pop();
  }
  
  
  return 0;
}
