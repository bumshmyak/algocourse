#include <iostream>
#include <limits>

using std::cout;
using std::endl;

void sep(int n, char c) {
  for (int i = 0; i < n; ++i) {
    cout << c;
  }
  cout << endl;
}

void inc(int* p) {
  (*p)++;
}

void swap(int* x, int* y) {
  int z = *x;
  *x = *y;
  *y = z;
}

int foo(int *x) {
  cout << x << endl;
  ++x;
  cout << x << endl;
}

void dec(int& x) {
  x--;
}

int main() {
  
  // ++, --
  {
    int a = 10;
    int x = ++a; // a = a + 1; return a;
    cout << "x = " << x << ", a = " << a << endl;
    int y = a++; // t = a; a = a + 1; return t;
    cout << "y = " << y << ", a = " << a << endl;
  }
  
  sep(40, '-');
  
  // +=, -=, *=, %=
  {
    int a = 2;
    a += 2; // a = a + 2;
    cout << "a = " << a << endl;
    a /= 4;
    cout << "a = " << a << endl; 
  }
  
  sep(40, '-');
  
  // basic types
  cout << "bool size = " << sizeof(bool) << endl
       << "char size = " << sizeof(char) << endl
       << "short int size = " << sizeof(short) << endl
       << "int size = " << sizeof(int) << endl
       << "long long size = " << sizeof(long long) << endl
       << "float size = " << sizeof(float) << endl
       << "double size = " << sizeof(double) << endl;
  
  
  // signed/unsigned
  // sizeof(signed T) == sizeof(unsigned T) == sizeof(T)
  {
    signed char x = -1; // = char, [-128; 127]
    unsigned char y = 192; // [0; 255]
  }
  
  // short/long
  // sizeof(short T) <= sizeof(T) <= sizeof(long T)
  // short int == short
  // long int == long
  
  sep(40, '-');
  
  // pointers
  {
    int a = 97;
    int* p = &a;
    
    cout << "p = " << p << endl;
    cout << "sizeof(p) = " << sizeof(p) << endl;
    
    cout << "*p = " << *p << endl;
    
    char* q = (char*)&a;
    
    cout << "*q = " << *q << endl;
    *q = 'b'; 
    
    cout << "*q = " << *q << endl;
    q += 2;
    *q = 'c';
    
    cout << "*p = " << *p << endl;
  
    ++p;
    cout << "after increment p = " << p << endl;
    cout << "garbage at *p = " << *p << endl;
    
    char* pc = (char*)(&a);
    cout << "*pc = " << *pc << endl;
  
    int* x, y; // never do this!!!
  }
  
  sep(40, '-');
  
  // why pointers are useful?
  {
    int x = 0;
    cout << "before inc x = " << x << endl;
    inc(&x);
    cout << "after inc x = " << x << endl;
    
    int first = 1;
    int second = 2;
    cout << "before swap, first = " << first
         << ", second = " << second << endl;
    swap(&first, &second);
    cout << "after swap, first = " << first
         << ", second = " << second << endl;    
  }
  
  
  sep(40, '-');
  
  // references
  {
    int a = 5;
    int& r = a;
    ++r;
    cout << "r = " << r << endl;
    cout << "a = " << a << endl;
  }
  
  sep(40, '-');
  
  // pass parameters by reference
  {
    int t = 10;
    dec(t);
    cout << "t = " << t << endl;
  }
  
  sep(40, '-');
  
  // arrays
  {
    int m[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    cout << "m = " << m << endl;
    int* p = m;
    cout << "p = " << p << endl;
    cout << "*p = " << *p << endl;
    
    // m[i] <=> *(m + i)
    for (int i = 0; i < 12; ++i) {
      cout << *(m + i) << ' ';
    }
    cout << endl;
    
    for (int* p = m; p != m + 12; ++p) {
      cout << *p << ' ';
    }
    cout << endl;
  }
   
  return 0;
}
