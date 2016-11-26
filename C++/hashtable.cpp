/**
Custom implementation of a Generic Hash Table

M < N : mapping large input range into a smaller range for fast retrieval

Makhtar
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <list>
#include <utility> // pair

using namespace std;

template <typename KeyT, typename ValT>
class HashTab
{
  private:
    // Number of KeyVals and Hash table size
    int N, M;

    typedef pair<KeyT, ValT> kvpair;

    int hash(KeyT key)
    {
        // Horner's method for hashing strings
        int hashCode = 0;
        string s = (string)key;
        for (int i = 0; i < s.size(); i++)
            hashCode = s[i] + (31 * hashCode);

        if (hashCode > M)
            hashCode %= M;
        return hashCode;
    }

    // For colliding keys
    list<kvpair> siblings;

    // Dynamic array of kv
    list<kvpair> **table;

  public:
    HashTab(int n = 20)
    {
        this->N = n;
        this->M = n / 5;

        table = new list<kvpair> *[M];
        for (int i = 0; i < M; i++)
            table[i] = new list<kvpair>();
    }

    /**
    Map a key-val pair
    If the key exist, updates the value
    If collided, push_back in a list of siblings
    */
    void put(KeyT key, ValT val)
    {
        int idx = hash(key);
        auto spot = table[idx];
        if (spot->size() < 1)
        {
            spot->push_back(std::pair<KeyT, ValT>(key, val));
            clog << "Hash idx: " << idx << " mapped key-val: " << key << " -> " << val << endl;
            return;
        }

        // Check duplicates
        kvpair kv(key, val);
        auto it = std::find(spot->begin(), spot->end(), kv);
        if (it != spot->end())
        {
            it->second = val;
            clog << "Hash idx: " << idx << "updated key: " << key << endl;
        }
        else
        {
            spot->push_back(kv);
            clog << "Hash idx: " << idx << " mapped siblings key-val: " << key << " -> " << val << endl;
        }
    }

    ValT get(KeyT key);
    void listTable();
};

int main()
{
    auto m = new HashTab<string, int>();
    m->put("atest", 10);
    m->put("b", 62);
    return 0;
}
