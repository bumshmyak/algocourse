#include <iostream>
#include <cassert>
#include <algorithm>

using std::cout;
using std::endl;
using std::cin;
using std::swap;

struct Node {
  int value;
  Node* next;
  Node* prev;
  
  Node(int _value) :
      value(_value),
      next(NULL),
      prev(NULL)
  { }
};

struct List {
  List() :
      head(NULL),
      size(0)
  { }

  ~List();
  
  void push_front(int value);
  Node* find(int value);
  void erase(Node* p);
  void reverse();
  int get_size() {
    return size;
  }

  void output();
  
  Node* head;
  int size;
};

void List::push_front(int value) {
  Node* newbie = new Node(value);
  if (head != NULL) {
    head->prev = newbie;
  }
  newbie->next = head;
  head = newbie;
  ++size;
}

Node* List::find(int value) {
  Node* p = head;
  while (p != NULL && p->value != value) {
    if (p->value == value) {
      break;
    }
    p = p->next;
  }
  return p;
}

void List::erase(Node* p) {
  assert(p != NULL);
  if (p->prev != NULL) {
    p->prev->next = p->next;
  } else {
    head = p->next;
  }
  if (p->next != NULL) {
    p->next->prev = p->prev;
  }
  --size;
}

void List::output() {
  for (Node* p = head; p != NULL; p = p->next) {
    cout << p->value << ' ';
  }
  cout << endl;
}

void List::reverse() {
  if (head == 0) {
    return;
  }
  
  Node* p = head;
  while (p->next != NULL) {
    Node* q = p->next;
    swap(p->next, p->prev);
    p = q;
  }
  
  head = p;
  swap(p->next, p->prev);
}


List::~List() {
  Node* p = head;
  while (p != NULL) {
    Node* q = p->next;
    delete p;
    p = q;
  }
}

int main() {
  const int N = 10;
  List l;

  for (int i = 0; i < N; ++i) {
    l.push_front(i);
  }

  assert(l.get_size() == N);

  cout << "original:" << endl;
  l.output();

  l.reverse();
  cout << "reversed:" << endl;
  l.output();
  
  for (int i = 0; i < N; ++i) {
    Node* p = l.find(i);
    l.erase(p);
    assert(l.get_size() == N - i - 1);
  }
  assert(l.get_size() == 0);

  return 0;
}



