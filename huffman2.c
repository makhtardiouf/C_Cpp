/****************************************************/
/***  fichier huffman.c                           ***/
/***  construction de l'arbre de Huffman          ***/
/****************************************************/

#include "huffman.h"

struct init
{
  char c;
  double p;
};

/* declaration des fonctions locales au fichier */
int comp_proba(struct init *, struct init *);
struct init *proba_init(char *, int);

int comp_proba(struct init *a, struct init *b)
{
  double x;
  x = a->p - b->p;
  if (x > 0)
    return(1);
  if (x == 0)
    return(0);
  if (x <0)
    return(-1);
}

struct init *proba_init(char *fichier, int n)
{
  FILE *flot;
  struct init *tab_proba;
  int i;
  char c;

  if ((flot = fopen(fichier, "r")) == NULL)
    {
      fprintf(stderr,"\n Erreur: impossible d'ouvrir le fichier %s\n", fichier);
      return(NULL);
    }
  tab_proba = (struct init*)malloc(n * sizeof(struct init));
  for (i=0; i < n; i++)
    {
      fscanf(flot, "%c", &tab_proba[i].c);
      fscanf(flot, "%lf", &tab_proba[i].p);
      c = fgetc(flot);
    }
  fclose(flot);

  
  /* on trie tab_proba dans l'ordre decroissant des probas */
  qsort(tab_proba, n, sizeof(struct init), comp_proba);
  return(tab_proba);
}
  
  
  


arbre huffman_arbre(char *fichier, int n)
{
  arbre *tab, *new_tab;
  struct init *tab_proba;
  int taille_tab;
  int i;
  
  /* on initialise tab_proba */
  tab_proba = proba_init(fichier, n);
  /* on cree n arbres correspondant aux feuilles */
  tab = (arbre*)malloc(n * sizeof(arbre));
  for (i=0; i<n; i++)
    tab[i] = constructeur(tab_proba[i].c, tab_proba[i].p, NULL, NULL);
  free(tab_proba); 
  
  

  /* on reduit la table autant de fois qu'il faut */
  taille_tab = n;
  while (taille_tab > 1)
    {
      new_tab = reduire(tab, taille_tab);
      free(tab); 
      tab= new_tab;
      taille_tab--;
    }
  return(tab[0]);
}
  

