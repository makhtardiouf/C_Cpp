/**
Depth First Traversal (or Search) for a graph:
Should put unvisited vertices on a *stack*

unlike trees, graphs may contain cycles,
http://www.geeksforgeeks.org/depth-first-traversal-for-a-graph/

g++ -std=c++11  dfs.cpp -o dfs
*/

#include <cstdio>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

// Class of a directed graph using adjacency lists
class Graph {
  int nV;         // Number of vertices
  list<int> *adj; // Pointer to an array containing adjacency lists

  vector<bool> visited;

public:
  bool isInit = true;

  Graph(int nV) {
    this->nV = nV;
    adj = new list<int>[nV];
    visited.resize(nV);

    // Mark all the vertices as not visited
    visited.assign(nV, false);
  }

  void resetTraversal() {
    isInit = true;
    visited.assign(nV, false);
  }

  // add an edge to graph
  void addEdge(int v, int w) {
    adj[v].push_back(w); // Add w to v’s list.
    printf(" %d -> %d, ", v, w);
  }

  // Traversal from a given source s, using stack
  void Dfs(int s) {
    if (isInit) {
      cout << "\nDFS from vertex " << s << ": \n";
      isInit = false;
    }

    stack<int> st;
    visited[s] = true;
    st.push(s);

    while (!st.empty()) {
      s = st.top();
      cout << s << " -> ";
      st.pop();

      for (auto it = adj[s].begin(); it != adj[s].end(); it++) {
        if (!visited[*it]) {
          cout << *it << ", ";
          visited[*it] = true;
          st.push(*it);

          //**** Heart of DFS: recurse further down to the children before
          // visiting siblings(adj) above!
          Dfs(*it);
        } else {
          cout << "| ";
        }
      }
    }
  }

  // Traversal from a given source s, using queue ?
  void DfsQueue(int s) {
    if (isInit) {
      cout << "\nDFS from vertex " << s << ": \n";
      isInit = false;
    }

    queue<int> q;
    visited[s] = true;
    q.push(s);

    while (!q.empty()) {
      // Dequeue a vertex from queue and print it
      s = q.front();
      cout << s << " -> ";
      q.pop();

      for (auto it = adj[s].begin(); it != adj[s].end(); it++) {
        if (!visited[*it]) {
          cout << *it << ", ";
          visited[*it] = true;
          q.push(*it);
          Dfs(*it);
        } else {
          cout << "| ";
        }
      }
    }
  }
};

// Test driver program
int main() {
  Graph g(4);
  cout << "Adding edges: ";
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);

  g.Dfs(2);
  cout << endl;

  g.resetTraversal();
  g.DfsQueue(2);
  cout << endl;
  return 0;
}
