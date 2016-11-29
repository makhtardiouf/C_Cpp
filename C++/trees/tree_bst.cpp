/**
 Generic Binary Search Tree, BST
 Makhtar Diouf
 $Id$
 Build: make tree_bst
*/
#include "malib.hpp"
#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;

template <typename ValT> class BsTree {

private:
  typedef int KeyT; // tmp
  typedef struct Node {
    KeyT key; // Check the role and data type of the key
    ValT value;
    Node *parent;
    Node *left;
    Node *right;
  } Node;

public:
  Node *root = new Node;

  BsTree(KeyT k, ValT v) {
    Node nd;
    nd.key = k;
    nd.value = v;
  };

  BsTree<ValT>(vector<ValT> v) {
    std::sort(v.begin(), v.end());
    for (auto el : v)
      insert(el);
  }

  void insert(ValT val) {
    Node *newNode = new Node;
    newNode->value = val;
    newNode->left = newNode->right = nullptr;
    Node *parent = nullptr;

    // Newly created tree?
    if (root == nullptr) {
      root = newNode;
      return;
    }

    // ALL insertions are as leaf nodes
    Node *curr = root;
    // Find the Node's parent
    while (curr) {
      parent = curr;
      if (newNode->value > curr->value)
        curr = curr->right;
      else
        curr = curr->left;
    }

    if (newNode->value < parent->value)
      parent->left = newNode;
    else
      parent->right = newNode;

    printf("Inserted %d after %d\n", val, parent->value);
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

  void traverse(Node *nd) {
    if (nd == nullptr)
      return;
    cout << nd->value << "\n\t / \n\t";
    traverse(nd->left);

    cout << nd->value << "\n\t \\ \n\t";
    traverse(nd->right);
  }
};

int main() {
  vector<int> v{-1, 40, 22, 5, 9, 1, 10};
  printV(v);

  auto tree = new BsTree<int>(v);
  printf("Tree min: %d, max: %d\n", tree->getMin(), tree->getMax());
  return 0;
}
