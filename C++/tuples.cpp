/**
   C++11  fixed-size collection of heterogeneous values,
   a generalization of std::pair
   Makhtar Diouf
   $Id$
   c++ -g -std=c++11 tuples.cpp -o tuples
   Ref: http://en.cppreference.com/w/cpp/utility/tuple
*/
#include <iostream>
#include <stdexcept>
#include <string>
#include <tuple>

std::tuple<double, char, std::string> getStudent(int id) {
  if (id == 0)
    return std::make_tuple(3.8, 'A', "Makhtar Simpson");
  if (id == 1)
    return std::make_tuple(2.9, 'C', "Milhouse Van Houten");
  if (id == 2)
    return std::make_tuple(1.7, 'D', "Ralph Diouf");
  throw std::invalid_argument("id");
}

int main() {
  auto stu0 = getStudent(0);
  std::cout << "ID: 0, "
            << "GPA: " << std::get<0>(stu0) << ", "
            << "grade: " << std::get<1>(stu0) << ", "
            << "name: " << std::get<2>(stu0) << '\n';

  double gpa1;
  char grade1;
  std::string name1;
  std::tie(gpa1, grade1, name1) = getStudent(2);
  std::cout << "ID: 1, "
            << "GPA: " << gpa1 << ", "
            << "grade: " << grade1 << ", "
            << "name: " << name1 << '\n';
  // getStudent(4);
}
