#include <iostream>
#include <stack>

using namespace std;

template <class T>
struct max_stack
{
  stack<T> s;
  stack<T> mx;

  void push( const T& x ) {
    s.push(x);
    if (mx.empty()) {
      mx.push(x);
    } else {
      mx.push(std::max(mx.top(), x));
    }
  }

  void pop() {
    s.pop();
    mx.pop();
  }

  T top() {
    return s.top();
  }

  T max() {
    return mx.top();
  }

  bool empty() {
    return s.empty();
  }
};

template <class T>
struct max_queue
{
  max_stack<T> left;
  max_stack<T> right;

  void push(const T& x) {
    left.push(x);
  }

  void pop() {
    if (right.empty()) {
      while (!left.empty()) {
        right.push(left.top());
        left.pop();
      }
    }
    right.pop();
  }

  T front() {
    if (right.empty()) {
      while (!left.empty()) {
        right.push(left.top());
        left.pop();
      }
    }
    return right.top();
  }

  T max() {
    T res;

    if (!left.empty()) {
      res = left.max();
      if (!right.empty()) {
        res = std::max(res, right.max());
      }
    }

    if ( !right.empty() ) {
      res = right.max();
      if ( !left.empty() ) {
        res = std::max(res, left.max());
      }
    }

    return res;
  }

  bool empty() {
    return left.empty() && right.empty();
  }
};

int main() {
  max_stack<int> s;
  return 0;
}
