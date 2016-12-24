/**
Check if 2 trees a, b are mirrors of each other

Their root node’s key must be same
Left subtree of root of ‘a’ and right subtree root of ‘b’ are mirror.
Right subtree of ‘a’ and left subtree of ‘b’ are mirror.
http://www.geeksforgeeks.org/check-if-two-trees-are-mirror/

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

bool isTreeMirrored(Node *a, Node *b) {
  // Base cases
  if (a == nullptr && b == nullptr)
    return true;

  if (a == nullptr || b == nullptr)
    return false;

  printf("\t\nCHK T1->%c && T2->%c", a->data, b->data);
  return (a->data == b->data) && isTreeMirrored(a->left, b->right) &&
         isTreeMirrored(a->right, b->left);
}

int main() {
  // Manually build the trees for testing

  auto a = new Node('a'); // root
  a->left = new Node('I');
  a->right = new Node('J');
  a->right->right = new Node('K');

  auto b = new Node('a'); // root
  b->right = new Node('I');
  b->left = new Node('J');
  b->left->left = new Node('K');

  cout << " Trees a, b are mirrors? "
       << (isTreeMirrored(a, b) == 0 ? "\nfalse" : "\ntrue") << endl;

  auto c = b;
  c->left = new Node('X');
  cout << " Trees a, c are mirrors?"
       << (isTreeMirrored(a, c) == 0 ? "\nfalse" : "\ntrue") << endl;

  return 0;
}
