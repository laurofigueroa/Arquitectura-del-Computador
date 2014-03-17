#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double factorial(int n) {
	double res = 1;
	int i;

	for(i = 1; i <= n; i++) {
		res *= i;
	}
	return res;
}

double *taylor(int n, double x) {
	double s = 0;
	double *sol = calloc(sizeof(double),(n+1));
	int i;

	for(i = 0; i < n; i++) {
		sol[i] = (pow(-1,i) * pow(x, 2*i)) / factorial(2*i);
		s += sol[i];
	}
	sol[n] = s;
	return sol;
}

double kahan(double *x, int n) {

	double s = 0, c = 0;
	double y, t;
	int i;
	for(i = 0; i < n; i++) {
		y = x[i] - c;
		t=s+ y;	
		c = (t-s) - y;
		s=t;
	}
	return s;
}

int main(void) {

	int n = 100;
	double *t = taylor(n, 1);
	double K = kahan(t, n);

	//printf("%1.30f \n", t[n]); printf("%1.30f \n", K);
	printf("Taylor diff: %1.30f \n", t[n]-cos(1));
	printf("Kahan diff: %1.30f \n", K-cos(1));

	free(t);
	return 0;
}
