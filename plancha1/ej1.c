#include <stdio.h>

/* Realizado por jagretti y lfigueroa */

#define BITCOUNT(x) (((BX_(x)+(BX_(x)>>4)) & 0x0F0F0F0F) % 255)
#define BX_(x) ((x) - (((x)>>1)&0x77777777) \
     - (((x)>>2)&0x33333333) \
     - (((x)>>3)&0x11111111))

int hamming(int bin1, int bin2) {
	return(BITCOUNT(bin1^bin2));
}

int main (int argc, char **argv) {
	printf("%d \n",hamming(11,5));
	return 0;
}
