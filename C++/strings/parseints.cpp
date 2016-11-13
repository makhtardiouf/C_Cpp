/**
 * Parse integers from a string input
 * Makhtar Diouf
*/
#include "malib.hpp"
#include <sstream>

using namespace std;

vector<int> parseInts(string input)
{
    stringstream stream(input);
    vector<int> ret;
    int n;
    while (stream >> n)
    {
        ret.push_back(n);
    }
    return ret;
}

int main()
{
    string input;
    std::getline(cin, input);
    auto v = parseInts(input);
    cout << "Parsed integers: ";
    for (auto el : v)
        cout << el << " ";

    cout << endl;
    return 0;
}
