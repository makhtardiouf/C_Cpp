/*
 * File:   lists.cpp
 * Author: makhtar
 * Custom implementation of lists, and mix with the stdlib list
 * g++ -g -std=c++11 -Wall lists.cpp -o lists
 * Created on February 7, 2016, 3:21 PM
 */

#include <cstdlib>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <list>
#include <string>

using namespace std;

template <typename T> struct Node {
  T elem;
  Node *prev;
  Node *next;

  Node(Node *p = NULL) : prev(nullptr), next(nullptr) {
    if (p) {
      prev = p;
      next = p->next;
      p->next = this;
      next->prev = this;
    }
  }

  Node(T data) : elem(data) {}

  ~Node() {
    if (prev) {
      prev->next = next;
      if (next)
        next->prev = prev;
    }
  }
};

template <typename T> class List {
public:
  class iterator;

  List() {}
  List(std::initializer_list<T> l);

  ~List() {
    if (elem)
      delete elem;
  }

  List<T> &operator=(const List<T> &l);

  void push_front(const T &val);

  void push_back(const T &val);
  T *pop_back();

  void reverse();
  void merge(const List<T> *l);

  inline int size() { return sz; }

  iterator begin() { return curr->head; }

  iterator end() { return elem; }

private:
  Node<T> *head;
  Node<T> *elem;
  int sz = 0;
};

template <typename T> void List<T>::push_back(const T &val) {
  Node<T> *n = new Node<T>(val);
  if (this->elem) {
    n->prev = this->elem;
    this->elem->next = n;
  } else
    this->elem = n;

  this->sz++;
}
// Implemented outside the List to allow multiple iterators to be used at the
// same time

template <typename T> class List<T>::iterator {
private:
  List<T> *curr;

public:
  iterator(List<T> &p) { this->curr = p; }

  bool operator==(const iterator &i) const { return (i->curr == curr); }

  bool operator!=(const iterator &i) const { return (i->curr != curr); }

  iterator &operator++() {
    curr = curr->next;
    return *this;
  }

  iterator &operator--() {
    curr = curr->prev;
    return *this;
  }

  T &operator*() const { return curr->elem; }

  T &operator()() { return elem; }
};

int main(int argc, char **argv) {

  std::list<int> lt;
  lt.push_back(100);
  for (int i = 0; i < 10; i++)
    lt.push_back(rand());

  lt.sort();
  std::list<int>::iterator it;
  for (it = lt.begin(); it != lt.end(); ++it)
    std::clog << *it << " ";

  cout << endl;
  List<int> bl;

  bl.push_back(10);
  bl.push_back(19);
  for (it = bl.begin(); it != bl.end(); ++it)
    std::clog << *it << " ";

  return 0;
}
