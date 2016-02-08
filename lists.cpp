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

template<typename T> class List {
    friend class Iterator;

public:

    List() {
    }
    List(const List<T>& l);

    ~List() {
        node = 0;
    }

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
        T elem;
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

        Node(T data) : elem(data) {
        }

        ~Node() {
            if (prev) {
                prev->next = next;
                if (next)
                    next->prev = prev;
            }
        }
    };

    Node* node;
};

template<typename T>
void List<T>::insert_front(const T& elem) {
    List<T>::Node* n = new List<T>::Node(elem);
    if (this->node) {
        n->prev = this->node;
        this->node->next = n;
    } else
        this->node = n;

}
// Implemented outside the List to allow multiple iterators to be used at the same time

/*
template<typename T>
class Iterator {
private:
    friend class List<T>;
    List<T>& list;
    typename List<T>::Node* first;
    typename List<T>::Node* current;

public:

    Iterator(List<T>& list) {
        //  first = list.head;
        current = first;
    }

    T* begin() {
        current = first;
        return first->elem;
    }

    T* end() {
        return NULL;
    }

    typename List<T>::Node* next() {
        typename List<T>::Node* p = current;
        current = current->next;
        return p;
    }

    typedef Iterator<T> iterator;
    bool operator==(const iterator& i) const {return (i->current == current);}
    bool operator!=(const iterator& i) const {return (i->current != current);}
    iterator& operator++();
    iterator& operator++(int);
    iterator& operator--();
    iterator& operator--(int);
    
    T& operator* () const;
    T& operator()() {
        return *current->elem;
    }
};
 */

int main(int argc, char** argv) {

    std::list<int> lt;
    for (int i = 0; i < 10; i++)
        lt.push_back(rand());

    lt.sort();
    for (std::list<int>::iterator it; it != lt.end(); it++)
        std::cout << *it;

    List<int> bList;

    bList.insert_front(10);
    bList.insert_front(19);
    return 0;
}

