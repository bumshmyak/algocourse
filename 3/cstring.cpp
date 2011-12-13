#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main() {
  string s = "The quick brown fox jumps over the lazy dog";
  
  int n = s.length();
  cout << "length = " << n << endl;
  
  // выделение подстроки
  string p = s.substr(0, 19);
  cout << p << endl;
  
  // удаление подстроки
  p.erase(4, 6);
  cout << p << endl;
  
  // поиск подстроки
  int w = p.find("brown");
  cout << w << endl;
  w = p.find("red");
  cout << w << endl;
  
  // вставка подстроки
  p.insert(p.length(), " and bear");
  cout << p << endl;
  
  return 0;
}
