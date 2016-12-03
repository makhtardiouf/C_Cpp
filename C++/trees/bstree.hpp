/**
 Generic Binary Search Tree, BST = tree in symmetric order
 Makhtar Diouf
 $Id$
 Build: make bstree
*/
#ifndef BSTREE_HPP
#define BSTREE_HPP

#include "malib.hpp"
#include <cstdlib>
#include <ctype.h>
#include <initializer_list>
#include <iomanip>
#include <queue>

using namespace std;

template <typename ValT> class BsTree {

private:
  typedef int KeyT; // tmp

  /**
  Tree Node
  @todo: Check the role and data type of the key
  could be an index assigned when building the tree
  */
  typedef struct Node {
    KeyT key;
    ValT data;
    Node *parent, *left, *right;
    int N = 0; // Nodes in subtree

    Node(ValT val) {
      data = val;
      parent = left = right = nullptr;
    };
  } Node;

  int size(Node x) {
    if (x == null)
      return 0;
    return x.N;
  }

  void insert(ValT val);

  inline int rank(KeyT key) { return rank(key, root); }

    inline void delete(Key key){ root = delete(root, key); }

public:
  Node *root = new Node((ValT)0);

  // Constructors
  BsTree(){};
  BsTree(KeyT k, ValT v);
  template <typename T> BsTree(T v);

  // Operations
  Node *insert(Node *x, ValT val);
  Node *search(Node *nd, ValT x);
  int rank(KeyT key, Node x);
  Node delete(Node x, Key key) ;

  ValT getMin(Node *min = nullptr);
  ValT getMax(Node *max = nullptr);

  void traversePreOrder(Node *nd);

  inline int size() { return size(root); }

  queue<KeyT> keys();

// == One type of DFS without looking for a particular element
  void inOrderTraversal(Node x, queue<KeyT> q);

};

#endif
