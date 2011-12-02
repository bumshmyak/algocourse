#include <iostream>

using namespace std;

struct Point {
  int x;
  int y;
};

int main() {
  Point* p = new Point;
  p->x = 0;
  p->y = 0;
  delete p;
  
  int* q = new int;
  *q = 5;
  delete q;
 
  return 0;
}
