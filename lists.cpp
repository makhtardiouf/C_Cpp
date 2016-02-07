/* 
 * File:   lists.cpp
 * Author: makhtar
 * Custom implementation of lists, and mix with the stdlib list
 * Created on February 7, 2016, 3:21 PM
 */

#include <cstdlib>
#include <list>
#include <string>
#include <iterator>
#include <iostream>

using namespace std;
class Iteratorx;

template<class T> class List {
    friend Iteratorx;

public:
    List();
    List(const List<T>& l);
    ~List();

    List<T>& operator=(const List<T>& l);

    void insert_front(const T& elem);
    T* remove_front();

    void insert_back(const T& elem);
    T* remove_back();

    void insert_nth(int n, const T& elem);
    T* remove_nth(int n);

    void reverse();
    void merge(const List<T>* l);

private:

    struct Node {
        T* elem;
        Node* prev;
        Node* next;
        Node* head; // lect15
        // ...

        Node(Node* p = NULL) : prev(NULL), next(NULL) {
            if (p) {
                prev = p;
                next = p->next;
                p->next = this;
                next->prev = this;
            }
        }

        ~Node() {
            if (prev) {
                prev->next = next;
                if (next)
                    next->prev = prev;
            }
        }
    };
};


int main(int argc, char** argv) {

    list<int> lt;
    for (int i = 0; i < 50; i++)
        lt.push_back(rand());

    lt.sort();
    for (list<int>::iterator it; it != lt.end(); it++)
        std::cout << *it;

    return 0;
}

// Implemented outside the List to allow multiple iterators to be used at the same time
template<class T> class Iteratorx {
    List<T>::Node* first;
    List<T>::Node* current;

public:

    Iterator(List<T>& list) {
      //  first = list.head;
        current = first;
    }

    begin() {
        current = first;
        return first->elem;
    }

    end() {
        return NULL;
    }

    next() {
        List<T>::Node* p = current;
        current = current->next;
        return p;
    }

    // overload operator() to access the element of a list

    T& operator()() {
        return *current->elem;
    }
};