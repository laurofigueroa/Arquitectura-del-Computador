#include <stdio.h>

void printbin (int a) {
	unsigned int size = sizeof(int)*8;
	unsigned int mascara = 1 << (size-1);
	
	while (mascara > 0) {
		if (mascara & a)
			printf("1");
		else
			printf("0");
		mascara = mascara >> 1; 
	} 
	puts("");
}

int main (int argc, char **argv) {
	printbin(65);
	printbin(-65);
	printbin(1 << (sizeof(int)*8-1));
	return 0;
}
