/****************************************************/
/***  fichier dico.c                              ***/
/***  construction du dictionnaire                ***/
/****************************************************/
#include "dico.h"

/* declaration des fonctions locales */
void dico_etape(arbre, int, char **, char *);

void dico_etape(arbre A, int profondeur, char **tab, char *sequence) {
  char c;
  int i, j;
  if (A->fgauche == NULL && A->fdroit == NULL) {
    c = A->lettre;
    if (c == ' ')
      i = 0;
    else
      i = c - 96;
    tab[i] = (char *)malloc((profondeur + 1) * sizeof(char));
    for (j = 0; j < profondeur; j++)
      tab[i][j] = sequence[j];
    tab[i][profondeur] = '\0';
    return;
  }
  sequence[profondeur] = '0';
  dico_etape(A->fgauche, profondeur + 1, tab, sequence);
  sequence[profondeur] = '1';
  dico_etape(A->fdroit, profondeur + 1, tab, sequence);
  return;
}

char **dico(char *fichier, int n) {
  arbre A;
  char **res;
  char *sequence;
  int i;

  A = huffman_arbre(fichier, n);
  res = (char **)malloc(n * sizeof(char *));
  sequence = (char *)malloc((n + 1) * sizeof(char));
  dico_etape(A, 0, res, sequence);

  printf("\n \t %s\n", res[0]);
  for (i = 1; i < n; i++)
    printf("%c \t %s\n", i + 96, res[i]);

  return (res);
}
