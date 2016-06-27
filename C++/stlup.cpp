/**
C++11 STL constructs demo
*/
#include "malib.hpp"
using namespace std;

void finit(initializer_list<int>);
void inits();

int main() {
  vector<int> v;
  for (const auto x : {1, 2, 3, 5, 8, 13, 21, 34}) {
    printf("%d ", x);
    v.push_back(x);
  }
  cout << endl;
  for (auto &x : v)
    ++x;
  printV(v);
  
  finit({23,345,4567,56789});
	finit({});	// empty list
  inits();
  return 0;
}

// Initializers
void finit(initializer_list<int> l) {
  for(auto el: l)
    printf("%d ", el);
  cout << endl;
}

void inits() {
  struct X {
    int a, b;
    
  std::ostream& operator<<(std::ostream &ostr) {ostr << a << b; return ostr;}
  //  void operator<<(X x) {cout << x.a << x.b;}
  };
  
 // allow {}-initializer lists for all initialization:
	X x1 = X{1,2}; 
	X x2 = {-1,4}; 	// the = is optional
	X x3{4,20}; 
	X* p = new X{10,-2}; 

  cout << x1 << x2 << x3 << endl;

	struct D : X {
		D(int x, int y) :X{x,y} { /* ... */ };
	};

	struct S {
		int a[3];
		S(int x, int y, int z) :a{x,y,z} { /* ... */ }; // solution to old problem
	};  
}

  
  // Move constructor and move assignment takes non-const &&
//void moveConstructs() {
  template<class T> class vect{
		vect(const vect&);	 		    // copy constructor
		vect(vect&&);	 		          // move constructor
		vect& operator=(const vect&);	// copy assignment
		vect& operator=(vect&&);		// move assignment
	};			
//}


// Suffix return type syntax
// auto here means "return type to be deduced or specified later"
	template<class T, class U>
	auto mul(T x, U y) -> decltype(x*y)
	{
		return x*y;
	}
  