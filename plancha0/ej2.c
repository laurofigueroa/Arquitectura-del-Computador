#include <stdio.h>

int rotate(int a, int n) {
	int clon = a;
	unsigned int size = sizeof(int)*8;

	a >>= n;
	clon <<= (size) - n;

	return a | clon;

}

void printbin(int a) {
	unsigned int size = sizeof(int)*8;
	unsigned int mascara = 1 << (size-1);
	
	while(mascara > 0) {
		if(mascara & a)
			printf("1");
		else
			printf("0");
		mascara = mascara >> 1; 
	} 
	puts("");
}

int main(int argc, char **argv) {
	int x = 4;
	int n = 1;

	printbin(x);
	x = rotate(x,n);
	printbin(x);

	return 0;
}
