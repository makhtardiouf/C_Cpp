/*
  Manually reverse a linked list and return pointer to the head
  The input list will have at least one element

    1 2 3 4 ->  4 3 2 1
    Use a Stack
*/
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <stack>

using namespace std;

typedef struct Node {
  int data;
  Node *next;

  Node(int val) { data = val; };
} Node;

Node *Reverse(Node *head) {
  //  if(!head)
  //     return head;

  stack<Node *> st;
  Node *n = head;
  while (n) {
    st.push(n);
    fprintf(stderr, "In: %d -> ", n->data);
    n = n->next;
  }

  puts("");
  n = head = st.top();
  fprintf(stdout, "%d ", n->data);
  st.pop();

  while (st.size() > 0) {
    n->next = st.top();
    st.pop();
    n = n->next;
    fprintf(stdout, "-> %d ", n->data);
  }

  puts("");
  return head;
}

int main() {
  Node* prev = new Node(10);
  Node* head = prev;
  for (int i = 2; i < 6; i++) {
    Node* n = new Node(rand() % i);
    if(!head->next) {
        head->next = n;
    } else {
    n->next = prev;
    }
    prev = n;
  }

Reverse(head);
  return 0;
}