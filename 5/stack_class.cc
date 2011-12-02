// rewrite to class
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

const int MAX_SIZE = 10000;

struct Stack {
  int elements[MAX_SIZE];
  int top_index;
  
  Stack() {
    top_index = 0;
  }
  
  void Clear();
  int Size();
  bool Empty();
  bool Push(int noob);
  bool Pop(int* r);
  bool Top(int* result);
};

int Stack::Size() {
  return top_index;
}

bool Stack::Empty() {
  return Size() == 0;
} 

// returns true if ok
// returns false if stack is full 
bool Stack::Push(int newbie) {
  if (Size() == MAX_SIZE) {
    return false;
  } else {
    elements[top_index] = newbie;
    ++top_index;
    return true;
  }
}

// returns true if ok
// return false if stack is empty
bool Stack::Pop(int* result) {
  if (Empty()) {
    return false;
  } else {
    *result = elements[top_index - 1];
    --(top_index);
    return true;
  }
}

// returns true if ok
// return false if stack is empty
bool Stack::Top(int* result) {
  if (Empty()) {
    return false;
  } else {
    *result = elements[top_index - 1];
    return true;
  }
}

int f() {
  Stack s1;
  s1.push(123);
}

int main() {
  for (;;) {
    string query;
    cin >> query;
    if (query == "push") {
      int t;
      cin >> t;
      s.Push(t);
      cout << "ok" << endl;
    } else if (query == "pop") {
      int result;
      if (!s.Pop(&result)) {
        cout << "error" << endl;
      } else {
        cout << result << endl;
      }
    } else if (query == "back") {
      int result;
      if (!s.Top(&result)) {
        cout << "error" << endl;
      } else {
        cout << result << endl;
      }
    } else if (query == "size") {
      cout << s.Size() << endl;
    } else if (query == "clear") {
      s.Clear();
      cout << "ok" << endl;
    } else if (query == "exit") {
      cout << "bye" << endl;
      return 0;
    }
  }
    
  return 0;
}
