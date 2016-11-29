/**
 Generic Binary Search Tree, BST = tree in symmetric order
 Makhtar Diouf
 $Id$
 Build: make bstree
*/
#include "malib.hpp"
#include <algorithm>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <ctype.h>
using namespace std;

template <typename ValT> class BsTree {

private:
  typedef int KeyT; // tmp
  typedef struct Node {
    /**
    @todo: Check the role and data type of the key
    could be an index assigned when building the tree
    */
    KeyT key;
    ValT value;
    Node *parent, *left, *right;

    Node(ValT val) {
      value = val;
      parent = left = right = nullptr;
    };
  } Node;

public:
  Node *root = new Node((ValT)0);

  BsTree(){};

  BsTree(KeyT k, ValT v) {
    Node nd;
    nd.key = k;
    nd.value = v;
  };

  template <typename T> BsTree(T v) {
    std::sort(v.begin(), v.end());
    for (auto el : v)
      insert(el);
  }

  void insert(ValT val) {
    Node *newNode = new Node(val);

    // Newly created tree?
    if (root == nullptr) {
      root = newNode;
      return;
    }

    // ALL insertions are as leaf nodes
    Node *cur = root;
    Node *parent = nullptr;

    // Find the Node's parent; @Todo check for duplicates using the key
    while (cur) {
      parent = cur;
      if (newNode->value > cur->value)
        cur = cur->right;
      else
        cur = cur->left;
    }

    if (newNode->value < parent->value)
      parent->left = newNode;
    else
      parent->right = newNode;

    cout << "Inserted " << val << " after " << parent->value << endl;
  }

  // O(log N) complexity
  Node *search(Node *nd, ValT x) {
    if (nd == nullptr)
      return nd;
    if (nd->value == x)
      return nd;

    if (x < nd->value)
      return search(nd->left, x);
    else
      return search(nd->right, x);
  }

  ValT getMin(Node *min = nullptr) {
    if (!min)
      min = root;

    // Traverse towards the left till the last leaf
    while (min->left)
      min = min->left;
    return min->value;
  }

  ValT getMax(Node *max = nullptr) {
    if (!max)
      max = root;

    // Traverse towards the right, till last leaf
    while (max->right)
      max = max->right;
    return max->value;
  }

  // Pre-order traversal - should indent depending on the level
  void traverse(Node *nd) {
    if (!nd)
      return;
    cout << "\t  " << nd->value << "\n\t / ";
    traverse(nd->left);

    cout << "\t \\ ";
    traverse(nd->right);
    cout << endl;
  }
};

int main() {
  vector<int> v{-1, 40, 22, 5, 9, 1, 10};
  printV(v);

  auto tree = new BsTree<int>(v);
  // tree->traverse(tree->root);
  printf("Tree min: %d, max: %d\n", tree->getMin(), tree->getMax());

  printf("\nTree of chars:\n");
  auto ctree = new BsTree<char>();
  for (int i = 0; i < 40; i++) {
    char c = (char)(rand() % 120);
    if(isalpha(c))
    ctree->insert(c);
  }
  printf("Tree min: %c, max: %c\n", ctree->getMin(), ctree->getMax());

  return 0;
}
