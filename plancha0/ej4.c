#include <stdio.h>
#include <stdlib.h>

void codificar(char codigo) {
	unsigned int caracter;

	while(EOF != (caracter = getchar())){
		printf("%c",caracter^codigo);
	}
}

int main(int argc,char **argv) {
	
	codificar(atoi(argv[1]));
	return 0;
}
