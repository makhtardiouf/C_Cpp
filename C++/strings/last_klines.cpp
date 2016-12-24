/**
 * Print last K lines of a file; reading it only once
 * Makhtar Diouf  - CTI P76, 205
*/
#include "malib.hpp"
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        cout << "Usage: last_klines [filename]\n";
        return 0;
    }

    int k = 10;
    vector<string> lines(k);
    lines.assign(k, "");

    string fname = argv[1];
    printf("Printing last %d lines from %s\n", k, fname.c_str());

    ifstream inp(fname);
    int i = 0;
    while (!inp.eof())
    {
        std::getline(inp, lines[i]);
        i++;

        // overwrite lines every k times, can directly use lines[i%k] above
        if ((i % k == 0))
            i = 0;
    }

    int start = (i == 0 ? i : i - 1);
    int num = 0;

    for (i = start; i < lines.size(); i++)
    {
        printf("\n%d: %s", num, lines[i].c_str());
        num++;
    }

    // When input ended before i reached k
    if (start != 0)
    {
        for (i = 0; i < start; i++)
        {
            printf("\n%d: %s", num, lines[i].c_str());
            num++;
        }
    }
    cout << endl;
    inp.close();
    return 0;
}
