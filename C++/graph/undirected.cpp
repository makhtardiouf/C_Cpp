/**
Undirected graph using Adjacency Matrix
For large number of vertices better use Adjacency Lists

Graph = Set of vertices connected pairwise by edges.
Vertice = Node
Edge = Link, Path
*/
#include "../malib/malib.hpp"
using namespace std;

class Graph {
private:
  // Number of vertices
  int nV;

  // Adjacency Matrix
  bool **adjM;

public:
  Graph(int nV) {
    this->nV = nV;
    adjM = new bool*[nV];

    for (int i = 0; i < nV; i++) {
      adjM[i] = new bool[nV];
      for (int j = 0; j < nV; j++)
        adjM[i][j] = false;
    }
  }

  ~Graph() {
    for (int i = 0; i < nV; i++)
      delete[] adjM[i];
    delete[] adjM;
  }

  void addEdge(int i, int j) {
    if (i >= 0 && i < nV && j > 0 && j < nV) {
      adjM[i][j] = adjM[j][i] = true;
    }
  }

  void removeEdge(int i, int j) {
    if (i >= 0 && i < nV && j > 0 && j < nV) {
      adjM[i][j] = adjM[j][i] = false;
    }
  }

  // 2 Vertices are connected
  bool isEdge(int i, int j) {
    if (i >= 0 && i < nV && j > 0 && j < nV)
      return adjM[i][j];
    else
      return false;
  }

};
