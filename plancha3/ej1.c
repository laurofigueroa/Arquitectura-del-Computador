#include <stdio.h>
#include <ieee754.h>

#define mantisa(a)	((*((unsigned *)&a) & 0x007fffff))
#define exponente_(a)	((*((unsigned *)&a) & 0x7f800000)>>23)

int fraccion(float a) {
	unsigned *aux = (unsigned *)&a;
	unsigned n = *aux;

	n &= 0x007fffff;

	return n;
}

int exponente(float a) {
	unsigned *aux = (unsigned *)&a;
	unsigned n = *aux;

	n &= 0x7f800000;
	n >>= 23;

	return n;
}

main() {
	float a = 3.14;

	int b = fraccion(a);
	int c = exponente(a);

	printbin(b);
	printbin(c);
	
	b = mantisa(a);
	c = exponente_(a);
	printbin(b);
	printbin(c);

	union ieee754_float uf;
	uf.f = 3.14;
	printf("%d \n", uf.ieee.mantissa);
	printf("%d \n", mantisa(uf.f));

	return 0; 
}
