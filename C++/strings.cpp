// $Id: strings.cpp 5 2007-03-31 15:04:06Z Makhtar $

#include <iostream>
#include <string>

using namespace std ;

int main(void)
{
    string s1, s2 ;
    string s3 = "\nHello, yow!\nMak is back!" ;
    string s4("whoami?") ;
    s2 = "Today is the day" ;
    s1 = s3 + " " + s4 ;
    s1 += " hey " ;        // appending to a string
    cout << s1 + s2 + "!" << endl << endl ;

    return 0;
}
