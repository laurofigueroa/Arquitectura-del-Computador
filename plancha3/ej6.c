#include <stdio.h>
#include <ieee754.h>

typedef struct float_ {
	unsigned int s:1;
	unsigned int m:18;
	unsigned int e:16;
} flotante;


flotante suma(flotante n1, flotante n2) {
  
  flotante res;
  unsigned int aux;

  if(n1.e == 0)
    return n2;
  if(n2.e == 0)
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
