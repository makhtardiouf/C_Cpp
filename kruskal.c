#include<stdio.h>
#define N 10       /*nombre de sommet */
#define inf 1000  /*Pour représenter l'infini */
int main(){
	
	/*Matrice du Graphe */
  int MG[N][N]={{0,1,inf,2,inf,inf,inf,inf,inf,inf},
	      		  {1,0,inf,inf,4,6,inf,inf,inf,inf},
	      		  {inf,inf,0,inf,5,inf,inf,inf,inf,3},
	      		  {2,inf,inf,0,1,inf,inf,6,inf,inf},
	      		  {inf,4,5,1,0,1,inf,3,inf,inf},
	      		  {inf,6,inf,inf,1,0,3,inf,2,3},
	      		  {inf,inf,inf,inf,inf,3,0,inf,5,3},
	      		  {inf,inf,inf,6,3,inf,inf,0,4,inf},
	      		  {inf,inf,inf,inf,inf,2,5,4,0,inf},
	     		  {inf,inf,3,inf,inf,3,3,inf,inf,0}
             	}; 
          
	/*Matrice de l'arbre initialisé à l'infini */	  
  int MA[N][N]={{inf,inf,inf,inf,inf,inf,inf,inf,inf,inf,},
	      {inf,inf,inf,inf,inf,inf,inf,inf,inf,inf,},
	      {inf,inf,inf,inf,inf,inf,inf,inf,inf,inf,},
	      {inf,inf,inf,inf,inf,inf,inf,inf,inf,inf,},
	      {inf,inf,inf,inf,inf,inf,inf,inf,inf,inf,},
	      {inf,inf,inf,inf,inf,inf,inf,inf,inf,inf,},
	      {inf,inf,inf,inf,inf,inf,inf,inf,inf,inf,},
	      {inf,inf,inf,inf,inf,inf,inf,inf,inf,inf,},
	      {inf,inf,inf,inf,inf,inf,inf,inf,inf,inf,},
	      {inf,inf,inf,inf,inf,inf,inf,inf,inf,inf,},
             };
	
  int Dist[]={0,1,inf,2,inf,inf,inf,inf,inf,inf};
  int SA[]={-1,0,0,0,0,0,0,0,0,0};
  int PP[]={1,1,1,1,1,1,1,1,1,1};
  int j,k,min,i=1;


  while(i<N){

  /*Recherche du sommet j qui minimise la distance qu'a l'arbre avec 
  	le reste du Graphe */
	min=inf;
	k=0;
 	while(k!=N){
  		if(Dist[k]<min && SA[k]!=-1){
			min=Dist[k];
			j=k;
		}
		k++;
	}
	
 	SA[j]=-1;    /*le sommet j est pris */
    for(k=1;k<N;k++){
      if(SA[k]!=-1){
		if(MG[j][k]<Dist[k]){
		  Dist[k]=MG[j][k];
	  	  PP[k]=j;
		}
      }
    }

   i++;
 }

      /*Construction de la matrice MA */
	for(i=0;i<N;i++){
		MA[i][i]=0;
		MA[i][PP[i]]=MG[i][PP[i]];
		MA[PP[i]][i]=MG[PP[i]][i];	
		
	}

       /* Affichage la matrice de l'arbre */
	printf("*******MATRICE D'UN ARBRE COUVRANT DE G:********\n");
	for(i=0;i<N;i++){
		for(j=0;j<N;j++)
			printf("%d   ",MA[i][j]);
		printf("\n");
	}	

            /* DESSIN DE L'ARBRE COUVRANT */

	printf("********DESSIN DE L'ARBRE COUVRANT********* \n\n");		

	printf("%7s(%d)\n","",2);
	printf("%8s \n","/");printf("%7d \n",1);printf("%6s \n","/");
	printf("%3c(%d)%21c(%d)\n",' ',1,' ',3);
	printf("%4c%26c \n",'/','\\');printf("%3d%29d\n",2,3);
	printf("%3c%29c \n",'/','\\');
	printf("(%d)",4);
	printf("___1___");
	printf("(%d)",5);printf("___1___");
	printf("(%d)",6);printf("___3___");printf("(%d)\n",10);
	printf("%10c%10c%2c \n",'/','/','\\');
	printf("%9d%9d%5d\n",3,2,3);
	printf("%8c%9c%7c \n",'/','/','\\');
	printf("%5c(%d)%6c(%d)%6c(%d)\n\n",' ',8,' ',9,' ',7);

         /*CALCUL DU POIDS MOYEN*/
		 
	 k=0;	
	 for(i=0;i<N;i++)
	 	k+=Dist[i];	
	printf("POIDS=%d\n\n",k);	 


  return 0;
}




