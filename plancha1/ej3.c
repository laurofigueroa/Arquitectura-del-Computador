#include <stdio.h>

/* Realizado por jagretti y lfigueroa */

short abs_short(short x) {
	return(x + 2 *( x* (x >> 15)));
}

int main (void) {
	short x = 37;
	printf("%hd \n",abs_short(x));
	return 0;
}
