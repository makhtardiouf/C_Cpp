/**
 Algo design manual, classic Tree value structure
 Makhtar Diouf
 $Id$
 Build: make tree
*/
#include "malib.hpp"
#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;

template <typename T> class Tree {
  // A Tree of trees/nodes

private:
  typedef struct node {
    T value; // value
    struct node *parent;
    struct node *left;
    struct node *right;
  } node;

public:
  node *root = new node;

  Tree(T a) {
    node n;
    n.value = a;
  };

  Tree(vector<T> v) {
    for (int i = 1; i < v.size(); i++)
      insert(v[i]);
    cout << endl;
  }

  void insert(int d) {
    node *t = new node;
    t->value = d;
    t->left = t->right = nullptr;
    node *parent = nullptr;

    // is this a new tree?
    if (root == nullptr)
      root = t;
    else {
      // Note: ALL insertions are as leaf nodes
      node *curr;
      curr = root;
      // Find the Node's parent
      while (curr) {
        parent = curr;
        if (t->value > curr->value)
          curr = curr->right;
        else
          curr = curr->left;
      }

      if (t->value < parent->value)
        parent->left = t;
      else
        parent->right = t;
    }
  }

  node *search(node *l, T x) {
    if (l == nullptr)
      return (nullptr);
    if (l->value == x)
      return (l);

    if (x < l->value)
      return (search(l->left, x));
    else
      return (search(l->right, x));
  }

  node *getMin(node *t) {
    node *min;
    // pointer to minimum
    if (t == nullptr)
      return nullptr;

    min = t;
    // Keep going to the left till the last leaf
    while (min->left != nullptr)
      min = min->left;
    return min;
  }

  void traverse(node **l) {
    if (*l == nullptr)
      return;
    cout << (*l)->value << "\n\t / \n\t";
    traverse(&(*l)->left);
    // processvalue(l->value);
    cout << (*l)->value << "\n\t \\ \n\t";
    traverse(&(*l)->right);
  }

  // Pretty-printing
  // http://stackoverflow.com/questions/13484943/print-a-binary-tree-in-a-pretty-way
  void printPorder(node *p = nullptr, int indent = 4) {
    if (p == nullptr)
      p = root;
    if (p->right)
      printPorder(p->right, indent + 4);

    if (indent)
      std::cout << std::setw(indent) << ' ';
    if (p->right)
      std::cout << " /\n" << std::setw(indent) << ' ';

    std::cout << p->value << "\n ";
    if (p->left) {
      std::cout << std::setw(indent) << ' ' << " \\\n";
      printPorder(p->left, indent + 4);
    }
  }
};

int main() {
  vector<int> v{4, 40, 2, 5, 3, 1, 10};
  printV(v);

  auto t = new Tree<int>(v);
  t->printPorder();
  return 0;
}
