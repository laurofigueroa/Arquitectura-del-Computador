#include <stdio.h>
#include <setjmp.h>
#include "guindows.h"

task t1,t2,taskmain;

void ft1 (void) {
	double d;
	for(d = -1; ; d*0.001) {
		printf("d = %f",d);
		TRANSFER(t1, t2);
	}
}

void ft2 (void) {
	int i;
	for(i = 0; i < 10000; i++) {
		printf("i = %d",i);
		TRANSFER(t2, t1);
	}
	TRANSFER(t2, taskmain);
}

int main (int argc, char **argv) {
	stack(t1, ft1);
	stack(t2, ft2);
	TRANSFER(taskmain, t1);
	return 0;
}
