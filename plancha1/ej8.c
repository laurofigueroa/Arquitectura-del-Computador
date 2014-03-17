#include <stdio.h>
#include <gmp.h>
#include <stdlib.h>

/* Hecho por jagretti y lfigueroa */

typedef struct nro_ {
	short *n;
	int size;
} nro;

void print(nro n)
{
        int i;
        char str[1024];
        short sign[16], num[16];
        mpz_t n1, n2;
        for (i=0; i<15; i++) {
                num[i] = n.n[i];
                sign[i] = 0;
        }
        num[15] = n.n[15] & 0x7FFF;
        sign[15] = n.n[15] & 0x8000;
        mpz_init(n1);
        mpz_init(n2);
        mpz_import(n1, 16, -1, 2, 0, 0, num);
        mpz_import(n2, 16, -1, 2, 0, 0, sign);
        mpz_neg(n2, n2);
        mpz_add(n2, n1, n2);
        mpz_get_str(str, 10, n2);
        printf("Numero: %s\n", str);
        mpz_clear(n1);
        mpz_clear(n2);
}


nro *mas_chico(nro *n1, nro *n2) {
	if(n1->size > n2->size) return n2;
	else return n1;
}
	
nro *mas_grande(nro *n1, nro *n2) {
	if(n1->size > n2->size) return n1;
	else return n2;
}

nro *numero_nuevo(int size) {
	nro *nuevo = malloc(sizeof(nro));
	nuevo->n = malloc(sizeof(short)*size);
	nuevo->size = size;
	
	return nuevo;
}

nro *suma_variable(nro *n1, nro *n2) {
	int i, carry, tmp;

	nro *nuevo = numero_nuevo(mas_grande(n1, n2)->size);
	nro *auxg = mas_grande(n1, n2);
	nro *auxc = mas_chico(n1, n2);
	
	carry = 0;
	for(i = 0; i < auxc->size; i++) {
		tmp = (unsigned short)auxg->n[i] + (unsigned short)auxc->n[i] + carry;
		carry = (tmp & 0xffff0000) >> 16;
		nuevo->n[i] = tmp;
	}
	for(; i < auxg->size ; i++) {
		tmp = (unsigned short)auxg->n[i] + carry;
		nuevo->n[i] = tmp;
	} 
	return nuevo;
}

int main() {
	int i;
	nro *n1 = numero_nuevo(16);
	nro *n2 = numero_nuevo(8);
	nro *res = numero_nuevo(16);

	for(i = 0; i < 16; i++)
		n1->n[i] = 0;
	for(i = 0; i < 8; i++)
		n2->n[i] = 0;

	n1->n[0] = 8;
	n2->n[0] = 19;
	res = suma_variable(n1, n2);
	print(*res);
}


