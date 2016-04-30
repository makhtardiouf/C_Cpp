/*
HRANK Lovely Triplets
c++ -g -std=c++11 lovtriplets.cpp  -o lovtriplets
Undirected Ugraph
Input: P (the number of different lovely triplets you must have in your graph)
and Q (distance between each pair of nodes in a lovely triplet),
output N(the number of nodes in the graph) and M(the number of edges in the
graph),

nodes = vertices
edges = links, Each edge is a pair of vertices.
*/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <set>
#include <string>
#include <vector>
using namespace std;

class Ugraph {
private:
  bool **adjMat;

public:
  int numVertexes = 0;
  int numEdges = 0;
  Ugraph() {}

  Ugraph(int numVertexes) {
    this->numVertexes = numVertexes;
    adjMat = new bool *[numVertexes];
    for (int i = 0; i < numVertexes; i++) {
      adjMat[i] = new bool[numVertexes];
      for (int j = 0; j < numVertexes; j++)
        adjMat[i][j] = false;
    }
  }

  ~Ugraph() {
    for (int i = 0; i < numVertexes; i++)
      delete[] adjMat[i];
    delete[] adjMat;
  }

  void addEdge(int i, int j) {
    if (i >= 0 && i < numVertexes && j > 0 && j < numVertexes) {
      adjMat[i][j] = true;
      adjMat[j][i] = true;
      numEdges++;
    }
  }

  bool isEdge(int i, int j) {
    if (i >= 0 && i < numVertexes && j > 0 && j < numVertexes)
      return adjMat[i][j];
    else
      return false;
  }
};

int main() {
  int P = 3, Q = 2;
  ////  cin >> P >> Q;
  int m = 0;

  int n = 18;  
  int numV = (P * 3) - 2; //Q;
  auto graph = Ugraph(n);
  vector<int> v(n);

  for (int i = 0; i < n; i++) {
    v[i] = i + 1;
  }

  int trip = 0, numNodes = 0;
  int j = 0, k = 0;
  for (int i = 0; i < n; i++) {
    if (trip == P)
      break;

    numNodes++;
    graph.addEdge(i, i + 1);

    //j = i + Q;
     for (int j = i + 1; j < n ; j++)
    if (abs(v[i] - v[j]) == Q) {
 // k = j + Q;
      for (int k = j + 1; k < n ; k++)    
      if (abs(v[j] - v[k]) == Q) {
        trip++;
        //  graph.addEdge(j, k);
        fprintf(stderr, "\nmatch: (%d, %d, %d)\n", v[i], v[j], v[k]);
        break;
      }
      // break;
    }
  }
  // close graphe
  graph.addEdge(numV - 1, 1);
  graph.addEdge(1, numV);

  // Num nodes, and edges
  printf("%d %d\n", numNodes, graph.numEdges);
  for (int i = 1; i <= graph.numEdges; i++) {
    if (graph.isEdge(i, i + 1))
      printf("%d %d\n", i, i + 1);
  }
  // for (int i = graph.numEdges; i > 0; i--) {
 // if (graph.isEdge(numV - 1, 1))
    printf("%d %d\n", graph.numEdges - 1, 1);

//  if (graph.isEdge(1, numV))
    printf("%d %d\n", 1, graph.numEdges);
  // }
  return 0;
}
