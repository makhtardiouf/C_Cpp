/**
 Graph Breadth First Search to find nodes which minimize the height of tree.

http://www.geeksforgeeks.org/roots-tree-gives-minimum-height/
*/

#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;

// Undirected graph object using adjacency lists
class Graph
{
    int V;          // No. of vertices
    list<int> *adj; // Pointer to an array containing adjacency lists
    vector<int> degree;

  public:
    Graph(int V);
    void addEdge(int v, int w); // add an edge to graph
    vector<int> rootForMinimumHeight();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[ V ];
    degree.assign(V, 0);
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list
    adj[w].push_back(v); // Add v to w’s list
    degree[v]++;
    degree[w]++;
}

vector<int> Graph::rootForMinimumHeight()
{
    queue<int> q;

    //  first enqueue all leaf nodes in queue
    for (int i = 0; i < V; i++)
        if (degree[i] == 1)
            q.push(i);

    //  loop until total vertex <= 2
    while (V > 2)
    {
        for (int i = 0; i < q.size(); i++)
        {
            int t = q.front();
            q.pop();
            V--;

            // for each neighbour, decrease its degree and
            // if it become leaf, insert into queue
            for (auto j = adj[t].begin(); j != adj[t].end(); j++)
            {
                degree[*j]--;
                if (degree[*j] == 1)
                    q.push(*j);
            }
        }
    }

    //  copying the result from queue to result vector
    vector<int> res;
    while (!q.empty())
    {
        res.push_back(q.front());
        q.pop();
    }
    return res;
}

// Test driver program
int main()
{
    Graph g(6);
    g.addEdge(0, 3);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(4, 3);
    g.addEdge(5, 4);

    vector<int> res = g.rootForMinimumHeight();
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}
