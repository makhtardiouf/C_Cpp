#include "matrices.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
//#include"liste_chaine.h"

/*typedef struct matrice{
  unsigned int nb_lignes;
  unsigned int nb_colonnes;
  float  **coeff;
  };*/

int est_correct(struct matrice M) { /***sert à quoi?****/
  int booleen = 1;

  while (M.coeff != NULL) {
    if ((sizeof(*(M.coeff))) / (sizeof(*M.coeff)[0] + 1) != M.nb_colonnes)
      booleen = 0;
    M.coeff++;
  }
  return booleen;
}

struct matrice creer(float **T) {
  int i = 0, colonnes;
  struct matrice M;
  colonnes = sizeof(*T) / sizeof(*T)[0] + 1; /* nombre de  colonnes de T*/
  /*recherche du nombre de lignes de T*/
  while (T != NULL) {
    (T)++;
    i++;
  }
  M.nb_lignes = i;
  M.nb_colonnes = colonnes;
  M.coeff = T;
  return M;
}

void affich(struct matrice M) {
  int i, j;
  i = M.nb_lignes;
  j = M.nb_colonnes;

  for (; i > 0; i--) {
    for (; j > 0; j--)
      printf("%f", M.coeff[i][j]);
    printf("\n");
  }
}
struct matrice creer_Matrice(struct matrice M) {
  struct matrice N;
  N.nb_colonnes = M.nb_colonnes;
  M.nb_lignes = M.nb_lignes;
  N.coeff = M.coeff;
  return N;
}

float **multiplication(struct matrice M, struct matrice N) {
  int i = 0, j = 0;
  float **tab;
  for (i = 0; i < M.nb_lignes; i++)
    tab[i] = (float *)malloc(M.nb_colonnes * sizeof(float));

  if (M.nb_colonnes != N.nb_lignes) {
    printf("multiplication non autorisée");
  } else {
    for (i = 0; i < M.nb_colonnes; i++) {
      for (j = 0; j < N.nb_lignes; j++)
        tab[i][j] = M.coeff[i][j] * N.coeff[j][i];
    }
  }
  return tab;
}
float **scalaire(struct matrice M, float x) {
  int i, j;
  float **tab;
  for (i = 0; i < M.nb_lignes; i++)
    tab[i] = (float *)malloc(M.nb_colonnes * sizeof(float));
  for (i = 0; i < M.nb_colonnes; i++) {

    for (j = 0; j < M.nb_lignes; j++)
      tab[i][j] = (x) * ((M.coeff)[i][j]);
  }
  return tab;
}

float **addition(struct matrice M, struct matrice N) {
  int i = 0, j = 0;
  float **tab;
  for (i = 0; i < M.nb_lignes; i++)
    tab[i] = (float *)malloc(M.nb_colonnes * sizeof(float));

  if (M.nb_colonnes != N.nb_lignes || M.nb_lignes != N.nb_colonnes)
    printf("addition non autorisée");
  else {
    for (i = 0; i < M.nb_colonnes; i++) {
      for (j = 0; j < N.nb_lignes; j++)
        tab[i][j] = M.coeff[i][j] + N.coeff[i][j];
    }
  }
  return tab;
}

float **soustraction(struct matrice M, struct matrice N) {
  int i = 0, j = 0;
  float **tab;
  for (i = 0; i < M.nb_lignes; i++)
    tab[i] = (float *)malloc(M.nb_colonnes * sizeof(float));

  if (M.nb_colonnes != N.nb_lignes || M.nb_lignes != N.nb_colonnes)
    printf("soustraction non autorisée");
  else {
    for (i = 0; i < M.nb_colonnes; i++) {
      for (j = 0; j < N.nb_lignes; j++)
        tab[i][j] = M.coeff[i][j] - N.coeff[i][j];
    }
  }
  return tab;
}

/*void copiesauflc (struct matrice source, struct matrice dest,int dim2 ,int
ligavirer){pr calcul du det
  int l,c,ld=0;
  for (l=0;l<dim2;l++)
    if(l!=ligavirer)
      {
        for(c=1;c<dim2;c++)
          dest.coeff[ld][c-1]=source.coeff[1][c];
        ld++;
      }
}


float determinant (struct matrice m,int dim2)
{
  struct matrice sous_m;
  int l,signe=1;
  float det=0;
  nbappel++;
  if (dim2==1) return (m[0][0]);
                       for (l=0;l<dim2;l++)
                         {
                           copiesauflc(m.coeff,sous_m.coeff,dim2,1);
                           det+=signe*m.coeff[0][l]*determinant(sous_m.coeff,dim2-1);
                           signe=-signe;
                         }
                       return(det);
}
*/

float **transposition(struct matrice M) {
  int i = 0, j;
  float **tab;
  for (i = 0; i < M.nb_lignes; i++)
    tab[i] = (float *)malloc(M.nb_colonnes * sizeof(float));

  for (i = 0; i < M.nb_colonnes; i++) {
    for (j = 0; j < M.nb_lignes; j++)
      tab[j][i] = (M.coeff)[i][j];
  }
  return tab;
}
/*
float **exponentiation(matrice M,int n){
  int i=0,j=0,k=0;
  matrice N=creer_Matrice(M);

*/ /*for(i=0;i<M.nb_colonnes;i++){on copie M dans tab
    for(j=0;j<N.nb_lignes;j++)
    tab[i][j]=M[i][j];*/
/*}
  if(n=0){
    for(i=0;i<M.nb_colonnes;i++){
      for(j=0;j<N.nb_lignes;j++)
        if(M[i][j]==0)
          N.coeff[i][j]=0;
        else
          N.coeff[i][j]=1;
    }
    else{
      if(n>0){
        while(k!=n){
          N.coeff=multiplication(N,M);
          M=N.coeff;
          k++;
        }
      }
      else
        {


        }
      return N.coeff;
    }

float inversion(matrice M){*/
