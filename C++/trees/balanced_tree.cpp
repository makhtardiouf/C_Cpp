/**
Balanced tree:
no two leaf nodes differ in distance from the root by more than 1.
i.e left and right subtrees of any node are the same height (or diff by 1).

Improved over C.T.I. P115
Makhtar
*/
#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

class Node {
public:
  char data;
  Node *left, *right;

  Node(char val) {
    data = val;
    left = right = nullptr;
  };
};

int chkDepth(Node *T) {
  static int depth = 0;
  if (!T)
    return 0;
  depth++;

  printf("\t\nCHK depth: %d -> %c", depth, T->data);
  return 1 + std::max(chkDepth(T->left), chkDepth(T->right));
}

// In one go
bool isBalanced(Node *T) {
  auto depth = std::minmax(chkDepth(T->left), chkDepth(T->right));

  printf("\t\nminDepth: %d, maxDepth: %d", depth.first, depth.second);

  return (depth.second - depth.first) <= 1;
}

int main() {
  // Manually build the trees for testing

  auto a = new Node('a'); // root
  a->left = new Node('I');
  a->left->left = new Node('Z');

  a->right = new Node('J');
  a->right->right = new Node('K');
  a->right->right->right = new Node('L');

  cout << " Tree is " << (isBalanced(a) ? "\n" : "\nNOT") << " Balanced \n";

  return 0;
}