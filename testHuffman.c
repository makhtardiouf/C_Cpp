#include"huffman.c"
#define N 27

int main(){
	arbre A;
	arbre B;
	struct init *tab;
	int i;
	char **dic;
	/*tab=proba_init("proba.txt", N);
	for(i=0;i<N;i++){
		printf("%c ",tab[i].c);
		printf("%f\n",tab[i].p);
	}*/
//	A=huffman_arbre("proba.txt",N);
	dic=dico("proba.txt",N);

	return 0;
}

