/**
Custom implementation of a Generic Hash Table
M < N : mapping large input range into a smaller range for fast retrieval

Could use Horner's method for hashing strings but chose the last few chars of the key...
as if e.g. mapping phone numbers, the last few digits would generate less collisions;
the initial digits would likely correlate.

http://www.cs.princeton.edu/courses/archive/spr10/cos226/lectures/10-34HashTables-2x2.pdf
http://en.algoritmy.net/article/50101/Hash-table

Makhtar
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <algorithm>
#include <list>
#include <utility> // pair

using namespace std;

template <typename KeyT, typename ValT>
class HashTab
{
  private:
    // Number of KeyVals and Hash table size
    uint N, M;

    typedef pair<KeyT, ValT> kvpair;

    uint hash(KeyT key)
    {
        uint hashCode = 0;
        string s = (string)key;
        for (uint i = 1; i < 4; i++)
            hashCode += s[s.size() - i];

        hashCode = (97 * hashCode) % M;
        return hashCode;
    }

    // Dynamic array of kv's lists
    list<kvpair> **table;

  public:
    uint nCollisions, tableSize;

    HashTab(uint n = 100)
    {
        this->N = n;
        this->M = n / 5;
        this->nCollisions = 0;

        table = new list<kvpair> *[M];
        for (uint i = 0; i < M; i++)
            table[i] = new list<kvpair>();
    }

    /**
    Map a key-val pair
    If the key exist, updates the value
    If collided, push_back in a list of siblings
    */
    void put(KeyT key, ValT val)
    {
        uint idx = hash(key);
        auto spot = table[idx];
        if (spot->size() < 1)
        {
            spot->push_back(std::pair<KeyT, ValT>(key, val));
            printf("Hash idx: %02d mapped key-val: %s -> %02d\n", idx, key.c_str(), val);
            return;
        }

        // Check duplicates
        kvpair kv(key, val);
        auto it = std::find(spot->begin(), spot->end(), kv);
        if (it != spot->end())
        {
            it->second = val;
            printf("Hash idx: %02d updated key: %s\n", idx, key.c_str());
        }
        else
        {
            this->nCollisions++;
            spot->push_back(kv);
            printf("Hash idx: %02d mapped siblings key-val: %s -> %02d\n", idx, key.c_str(), val);
        }
    }

    ValT get(KeyT key);
    void listTable();
};

int main()
{
    auto m = new HashTab<string, uint>();
    stringstream ss;
    uint items = 0;
    for (char c = 'a'; c <= 'z'; c++)
    {
        ss << c;
        m->put(ss.str(), rand() % 100);
        items++;
    }
    // Test key update
    m->put("abc", 10);

    printf("Items: %d, Number of collisions: %d %.2f\% \n", items, m->nCollisions, (float)(m->nCollisions * 100 / items));
    return 0;
}
