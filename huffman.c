#include"huffman.h"

struct init{
  	char c;
  	double p;
};
void trier(struct init *,int);
void echange(struct init *,struct init *);

arbre constructeur(char c, double p, arbre *fg, arbre *fd){
	arbre abr;
	abr.c=c;
	abr.p=p;
	abr.fg=fg;
	abr.fd=fd;
	return abr;
}

arbre joindre(arbre A, arbre B){
	arbre abr;
	abr.p=A.p+B.p;
	abr.fg=&A;
	abr.fd=&B;
	return abr;
}

arbre *reduire(arbre *tab, int n){
	//arbre tab1[n-1];
	arbre *tab1;
	tab1=(arbre *)malloc(sizeof(arbre)*(n-1));
	int i;
	for(i=0;i<n-2;i++)
		tab1[i]=tab[i];
	tab1[n-2]=joindre(tab[n-2],tab[n-1]);
	return tab1;
}


struct init *proba_init(char *fichier, int n){
	struct init *tab;
	int fd,i;
	char buf[10];
	struct init prov;
	tab=(struct init *)malloc(sizeof(struct init)*n);
	if((fd=open(fichier,O_RDONLY))==-1){
		fprintf(stderr,"erreur d'ouverture de :%s",fichier);
		exit(EXIT_FAILURE);
	}
	for(i=0;i<n;i++){
		read(fd,buf,1);
		prov.c=buf[0];//printf("%c ",buf[0]);
		read(fd,buf,1);
		read(fd,buf,7);
		prov.p=atof(buf);//printf("%f\n",prov.p);
		tab[i]=prov;
	}

	return tab;
}

void echange(struct init *a,struct init *b){
	double pro;
	char car;
	pro=a->p;
	car=a->c;
	a->p=b->p;
	a->c=b->c;
	b->p=pro;
	b->c=car;
}
	
void trier(struct init *tab,int n){
	int i,j;
	i=0;
	j=0;
	while(j<n-1){
		for(i=j;i<n;i++){
			if(tab[i].p<tab[j].p)
				echange(&tab[i],&tab[j]);
		}
		j++;
	}
}
	
arbre huffman_arbre(char *fichier, int n){
	arbre A;
	arbre *tab1,*prov;
	struct init *tab;
	int i;
	tab1=(arbre *)malloc(sizeof(arbre)*n);
	tab=proba_init(fichier,n);
	trier(tab,n);
	/*for(i=0;i<n;i++){
		printf("%c ",tab[i].c);
		printf("%f\n",tab[i].p);
		}*/

	for(i=0;i<n;i++)
		tab1[i]=constructeur(tab[i].c,tab[i].p,NULL,NULL);
	
	for(i=0;i<n-1;i++){
		prov=reduire(tab1,n-i);
		tab1=prov;
	}
	A=tab1[0];
	
	return A;
}
	

/* declaration des fonctions locales */
void dico_etape(arbre *, int, char **, char *);

void dico_etape(arbre *A, int profondeur, char **tab, char *sequence)
{
  char c;
  int i, j;
  if(A==NULL){
	  printf("null\n");
  }
  if (A->fg == NULL && A->fd == NULL)
    {
      c = A->c;
      if (c == ' ')
	i = 0;
      else
	i = c - 96;
      tab[i] = (char *)malloc((profondeur+1) * sizeof(char));
      for (j=0; j<profondeur; j++)
	tab[i][j] = sequence[j];
      tab[i][profondeur] = '\0';
      return;
    }
  sequence[profondeur] = '0';
  dico_etape(A->fg, profondeur+1, tab, sequence);
  sequence[profondeur] = '1';
  //dico_etape(A->fd, profondeur+1, tab, sequence);printf("dddddddddddddd\n");
  return;
}

char **dico(char *fichier, int n)
{
  arbre A;
  char **res;
  char *sequence;
  int i;
  
  A = huffman_arbre(fichier, n);
  res = (char**)malloc(n * sizeof(char *));
  sequence = (char *)malloc((n+1) * sizeof(char));
  dico_etape(&A, 0, res, sequence);
  
  printf("\n \t %s\n", res[0]);
  for (i=1; i<n; i++)
    printf("%c \t %s\n", i+96, res[i]);

  return(res);
}

