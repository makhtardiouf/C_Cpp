/**
Utility functions for BST

*/
#include "bstree.hpp"

typedef BsTree::Node Node;

template <typename ValT> template <typename T> BsTree<ValT>::BsTree(T v) {
  std::sort(v.begin(), v.end());
  printV(v);

  // Use mid element as root, to balance the tree
  root = new Node((ValT)v[v.size() / 2]);
  v.erase(v.begin() + v.size() / 2);

  for (auto el : v)
    insert(el);
}

/**
Insert vis-a-vis node x, downward
@Todo complete
*/
template <typename ValT>
BsTree::Node *BsTree<ValT>::insert(BsTree::Node *x, ValT val) {
  if (!x)
    return x;

  int cmp = val - x->data;
  if (cmp > 0) {
    x->right = insert(x->right, val);
  } else if (cmp < 0) {
    x->left = insert(x->left, val);
  } else
    x->data = val; // update

  return x;
}

template <typename KeyT> int BsTree<KeyT>::rank(KeyT key, BsTree::Node x) {
  if (x == nullptr)
    return 0;
  int cmp = key.compareTo(x.key);
  if (cmp < 0)
    return rank(key, x.left);

  else if (cmp > 0)
    return 1 + size(x.left) + rank(key, x.right);
  else
    return size(x.left);
}

template <typename KeyT> queue<KeyT> BsTree<KeyT>::keys() {
  queue<KeyT> q = new queue<KeyT>();
  inorder(root, queue);
  return q;
}

template <typename KeyT> void BsTree<KeyT>::inOrderTraversal(Node x, queue<KeyT> q) {
  if (x == nullptr)
    return;
  inorder(x.left, q);
  q.push(x.key);
  inorder(x.right, q);
}
