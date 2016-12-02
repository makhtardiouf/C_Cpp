/**
 Generic Binary Search Tree, BST = tree in symmetric order
 Makhtar Diouf
 $Id$
 Build: make bstree
*/
#include "malib.hpp"
#include <cstdlib>
#include <ctype.h>
#include <initializer_list>
#include <iomanip>
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

    Node(ValT val) {
      data = val;
      parent = left = right = nullptr;
    };
  } Node;

public:
  Node *root = new Node((ValT)0);

  // Constructors
  BsTree(){};

  BsTree(KeyT k, ValT v) {
    Node nd;
    nd.key = k;
    nd.data = v;
  };

  template <typename T> BsTree(T v) {
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
  Node *insert(Node *x, ValT val) {
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
      if (newNode->data > cur->data)
        cur = cur->right;
      else
        cur = cur->left;
    }

    if (val < parent->data)
      parent->left = newNode;
    else
      parent->right = newNode;

    cout << "Inserted " << val << " after " << parent->data << endl;
  }

  // O(log N) complexity
  Node *search(Node *nd, ValT x) {
    if (nd == nullptr)
      return nd;
    if (nd->data == x)
      return nd;

    if (x < nd->data)
      return search(nd->left, x);
    else
      return search(nd->right, x);
  }

  ValT getMin(Node *min = nullptr) {
    if (!min)
      min = root;

    // traversePreOrder towards the left till the last leaf
    while (min->left)
      min = min->left;
    return min->data;
  }

  ValT getMax(Node *max = nullptr) {
    if (!max)
      max = root;

    // traversePreOrder towards the right, till last leaf
    while (max->right)
      max = max->right;
    return max->data;
  }

  // Pre-order traversal - should indent depending on the level
  void traversePreOrder(Node *nd) {
    if (!nd)
      return;
    cout << "\t  " << nd->data << "\n\t / ";
    traversePreOrder(nd->left);

    cout << "\t \\ ";
    traversePreOrder(nd->right);
    cout << endl;
  }
};

int main() {
  vector<int> v{-1, 40, 22, 5, 9, 1, 10, 30, -18};
  printV(v);

  auto tree = new BsTree<int>(v);
  // tree->traversePreOrder(tree->root);
  printf("Tree min: %d, max: %d\n", tree->getMin(), tree->getMax());

  printf("\nTree of alpha chars:\n");
  auto ctree = new BsTree<char>();
  ctree->root->data = 'L';

  for (int i = 0; i < 40; i++) {
    char c = (char)(rand() % 120);
    if (isalpha(c))
      ctree->insert(c);
  }
  printf("Tree min: %c, max: %c\n", ctree->getMin(), ctree->getMax());

  return 0;
}
