/**
Algo design manual P165
Graph using Adjacency Lists
Directed edge (x, y) is represented by a node-y in node-x’s adjacency list

Graph = Set of vertices connected pairwise by edges.
Vertice = Node
Edge = Link, Path
*/
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

// Max number of vertices
#define MAXV 1000

typedef struct node {
  int y;                 // adjacency info
  int weight;            // edge weight, if any
  node *next;       // next edge in list
};

typedef struct {
  node *edges[MAXV + 1]; // adjacency info
  int degree[MAXV + 1];
  int nvertices;
  int nedges;

  // identify whether we need to insert
  // two copies of each edge or only one
  bool directed;
} graph;

void initGraph(graph *g, bool directed) {
  // counter
  int i;
  g->nvertices = 0;
  g->nedges = 0;
  g->directed = directed;

  for (i = 1; i <= MAXV; i++)
    g->degree[i] = 0;

  for (i = 1; i <= MAXV; i++)
    g->edges[i] = nullptr;
}


void insertEdge(graph *g, int x, int y, bool directed) {
  // temp pointer
  node* p = (node*) malloc(sizeof(node));
  p->weight = 0;
  p->y = y;
  p->next = g->edges[x];
  g->edges[x] = p;

  // insert at head of list
  g->degree[x]++;

  if (directed == false)
    insertEdge(g, y, x, true);
  else
    g->nedges++;
}


// Building the graph for a file's content
void readGraph(graph *g, bool directed) {
  int i;    // counter
  int m;    // number of edges
  int x, y; // vertices in edge (x,y)

  initGraph(g, directed);
  scanf("%d %d", &(g->nvertices), &m);

  for (i = 1; i <= m; i++) {
    scanf("%d %d", &x, &y);
    insertEdge(g, x, y, directed);
  }
}

void printGraph(graph *g) {
  int i;
  // temp pointer
  node *p;

  for (i = 1; i <= g->nvertices; i++) {
    printf("%d: ", i);
    p = g->edges[i];

    while (p != nullptr) {
      printf(" %d", p->y);
      p = p->next;
    }
    printf("\n");
  }
}
