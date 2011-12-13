#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

bool b;
char c;
int n;
long long m;
double x;
string s;
int a[10]; // a[0], ..., a[9]

int main() {
  b = true;
  c = 'a';
  n = 1000;
  m = 1000000000;
  x = 3.14;
  s = "mnogo bykv";
  a[0] = 5;
  
  cout << "b = " << b << endl
       << "c = " << c << endl
       << "n = " << n << endl
       << "m = " << m << endl
       << "x = " << x << endl
       << "s = " << s << endl
       << "a[0] = " << a[0] << endl;
  
  return 0;
}
