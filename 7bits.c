/*filtre de texte :
 * force à zero le bit de poids fort de chaque octet
 *
 */
#include<stdio.h>


int main(void){
	char c;
	do{
		c=getc(stdin);        /*lit un caractere sur l'entree */
		if(c!=EOF){
			c=c & 0x7f;   /*force bit 7 a zero */
			putc(c,stdout); /*ecrit le caractere*/
		}
	}while(c!=EOF);
	return 0;
}
