#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const int MAX_SIZE = 10000;

struct Queue {
  int elements[MAX_SIZE];
  int elements_count;
  int head_index;
  int tail_index;
};

void Init(Queue* q) {
  q->elements_count = 0;
  q->head_index = 0;
  q->tail_index = 0;
}

void Clear(Queue* q) {
  q->elements_count = 0;
  q->head_index = 0; 
  q->tail_index = 0;
}

int Size(Queue* q) {
  return q->elements_count;
}

bool Empty(Queue* q) {
  return Size(q) == 0;
}

bool Enqueue(Queue* q, int newbie) {
  if (Size(q) == MAX_SIZE) {
    return false;
  } else {
    q->elements[q->tail_index] = newbie;
    q->tail_index = (q->tail_index + 1) % MAX_SIZE;
    ++q->elements_count;
    return true;
  }
}

bool Dequeue(Queue* q, int* result) {
  if (Empty(q)) {
    return false;
  } else {
    *result = q->elements[q->head_index];
    q->head_index = (q->head_index + 1) % MAX_SIZE;
    --q->elements_count;
    return true;
  }
}


int main() {
  Queue q;
  Init(&q);
  
  for (int i = 0; i < MAX_SIZE; ++i) {
    Enqueue(&q, i);
  }
  
  cout << Size(&q) << endl;
  
  for (int i = 0; i < MAX_SIZE; ++i) {
    int result;
    Dequeue(&q, &result);
    cout << result << ' ';
  }
  
  cout << endl;
  
  cout << Size(&q) << endl;
  
  
  for (int i = 0; i < 20; ++i) {
    Enqueue(&q, i);
    int result;
    Dequeue(&q, &result);
    cout << result << ' ';
  }
  cout << endl;
  
  for (int i = 0; i < 10; ++i) {
    if (!Enqueue(&q, i)) {
      cout << "no way" << endl;
    }
  }
  
  return 0;
}
