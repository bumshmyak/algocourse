#include <iostream>
#include <cmath>

using namespace std;

#if 0
double pow(double a, int n) {
  if (n == 0) {
    return 1;
  }
  if (n == 1) {
    return a;
  }
  double t = pow(a, n / 2);
  return t * t * pow(a, n % 2);
}

double pow_nonrec(double a, int n) {
  double r = 1;
  while (n) {
    if (n % 2 == 1) {
      r *= a;
    }
    a *= a;
    n /= 2;
  }
  return r;
}
#endif


int main() {
  int a, n;
  cin >> a >> n;
  cout << a << " = " << (a / n) << "*" << n << "+" << a % n << endl; 
  return 0;
}
