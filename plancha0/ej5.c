#include <stdio.h>

#define MAX_CHAR	256
#define P(x)		((alfabeto[x]*100)/(float)cant) /*Calcula el porcentaje de ocurrencias de un caracter */


void ocurrencias(void) {
	int caracter, i;  /*preguntar unsigned char caracter */
	int cant = 0;
	int alfabeto[MAX_CHAR];

	/*Limpia el arreglo de basura */
	for(i = 0; i < MAX_CHAR; i++)
		alfabeto[i] = 0;
	
	while(EOF != (caracter = getchar())) {
		alfabeto[caracter]++;
		cant++;
	}
	for(i = 0; i < MAX_CHAR; i++)
		if(P(i))
			printf("%c ocurrio %d veces %%  %.2f \n",i,alfabeto[i],P(i)); 
	
}

int main(void) {

	ocurrencias();
	return 0;
}
