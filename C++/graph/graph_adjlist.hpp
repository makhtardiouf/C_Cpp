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

template <typename T> struct vertex {
  // Cost of edge to destination vertex
  typedef pair<int, vertex *> ve;

  // Unique neighbors, using set instead of list/vector
  set<ve> adj;

  // Payload
  T name;
  vertex(T s) : name(s) {}
};

template <typename T> class Graph {
private:
  bool isDirected = false;
  map<T, vertex<T> *> vertices;

public:
  void addVertex(T);
  vertex<T> getVertex(T);
  void addEdge(T from, T to, int cost);
  bool isEdge(T from, T to);

  Graph(bool directed) { isDirected = directed; }
};

template <typename T>
void Graph<T>::addVertex(T name) {
  // map will skip over duplicates
  // Complexity:  O(log(vertices.size()))
  vertices[name] = new vertex<T>(name);
}

template <typename T>
vertex<T> Graph<T>::getVertex(T v) {
  return vertices.find(v)->second;
}

template <typename T>
void Graph<T>::addEdge(T from, T to, int cost) {
  auto f = vertices.find(from)->second;
  auto t = vertices.find(to)->second;
  auto edge = make_pair(cost, t);
  f->adj.insert(edge);

  if (!isDirected) {
    edge = make_pair(cost, f);
    t->adj.insert(edge);
  }
}

template <typename T>
bool Graph<T>::isEdge(T from, T to) {
  auto f = vertices.find(from)->second;
  auto t = vertices.find(to)->second;

  for(auto el : f->adj) {
    if (el.second == t)
      return true;
  }
  if(!isDirected) {
  for (auto el : t->adj) {
    if (el.second == f)
      return true;
  }
  }
  return false;
}
