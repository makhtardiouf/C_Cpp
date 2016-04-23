/**
 Algo design manual
 Makhtar Diouf
 $Id$
 g++ -g -std=c++11 tree.cpp -o tree
*/
#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
class Tree
{
    // A Tree of trees
private:
    typedef struct tree {
        T item; // data
        struct tree *parent;
        struct tree *left;
        struct tree *right;
    } tree;

    tree* root = nullptr;

public:
    Tree(T a)
    {
        tree n;
        n.item = a;
    };
    Tree(vector<T> v)
    {
      //root = new tree;
        //  t->item = v[0];
        // insert root
      std::sort(v.begin(), v.end());
        insert(nullptr, v[0], nullptr);
        for( int i = 1; i < v.size(); i++)
            insert(&root, v[i], root);
        traverse(root);
        cout << endl;
    }

    tree* search(tree *l, T x)
    {
        if (l == nullptr) return(nullptr);
        if (l->item == x) return(l);

        if (x < l->item)
            return( search(l->left, x) );
        else
            return( search(l->right, x) );
    }

    tree* getMin(tree *t)
    {
        tree *min;
        // pointer to minimum
        if (t == nullptr) return(nullptr);
        min = t;
        // Keep going to the left till the last leaf
        while (min->left != nullptr)
            min = min->left;
        return(min);
    }

    void traverse(tree *l)
    {
        if (!l)
            return;
        cout << l->item << "\n\t / \n\t";
        traverse(l->left);
        //processitem(l->item);
        cout << l->item << "\n\t \\ \n\t";
        traverse(l->right);
    }

    void insert(tree **l, T x, tree *parent)
    {
        tree *p;
        if ((root == nullptr) || (*l == nullptr)) {
            p = new tree; /* allocate new node */
            p->item = x;
            p->left = p->right = nullptr;
            p->parent = parent;
            //*l = new tree;
            // 1st node to be added to the tree
            if(root == nullptr) {
              root = p;
            
            } else
              ;//l = &p;
            /* link into parent’s record */
            return;
        }

        if (x < (*l)->item)
          insert(&((*l)->left), x, *l);
        else
          insert(&((*l)->right), x, *l);
    }

};

int main()
{
    vector<int> v {40, 2, 5, 3, 10};
    auto t = new Tree<int>(v);
    return 0;
}
