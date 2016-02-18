// $Id: structUnion.cpp 9 2007-07-11 08:22:53Z Makhtar $

#include <iostream>
#include <cerrno>

using namespace std ;

// Each field has its own address in memory
struct class0
{
  int a;
  char b;
};

// All fields share the same address in memory
union class1
{
    int a;
    char b;
};


int main(void)
{
    class0 mystruct;
    cout << "\nSize of structure mystruct equals " << sizeof(mystruct);
    mystruct.a = 34;
    cout << "\nmystruct.a = " << mystruct.a;
    mystruct.b = 'W';
    cout << "\nmystruct.b = " << mystruct.b;
    cout << "\nmystruct.a = " << mystruct.a;


    class1 myunion;
    int* pa = &myunion.a;
    char* pb = &myunion.b;

    cout << "\n\nSize of union myunion equals " << sizeof(myunion);
    myunion.a = -12;
    cout << "\nmyunion.a = " << myunion.a;
    myunion.b = 'W';
    cout << "\nmyunion.b = " << myunion.b;
    // Verify that a's value was changed after the assignment operated in b
    cout << "\nmyunion.a = " << myunion.a << endl;

    printf("Address of myunion.a = %p\n", pa);
    printf("Address of myunion.b = %p\n", pb);

    if (errno not_eq 0)
        perror("\nERROR ");

    return EXIT_SUCCESS;
}
