#include<math.h>

struct matrice {
  unsigned int nb_lignes;
  unsigned int nb_colonnes;
  float  **coeff;
};


float             **soustraction(struct matrice M, struct matrice N)
struct matrice    creer(float** T);
int               est_correct(struct matrice M);
void              affich(struct matrice M);
struct matrice    creer_Matrice(struct matrice M);
float           **multiplication(struct matrice M,struct matrice N);
float           **scalaire(struct matrice M,float x);
float           **addition(struct matrice M,struct matrice N);
float           **transposition(struct matrice M);
