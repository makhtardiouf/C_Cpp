/**
 Algo design manual, classic Tree data structure
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
    T value; // data
    struct node *parent;
    struct node *left;
    struct node *right;
  } node;  

public:
  node *root;
  
  Tree(T a) {
    node n;
    n.value = a;
  };
  
  Tree(vector<T> v) {
    // insert root
    insert(nullptr, v[0], nullptr);
    
    for (int i = 1; i < v.size(); i++)
      insert(&root, v[i], root);
    
    // traverse(&root);    
    cout << endl;
  }

  void insert(node **l, T x, node *parent) {
    node *p;
    if ((root == nullptr) || (*l == nullptr)) {
      p = new node; /* allocate new node */
      p->value = x;
      p->left = p->right = nullptr;
      p->parent = parent;

      // 1st node to be added to the node
      if (root == nullptr) {
        root = p;
      } else
        // link into parent’s record
        *l = p;

      return;
    }

    if (x < (*l)->value)
      insert(&((*l)->left), x, *l);
    else
      insert(&((*l)->right), x, *l);
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
      return (nullptr);
    min = t;
    // Keep going to the left till the last leaf
    while (min->left != nullptr)
      min = min->left;
    return (min);
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
  void printPostorder(node *p, int indent = 0) {
    if (p == nullptr) {
      cout << "No nodes detected at this position\n";
      return;
    }
    std::cout << p->value << "\n ";
    if (p->right) {
      std::cout << " \\\n" << ' ';
      printPostorder(p->right, indent + 4);
    }
    if (indent) {
      ; // std::cout << std::setw(indent) << ' ';
    }
    // if (p->right) std::cout<<" /\n" << std::setw(indent) << ' ';
    // std::cout<< p->value << "\n ";

    if (p->left) {
      std::cout << " /\n";
      printPostorder(p->left, indent + 4);
    }
  }
};

int main() {
  vector<int> v{4, 40, 2, 5, 3, 1, 10};
  printV(v);
  
  auto t = new Tree<int>(v);
  t->printPostorder(t->root);
  return 0;
}
