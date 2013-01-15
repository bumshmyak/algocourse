#include <iostream>
#include <algorithm>

using namespace std;

const int BLACK = 0;
const int RED = 1;

struct node {
  int data, color;
  node *parent, *left, *right;
  
  node() :
    color(RED),
    parent(0),
    left(0),
    right(0)
  { }
  
  node(int data) :
    data(data),
    color(RED),
    parent(0),
    left(0),
    right(0)
  { }
};

typedef node* ref;

ref root = 0;

ref get_grandparent(ref self) {
  if (self->parent)
    return self->parent->parent;
  else
    return 0;
}

ref get_uncle(ref self) {
  ref gp = get_grandparent(self);
  if (gp)
    if (gp->left == self->parent)
      return gp->right;
    else
      return gp->left;
  else
    return 0;
}

int get_color(ref self) {
  if (!self)
    return BLACK;
  else
    return self->color;
}

void set_color(ref &self, int color) {
  if (self)
    self->color = color;
}

void set_parent(ref &self, ref parent) {
  if (self)
    self->parent = parent;
}

void set_left(ref self, ref left) {
  if (self)
    self->left = left;
}

void set_right(ref self, ref right) {
  if (self)
    self->right = right;
}

void left_rotate(ref self) {
  ref newself = self->right;
  ref buffer = newself->left;
  ref parent = self->parent;
  
  set_parent(self, newself);
  set_parent(newself, parent);
  set_parent(buffer, self);
  
  set_right(self, buffer);
  set_left(newself, self);
  
  if (parent) {
    if (parent->left == self)
      set_left(parent, newself);
    else
      set_right(parent, newself);
  } else {
    root = newself;
  }
}

void right_rotate(ref self) {
  ref newself = self->left;
  ref buffer = newself->right;
  ref parent = self->parent;
  
  set_parent(self, newself);
  set_parent(newself, parent);
  set_parent(buffer, self);
  
  set_left(self, buffer);
  set_right(newself, self);
  
  if (parent) {
    if (parent->left == self)
      set_left(parent, newself);
    else
      set_right(parent, newself);
  } else {
    root = newself;
  }
}

void fix_up(ref self) {
  while (get_color(self->parent) == RED) {
    ref gp = get_grandparent(self);
    if (!gp)
      return (void) set_color(self->parent, BLACK);
    ref uncle = get_uncle(self);
    ref parent = self->parent;
    if (get_color(uncle) == RED) {
      set_color(uncle, BLACK);
      set_color(parent, BLACK);
      set_color(gp, RED);
    } else {
      set_color(gp, RED);
      set_color(parent, BLACK);
      if (self->parent == gp->right) {
        if (self == self->parent->left)
          right_rotate(self->parent);
        left_rotate(gp);
      } else {
        if (self == self->parent->right)
          left_rotate(self->parent);
        right_rotate(gp);
      }
    }
    self = gp;
  }
}

void insert(ref &self, int x) {
  ref it = self;
  ref prev = 0;
  while (it) {
    prev = it;
    if (it->data < x)
      it = it->right;
    else
      it = it->left;
  }
  ref newbie = new node(x);
  if (!prev) {
    self = newbie;
  } else {
    if (prev->data < x)
      prev->right = newbie;
    else
      prev->left = newbie;
  }
  set_parent(newbie, prev);
  fix_up(newbie);
  set_color(root, BLACK);
}

void print(ref self, int n = 0) {
  if (self) {
    print(self->right, n + 1);
    for (int i = 0; i < n; i++)
      cout << "    ";
    cout << self->data << ',' << (get_color(self) == RED ? "RED" : "BLACK") << endl;
    print(self->left, n + 1);
  }
}

int main() {
  for (int i = 1; i <= 200; i += 2) {
    insert(root, i);
  }
  for (int i = 200; i >= 1; i -= 2) {
    insert(root, i);
  }
  print(root);
  return 0;
}
