/* 
 * Custom vector implementation demo
 * Author: makhtar
 *
 * February 23, 2016, 8:46 AM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Vector<T> {
public:

    Vector() {
        item = new T;
    }

    ~Vector() {
        delete[] item;
        clog << "~Vector called\n";
    }

    void add(T a) {
        item = new T(a);
    }
    void remove(T item);

    int size() {
        return sz;
    }

    std::ostream& operator<<(std::ostream& ostr) {
        ostr << *item;
    }

    T& operator[];

private:
    T* item;
    int sz;
};

/*
 * 
 */
int main(int argc, char** argv) {

    Vector<int> v;
    v.add(10);
    cout << v;
    return 0;
}

