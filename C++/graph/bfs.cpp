/**
 Graph Breadth First Search,  Put unvisited vertices on a queue.

 print Bfs traversal from a given source vertex.
 Bfs(int s) traverses vertices reachable from s.
http://www.geeksforgeeks.org/breadth-first-traversal-for-a-graph/
*/

#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;

// Class of a directed graph using adjacency lists
class Graph
{
    int V;          // No. of vertices
    list<int> *adj; // Pointer to an array containing adjacency lists

  public:
    Graph(int V);
    void addEdge(int v, int w);
    void Bfs(int s);            // Traversal from a given source s
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[ V ];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::Bfs(int s)
{
    cout << "\nBreadth First Traversal (starting from vertex " << s << "): \n";

    // Mark all the vertices as not visited
    vector<bool> visited(V);
    visited.assign(V, false);

    // queue for Bfs
    std::queue<int> q;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    q.push(s);

    while (!q.empty())
    {
        // Dequeue a vertex and print it
        s = q.front();
        cout << s << " -> ";
        q.pop();

        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        for (auto it = adj[s].begin(); it != adj[s].end(); ++it)
        {
            if (!visited[*it])
            {
                visited[*it] = true;
                q.push(*it);
            }
        }
    }
}

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

    g.Bfs(2);
    g.Bfs(1);
    cout << endl;
    return 0;
}
