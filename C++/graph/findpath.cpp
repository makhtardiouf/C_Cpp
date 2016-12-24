/**
Graph processing: find path from vertex v to w, using DFS

Ref: Princeton Undirected graphs
*/
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include "graph_adjlist.hpp"

using namespace std;

// Defined externally
class Graph;

class PathfinderDFS {
private:
  vector<int> edgeTo;

  void dfs(Graph G, int v) {
    for (int w : G.adj(v))
      if (edgeTo[w] == 0) {
        edgeTo[w] = v;
        dfs(G, w);
      }
  }

public:
  PathfinderDFS(Graph G, int s) {
    edgeTo = vector<int>(G.V());
    edgeTo[s] = s;
    dfs(G, s);
  }

  vector<int> pathTo(int v);
  // Stay tuned.
};
