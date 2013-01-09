#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const int MAX_SIZE = 1000;

struct Stack {
  int elements[MAX_SIZE];
  int top_index;
};

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
  
  for (int i = 0; i < 10; ++i) {
    Push(&s, i);
  }
  
  cout << Size(&s) << endl;

  for (int i = 0; i < 10; ++i) {
    int top_element;
    Pop(&s, &top_element);
    cout << top_element << ' ';
  }
  cout << endl;
   
  cout << Size(&s) << endl;
       
  return 0;
}



