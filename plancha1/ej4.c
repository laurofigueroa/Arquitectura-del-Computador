#include <stdio.h>

/* Hecho por jagretti y lfigueroa */

#define mod(x)	(x & 1U)

unsigned mult(unsigned a, unsigned b) {

	if(b == 0)
		return 0;
	if(b == 1) 
		return a;	
	if(mod(b) == 0) {
		return mult(a << 1, b >> 1);
	}
	else {
		return mult(a << 1, (b-1) >> 1) + a;
	}	

}

int main() {
	printf("%u \n", mult(20, 7));
	printf("%u \n", mult(35, 2));
	printf("%u \n", mult(0, 10));
	printf("%u \n", mult(1,7));
}

