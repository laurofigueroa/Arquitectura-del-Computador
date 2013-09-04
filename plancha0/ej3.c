#include <stdio.h>

void swap3(int *a, int *b, int *c) {
	*b = *b^*c;
	*c = *b^*c;
	*b = *b^*c;
	*a = *a^*b;
	*b = *a^*b;
	*a = *a^*b;
}

int main(int argc, char **argv) {

	int a = 10, b = 52, c = -5;
	
	printf("a = %d - b = %d - c = %d \n", a, b, c);

	swap3(&a, &b, &c);

	printf("a = %d - b = %d - c = %d \n", a, b, c);

	return 0;
}
