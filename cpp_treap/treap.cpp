#include <iostream>
#include <algorithm>

using namespace std;

struct treap {
  int key, prior;
  treap *l, *r;
  
  treap() :
    prior(rand()),
    l(0), r(0)
  { }
  
  treap(int new_key) :
    key(new_key),
    prior(rand()),
    l(0), r(0)
  { }
};

typedef treap* tree;

void split(tree t, int key, tree &l, tree &r) {
  if (!t)
    return void(l = r = 0);
  if (t->key < key) {
    split(t->r, key, t->r, r);
    l = t;
  } else {
    split(t->l, key, l, t->l);
    r = t;
  }
}

tree merge(tree l, tree r) {
  if (!l || !r)
    return l ? l : r;
  if (l->prior > r->prior) {
    l->r = merge(l->r, r);
    return l;
  } else {
    r->l = merge(l, r->l);
    return r;
  }
}

/* example */

void print_tree(tree t, int n = 0) {
  if (t) {
    print_tree(t->r, n + 1);
    for (int i = 0; i < n; i++)
      cout << "    ";
    cout << t->key << endl;
    print_tree(t->l, n + 1);
  }
}

int main() {
  tree t = 0;
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    tree newbie = new treap(i);
    t = merge(t, newbie);
  }
  print_tree(t);
  return 0;
}

/*  input:
20

    output:
            20
                19
        18
            17
    16
15
                14
                    13
            12
                    11
                10
                    9
        8
            7
                6
    5
            4
                3
                    2
        1
*/
