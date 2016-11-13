/**
Multiply two linked lists

http://www.practice.geeksforgeeks.org/problem-page.php?pid=700336
The prob above only requires the completion of the function multiplyTwoLists,
but unused here, coz the 'node' ds is unspecified on the site
*/

#include <iostream>
#include <list>

using namespace std;

list<int>::iterator node;
long long multiplyTwoLists(node *l1, node *l2)
{
    list<long long> prod;

    while (l1->next != nullptr)
    {
        while (l2->next != nullptr)
            prod.push_back((*l1) * (*l2));
    }
    for (auto el = prod.begin(); el != prod.end(); el++)
        cout << *el;
    cout << endl;
}

int main(int argc, char **argv)
{
    int T = 0, n = 0, m = 0, el = 0;
    cin >> T;
    while (T--)
    {
        cin >> n;
        list<int> l1;
        for (int i = 0; i < n; i++)
        {
            cin >> el;
            l1.push_back(el);
        }
        cin >> m;
        list<int> l2;
        for (int i = 0; i < m; i++)
        {
            cin >> el;
            l2.push_back(el);
        }

        list<long long> prod;
        cout << "Lists sizes: " << l1.size() << " " << l2.size() << " " << prod.size() << endl;

        for (auto i = l1.begin(); i != l1.end(); i++)
        {
            for (auto j = l2.begin(); j != l2.end(); j++)
                prod.push_back((*i) * (*j));
        }
        for (auto el = prod.begin(); el != prod.end(); el++)
            cout << *el;
        cout << endl;
    }

    return 0;
}