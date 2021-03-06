/*
Topological sort of an acyclic graph of n vertices, with depth-first-search; TO COMPLETE
$Id$
See UVA #10305 "Ordering Tasks"
UVA #124 "Following Orders"
UVA #200 "Rare Order"
g++ -std=c++11 toposort.cpp -o toposort
*/
#include "../malib/malib.hpp"
using namespace std;

class TopoSorter
{
private:
  int n;                       // number of vertices
  const static int MAXN = 100; // to change
  vector<int> g[MAXN];         // count
  bool used[MAXN];

public:
  TopoSorter(int _n) { this->n = _n; }

  void dfs(vector<int> &ans, int v)
  {
    used[v] = true;
    for (size_t i = 0; i < g[v].size(); ++i)
    {
      int to = g[v][i];
      if (!used[to])
        dfs(ans, to);
    }
    ans.push_back(v);
  }

  void topological_sort(vector<int> &ans)
  {
    for (int i = 0; i < n; ++i)
      used[i] = false;

    ans.clear();
    for (int i = 0; i < n; ++i)
      if (!used[i])
        dfs(ans, i);

    reverse(ans.begin(), ans.end());
  }
};

int main(void)
{
  vector<int> v{-1, 10, 3, -50, 20};
  for (auto e : v)
    cout << e << " ";
  cout << endl;

  auto sorter = new TopoSorter(v.size());
  sorter->topological_sort(v);
  for (auto e : v)
    cout << e << " ";
  cout << endl;
  return 0;
}