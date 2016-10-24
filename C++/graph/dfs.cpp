/**
Depth First Traversal (or Search) for a graph:
unlike trees, graphs may contain cycles,
http://www.geeksforgeeks.org/depth-first-traversal-for-a-graph/

g++ -std=c++11  dfs.cpp -o dfs
*/

#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;

// Class of a directed graph using adjacency lists
class Graph
{
    int nV;         // No. of vertices
    list<int> *adj; // Pointer to an array containing adjacency lists
    queue<int> q;
    // Mark all the vertices as not visited
    vector<bool> visited;

  public:
    Graph(int nV)
    {
        this->nV = nV;
        adj = new list<int>[ nV ];
        visited.resize(this->nV);
        visited.assign(this->nV, false);
    }

    // add an edge to graph
    void addEdge(int v, int w)
    {
        adj[v].push_back(w); // Add w to v’s list.
    }

    // prints Dfs traversal from a given source s
    void Dfs(int s)
    {
        if (!visited[s])
            cout << s << " ";
        visited[s] = true;
        q.push(s);

        while (!q.empty())
        {
            // Dequeue a vertex from queue and print it
            s = q.front();
            q.pop();

            for (auto it = adj[s].begin(); it != adj[s].end(); it++)
            {
                if (!visited[*it])
                {
                    cout << *it << " ";
                    visited[*it] = true;
                    q.push(*it);
                    Dfs(*it);
                }
            }
        }
    }
};

// Test driver program
int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.Dfs(2);
    cout << endl;
    g.Dfs(0);
    cout << endl;
    return 0;
}
