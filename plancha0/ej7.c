#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int CmpFunc(void *, void *);

int cmp(void *a, void *b) {
	return *((int*)a)-*((int*)b);
}

/* acomodar se encarga de ubicar el elemento en la posicion pos en su lugar correspondiente 
 * y no altera la propiedad de que todos sus anteriores estan ordenados 
 */
void acomodar(void *base, size_t size, int nelems, int pos, CmpFunc cmp) {

	void *aux = malloc(size);
	void *indice = base + size*pos;

	while(((indice - size) >= base) && (cmp(indice, indice - size) < 0)) {
		memcpy(aux, indice, size);
		memcpy(indice, indice - size, size);
		memcpy(indice - size, aux, size);
		indice -= size;
	}
	free(aux);
	return;
}

void insertion(void *base, size_t size, int nelems, CmpFunc cmp) {
	int i;
	void *tmp = base;
	
	if(base == NULL) {
		printf("ERROR\n");
		return;
	}
	tmp = base;
	for(i = 1; i < nelems; i++) 
		acomodar(base, size, nelems, i, cmp);
	return;
}	

int main(int argc, char **argv) {

	int i;
	int arr[10] = {1, 8, 7, 6, 5, 34, -5, -3, 0, 75};
	int nelems = sizeof(arr)/sizeof(int);
 
	insertion(arr,sizeof(int),nelems,cmp);

	for(i = 0; i < nelems; i++)
		printf("%d ",arr[i]);
	puts("");

	return 0;
}
