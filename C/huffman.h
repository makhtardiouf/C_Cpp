/* 
 * $Id$
 * Makhtar Diouf  2005  
 */
#ifndef _HUFFMAN_H
#define _HUFFMAN_H

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct arbre {
    double p;
    char c;
    struct arbre *fg;  // left leaf
    struct arbre *fd;  // right leaf
} tree;

struct init
{
  char c;
  double p;
};

tree construct(char c, double p, tree *fg, tree *fd);
tree join(tree, tree);
tree *reduce(tree *tab, int n);
tree huffman_tree(char *fichier, int n);
extern char **dico(char *, int);

#endif
