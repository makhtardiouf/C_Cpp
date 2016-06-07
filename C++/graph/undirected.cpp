/*

Undirected graph using Adjacency Matrix
For large number of vertices better use Adjacency Lists
*/


class Graph {
private:
      bool** adjMatrix;
      int vCount;
public:
      Graph(int vCount) {
            this->vCount = vCount;
            adjMatrix = new bool*[vCount];
            for (int i = 0; i < vCount; i++) {
                  adjMatrix[i] = new bool[vCount];
                  for (int j = 0; j < vCount; j++)
                        adjMatrix[i][j] = false;
            }
      }
 
      void addEdge(int i, int j) {
            if (i >= 0 && i < vCount && j > 0 && j < vCount) {
                  adjMatrix[i][j] = true;
                  adjMatrix[j][i] = true;
            }
      }
 
      void removeEdge(int i, int j) {
            if (i >= 0 && i < vCount && j > 0 && j < vCount) {
                  adjMatrix[i][j] = false;
                  adjMatrix[j][i] = false;
            }
      }
 
      bool isEdge(int i, int j) {
            if (i >= 0 && i < vCount && j > 0 && j < vCount)
                  return adjMatrix[i][j];
            else
                  return false;
      }
 
      ~Graph() {
            for (int i = 0; i < vCount; i++)
                  delete[] adjMatrix[i];
            delete[] adjMatrix;
      }
};
