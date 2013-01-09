#include <iostream>
#include <cassert>

using std::cout;
using std::endl;
using std::cin;

struct Node {
  int value;
  Node* next;
  
  Node(int _value) :
      value(_value),
      next(NULL)
  { }
};

struct Slist {
  Slist() :
      head(NULL),
      size(0)
  { }

  ~Slist();
  
  void push_front(int value);
  Node* find(int value);
  void reverse();
  int get_size() {
    return size;
  }

  void output();
  
  Node* head;
  int size;
};

void Slist::push_front(int value) {
  Node* newbie = new Node(value);
  newbie->next = head;
  head = newbie;
  ++size;
}

Node* Slist::find(int value) {
  Node* p = head;
  while (p != NULL && p->value != value) {
    if (p->value == value) {
      break;
    }
    p = p->next;
  }
  return p;
}

void Slist::output() {
  for (Node* p = head; p != NULL; p = p->next) {
    cout << p->value << ' ';
  }
  cout << endl;
}

void Slist::reverse() {
  if (head == NULL) {
    return;
  }
  
  Node* p = head;
  Node* q = head->next;
  p->next = NULL;
  while (q != NULL) {
    Node* r = q->next;
    q->next = p;
    p = q;
    q = r;
  }
  head = p;
}

Slist::~Slist() {
  Node* p = head;
  while (p != NULL) {
    Node* q = p->next;
    delete p;
    p = q;
  }
}

int main() {
  const int N = 10;
  Slist l;

  for (int i = 0; i < N; ++i) {
    l.push_front(i);
  }
  assert(l.get_size() == N);

  cout << "original:" << endl;
  l.output();

  l.reverse();
  cout << "reversed:" << endl;
  l.output();
  assert(l.get_size() == N);
  
  for (int i = 0; i < N; ++i) {
    assert(l.find(i) != NULL);
  }
  assert(l.find(N) == NULL);

  return 0;
}



