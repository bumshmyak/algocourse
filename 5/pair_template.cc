#include <iostream>
#include <string>

using namespace std;

template <class T, class U>
class MyPair {
 public:
	T first;
	U second;
	MyPair(T _first, U _second) :
		first(_first),
		second(_second)
   { }
};

int main() {
	MyPair<int, int> a(1, 2);
	
	cout << a.first << ' ' << a.second << endl;
	
	MyPair<string, double> b("answer", 42);
	cout << b.first << ' ' << b.second << endl;
	
	return 0;
}




