/* 
 * $Id$
 * Author: makhtar
 * https://code.google.com/codejam/contest/351101/dashboard#s=p0
 * Created on February 12, 2016, 3:32 PM
 * ONLY 2 items' prices should be == to the Total credit
 */

#include <cstdlib>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iterator>
#include "malib.h"
using namespace std;

struct _case {
    int credit;
    int numItems;
    vector<int> prices;
};

void SelectProducts(string filename);

bool getSelection(_case c);

int main(int argc, char** argv) {
    if (argc < 2)
        terminate("Usage: ./str_reversewords filename");

    string s{argv[1]};
    SelectProducts(s);
    return EXIT_SUCCESS;
}

void SelectProducts(string filename) {
    std::ifstream input{filename}; // input stream       
    int n;
    input >> n; // skip first num = N test cases
    clog << n << " test cases\n";

    _case acase;
    int item;

    while (!input.eof()) {
        input >> acase.credit;
        input >> acase.numItems;
        clog << "Credit: " << acase.credit << "  Items: " << acase.numItems << "\n";

        for (int i = 0; i < acase.numItems; i++) {
            input >> item;
            acase.prices.push_back(item);
            clog << "item: " << item << "\n";
        }

        //  std::sort(acase.prices.begin(), acase.prices.end(), std::greater<int>());
        bool gotit = getSelection(acase);
        if (!gotit) {
            std::sort(acase.prices.begin(), acase.prices.end(), std::less<int>());
            getSelection(acase);
        }
        clog << "\n";
    }
}

bool getSelection(_case acase) {
    list<int> selected;
    bool gotit = false;

    for (int i = 0; i < acase.numItems; i++) {
        for (int j = i + 1; j < acase.numItems; j++) {
            if ((acase.prices[i] + acase.prices[j]) == acase.credit) {
                selected.push_back(acase.prices[i]);
                selected.push_back(acase.prices[j]);
                gotit = true;
                break; // only two solution
            }
            if(gotit)
                break;
        }
    }

    /*   for (int i = 0; i < acase.numItems; i++) {

           if ((total += acase.prices[i]) <= acase.credit)
               selected.push_back(acase.prices[i]);
           else //if( (total - prices[i]) > 0)
               total -= acase.prices[i];

           if (total == acase.credit)
               break;
           clog << "\nTotal selected: " << total;
       } */
    if (gotit) {
        clog << "\nMatches: ";
        for (list<int>::iterator it = selected.begin(); it != selected.end(); it++)
            clog << *it << " ";
    }

    clog << "\n";
    selected.clear();
    acase.prices.clear();
    return gotit;
}