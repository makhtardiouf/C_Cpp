/**
Graph using Adjacency List (Set actually for uniqueness)

Graph = Set of vertices connected pairwise by edges.
Vertex = Node
Edge = Link, Path
Ref: http://stackoverflow.com/questions/5493474/graph-implementation-c
*/

#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

struct vertex {
  // Cost of edge to destination vertex
  typedef pair<int, vertex *> ve;

  // Unique neighbors, using set instead of list/vector
  set<ve> adj;

  // Payload
  string name;
  vertex(string s) : name(s) {}
};

class Graph {
private:
  bool isDirected = false;
  map<string, vertex *> vertices;

public:
  void addVertex(string);
  void addEdge(string from, string to, int cost);
  bool isEdge(string from, string to);

  Graph(bool directed) { isDirected = directed; }
};

void Graph::addVertex(string name) {
  // Check existing in O(n log n)
  if (vertices.find(name) != vertices.end()) {
    printf("\nVertex %s already exists!", name.c_str());
    return;
  }
  vertex *v = new vertex(name);
  vertices[name] = v;
}

void Graph::addEdge(string from, string to, int cost) {
  vertex *f = vertices.find(from)->second;
  vertex *t = vertices.find(to)->second;
  pair<int, vertex *> edge = make_pair(cost, t);
  f->adj.insert(edge);

  if (!isDirected) {
    edge = make_pair(cost, f);
    t->adj.insert(edge);
  }
}

bool Graph::isEdge(string from, string to) {
  vertex *f = vertices.find(from)->second;
  vertex *t = vertices.find(to)->second;

  for(auto el : f->adj) {
    if (el.second == t)
      return true;
  }
  for (auto el : t->adj) {
    if (el.second == f)
      return true;
  }
  return false;
}
