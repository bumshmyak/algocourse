#include <iostream>
#include <string>

template <class T>
void swap(T& first, T& second) {
  T tmp;
  tmp = first;
  first = second;
  second = tmp;
}

int main() {
  int a = 1;
  int b = 2;
  swap(a, b);
  
  double x = 1.01;
  double y = 0.99;
  swap(a, b);
  
  return 0;
}
