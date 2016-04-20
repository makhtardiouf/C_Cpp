// $Id: streamIterators.cpp 8 2007-04-30 22:25:20Z Makhtar $

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <exception>
#include <cstdlib>

int main(void)
{
  using namespace std;
    string from, to;
    cout << __FILE__ << ":" << __LINE__ << "\nEnter filenames SOURCE TARGET: ";
    cin >> from >> to;	// get source and target file names

    try {
    ifstream src{from, ios_base::out};	// input stream
    if(!src) {
        throw runtime_error("Input file could not be read ");
    }
    istream_iterator<string> inIt{src};
    istream_iterator<string> eos;

    string s;
    while(src >> s)
        cout << s << "\n";
    
    vector<string> lines(inIt, eos);
    sort(lines.begin(), lines.end());

    ofstream target{to};	// output stream
    ostream_iterator<string> oIt(target, "\n");

    unique_copy(lines.begin(), lines.end(), oIt);

    return (!src.eof() && !target); 	// return error state
    } catch(runtime_error ex) {
        std::cerr << "Error: " << ex.what() << " " <<__FILE__ << ":" << __LINE__ << "\n";
        return EXIT_FAILURE;
    }
}
