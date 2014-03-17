#include <stdio.h>

/* Realizado por jagretti y lfigueroa */

int not(int bin) {
	return bin^(-1);
}

int main() {
	int bin = 10;
//	printf("%d \n", bin);
	printbin(bin);
	
	bin = not(bin);
	printbin(bin);
//	printf("%d \n", bin);
	return 0;
}
