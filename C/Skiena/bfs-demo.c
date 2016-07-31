
/*	bfs-demo.c
        Driver program demonstrating breadth-first search
        begun: March 26, 2002
        Copyright 2003 by Steven S. Skiena; all rights reserved.
*/

#include "bool.h"
#include "graph.h"

extern bool processed[];  /* which vertices have been processed */
extern bool discovered[]; /* which vertices have been found */
extern int parent[];      /* discovery relation */

process_vertex_early(int v) { printf("processed vertex %d\n", v); }

process_vertex_late(int v) {}

process_edge(int x, int y) { printf("processed edge (%d,%d)\n", x, y); }

main() {
  graph g;
  int i;

  read_graph(&g, FALSE);
  print_graph(&g);
  initialize_search(&g);
  bfs(&g, 1);
  for (i = 1; i <= g.nvertices; i++)
    printf(" %d", parent[i]);
  printf("\n");

  for (i = 1; i <= g.nvertices; i++)
    find_path(1, i, parent);
  printf("\n");
}
