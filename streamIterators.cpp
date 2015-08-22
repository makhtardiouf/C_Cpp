// $Id: streamIterators.cpp 8 2007-04-30 22:25:20Z Makhtar $

#include <iostream>
#include <string>
#include <vector>


int main(void)
{
  using namespace std;

    string from, to;
    cout << "\nEnter filenames: SOURCE TARGET >> ";
    cin >> from >> to;		// get source and target file names

    ifstream is(from.c_str());	// input stream
    istream_iterator<string> ii(is);
    istream_iterator<string> eos;

    vector<string> b(ii, eos);
    sort(b.begin(), b.end());

    ofstream os(to.c_str());	// output stream
    ostream_iterator<string> oo(os, "\n");

    unique_copy(b.begin(), b.end(), oo);

    return !is.eof() && !os ; 	// return error state
}
