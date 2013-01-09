#include <iostream>
#include <cmath>

using namespace std;

class Point {
 public:
  
  // default constructor
  Point() {
    x = 0;
    y = 0;
  }
 
  // constructor with parameters
  Point(int _x, int _y) {
    x = _x;
    y = _y;
  };
  
  // TODO: show initialization list
  
  double distance() {
    return sqrt(x * x + y * y);
  }
  
  double x, y;
};

bool operator==(const Point& first, const Point& second) {
  return (first.x == second.x) && (first.y == second.y);
}

ostream& operator<<(ostream& out, const Point& p) {
  out << '(' << p.x << ';' << p.y << ')';
  return out;
}

istream& operator>>(istream& in, Point& p) {
  in >> p.x >> p.y;
  return in;
} 

int main() {
  Point a;
  Point b(1, 2);
  cin >> a;
  if (a == b) {
    cout << "point " << a << " is equal to  point " << b << endl;
  } else {
    cout << "point " << a << " is not equal to point " << b << endl;
  }
  return 0;
}
