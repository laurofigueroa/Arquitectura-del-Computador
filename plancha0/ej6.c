#include <stdio.h>
#include <string.h>

typedef struct {
	char clave[10];
	int otrosdatos;
} registro;

int cmp(void *d1, void *d2) {
	int i;
	char *c1 = ((registro *)d1)->clave;
	char *c2 = ((registro *)d2)->clave;

	for(i = 0; i < 10; i++) {
		if(c1[i] != c2[i])
			return c1[i]-c2[i];
	}
	return 0;
}

void ordenar_registro(registro *base, int nelems) {

	qsort(base,nelems,sizeof(registro),cmp);
	return;
}

int main(void) {

	/* Ejemplo */
	registro base[2];
	scanf("%s",base[0].clave);
	scanf("%s",base[1].clave);
	int nmemb = 2;

	ordenar_registro(base,nmemb);
	
	printf("base[0] = %s - base[1] = %s \n",base[0].clave,base[1].clave);
	return 0;
}
