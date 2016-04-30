/*
HRANK Lovely Triplets
c++ -g -std=c++11 lovtriplets.cpp  -o lovtriplets
Undirected Ugraph
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
  int numVertexes;
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
    }
  }

  void rmEdge(int i, int j) {
    if (i >= 0 && i < numVertexes && j > 0 && j < numVertexes) {
      adjMat[i][j] = false;
      adjMat[j][i] = false;
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
  cin >> P >> Q;
  int n = 0, m = 0;

  int numV = (P * 3) - Q;
  auto graph = Ugraph(numV);
  vector<int> v(numV);

  for (int i = 1; i < numV-1; i++) {
    graph.addEdge(i, i + 1);
    v[i] = i;
    fprintf(stderr, "edj: %d %d\n", i, i + 1);
  }
  graph.addEdge(numV-1, 1);
  fprintf(stderr, "edj: %d %d\n", numV-1, 1);
  graph.addEdge(1, numV);
  fprintf(stderr, "edj: %d %d\n", 1, numV);
  //  cout <<  << endl;
  
int trip = 0;
  for (int i = numV - 1; i >= 0; i--) {

    for (int j = i - 1; j >= 0; j--) {
      if ((v[i] - v[j]) == Q) {

        for (int k = j - 1; k >= 0; k--) {
          if ((v[j] - v[k]) == Q) {
            trip++;
            fprintf(stderr, "\nmatch: (%d, %d, %d)\n", v[i], v[j], v[k]);
            break;
          }
        }
        break;
      }
    }
  }

  // Num nodes, and edges
  printf("%d %d\n", numV, graph.numVertexes);
  for (int i = 1; i < numV-1; i++) {
    printf("%d %d\n", i, i+1);
  }
   printf("%d %d\n", numV-1, 1);
   printf("%d %d\n", 1, numV);
    
  return 0;
}
