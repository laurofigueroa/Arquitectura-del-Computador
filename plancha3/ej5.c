#include <stdio.h>
#include <ieee754.h>

#define mantisa(a)	((*((unsigned *)&a) & 0x007fffff))
#define exponente(a)	((*((unsigned *)&a) & 0x7f800000)>>23)

typedef struct float_ {
	unsigned int s:1;
	unsigned int m:18;
	unsigned int e:16;
} flotante;

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

flotante suma(flotante n1, flotante n2) {
  
  flotante res;
  unsigned int aux;

  if(n1.m == 0)
    return n2;
  if(n2.m == 0)
    return n1;

  if(n1.e < n2.e) {
    n1.m >>= (n2.e - n1.e);
    res.e = n2.e - n1.e;
  } else {
    n2.m >>= (n1.e - n1.e);
    res.e = n1.e - n2.e;
  }

  if(n1.s == n2.s)
    aux = n1.m + n2.m;
  if(n1.s == 1 && n2.s == 0)
    aux = n2.m - n1.m;
  else
    aux = n1.m - n2.m;

  if((1U << 18) < aux) {
    res.e += 1;
    res.m = aux >> 1;
  }
  else
    res.m = aux;

  return res;

} 

num multiplicacion(num n1, num n2) {

  unsigned int aux = 0;
  num res;

  if(n1.m == 0) 
    return n1;
  if(n2.m == 0)
    return n2;

  res.e = n1.e + n2.e;
  aux = n1.m * n2.m;
	
  if(n1.sig == n2.sig)
    res.s = 0;
  else
    res.s = 1;

  if(aux >= (1<<18)) {
    res.m = aux>>1;
    res.e = res.e+1;
  } else
    res.m = aux;
  
  return res;
}
