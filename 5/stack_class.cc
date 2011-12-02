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
}; // !!

void Init(Stack* s) {
  s->top_index = 0; // something->member <=> (*something).member
}

void Clear(Stack* s) {
  s->top_index = 0;
}

int Size(Stack* s) {
  return s->top_index;
}

bool Empty(Stack* s) {
  return Size(s) == 0;
} 

// returns true if ok
// returns false if stack is full 
bool Push(Stack* s, int newbie) {
  if (Size(s) == MAX_SIZE) {
    return false;
  } else {
    s->elements[s->top_index] = newbie;
    ++(s->top_index);
    return true;
  }
}

// returns true if ok
// return false if stack is empty
bool Pop(Stack* s, int* result) {
  if (Empty(s)) {
    return false;
  } else {
    *result = s->elements[s->top_index - 1];
    --(s->top_index);
    return true;
  }
}

// returns true if ok
// return false if stack is empty
bool Top(Stack* s, int* result) {
  if (Empty(s)) {
    return false;
  } else {
    *result = s->elements[s->top_index - 1];
    return true;
  }
}

int main() {
  Stack s;
  
  Init(&s);
  
  for (;;) {
    string query;
    cin >> query;
    if (query == "push") {
      int t;
      cin >> t;
      Push(&s, t);
      cout << "ok" << endl;
    } else if (query == "pop") {
      int result;
      if (!Pop(&s, &result)) {
        cout << "error" << endl;
      } else {
        cout << result << endl;
      }
    } else if (query == "back") {
      int result;
      if (!Top(&s, &result)) {
        cout << "error" << endl;
      } else {
        cout << result << endl;
      }
    } else if (query == "size") {
      cout << Size(&s) << endl;
    } else if (query == "clear") {
      Clear(&s);
      cout << "ok" << endl;
    } else if (query == "exit") {
      cout << "bye" << endl;
      return 0;
    }
  }
    
  return 0;
}
