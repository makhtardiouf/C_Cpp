/* 
 * Custom vector implementation demo
 * Author: makhtar
 * g++ -g -std=c++11 -Wall Vector.cpp  -o Vector
 * February 23, 2016, 8:46 AM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <initializer_list>
#include <typeinfo>

using namespace std;

template <typename T>
class Vector {
  
public:

//    Vector() {
//        // elem = new T;
//    }

    Vector(int s)
    : sz(s), elem{
        new T[s]
    }
    {
        std::copy(elem, elem + sz, 0);
    }

    // Initialize with {}
    Vector(std::initializer_list<T> l)
    : sz(l.size()), elem{new T[l.size()]}
    {
        std::copy(l.begin(), l.end(), elem);         
        clog << "Initialized vector of " << sz << " elements \n";
    };

    // Copy constructor
    Vector(const Vector& v)
    {
        T* p = new T[v.sz];       
        std::copy(v.elem, v.elem + v.sz, p);
       // delete[] elem;
        elem = p;
        sz = v.sz;      
    }

    ~Vector() {
        delete[] elem;
        clog << "~Vector called\n";
    }

    //   const_iterator begin() {return &elem[0];}
    //   const_iterator end() {return &elem[sz+1];}

    void
    add(T i) {
        cout << "Adding 1 element: " << i << endl;
        T* p = new T[sz + 1];
        // Move elements to the newly allocated space 
        std::move(elem, elem + sz, p);
        p[sz] = i;
        delete[] elem;
        sz++;
        elem = p;
    }
    void remove(T elem);

    int
    size() {
        return sz;
    }

    T& operator[](int i) {
        return elem[i];
    };

private:
    T* elem = nullptr;
    int sz = 0;
 
};

int
main(int argc, char** argv) {
    try {
        Vector<int> v{5, 10, 15};
        v.add(20);
        v.add(rand() % 2);

        for (int i = 0; i < v.size(); i++)
            cout << v[i] << " ";
        cout << "\n";

        Vector<string> s{"Hello", "container", "world"};
        s.add("The way it is...");
        
        for (int i = 0; i < s.size(); i++)
            cout << s[i] << " ";
        cout << "\n";
        return 0;
    } catch (exception e) {
        clog << "Fatal error: " << e.what() << endl;
        return -1;
    }
}

