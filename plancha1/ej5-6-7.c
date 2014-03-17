#include <stdio.h>
#include <gmp.h>

/* Hecho por jagretti y lfigueroa */

typedef struct { short n[16]; } nro;

#define SIZE   16
#define SHIFTI(n)   (n<<1)
#define SHIFTD(n)   (n>>1)
#define BIT15(n)    (n&0x8000)
#define BIT1(n)     (n&0x0001)

void print(nro n)
{
	int i;
	char str[1024];
	short sign[16], num[16];
	mpz_t n1, n2;
	for (i=0; i<15; i++) {
		num[i] = n.n[i];
		sign[i] = 0;
	
	}
	num[15] = n.n[15] & 0x7FFF;
	sign[15] = n.n[15] & 0x8000;
	mpz_init(n1);
	mpz_init(n2);
	mpz_import(n1, 16, -1, 2, 0, 0, num);
	mpz_import(n2, 16, -1, 2, 0, 0, sign);
	mpz_neg(n2, n2);
	mpz_add(n2, n1, n2);
	mpz_get_str(str, 10, n2);
	printf("Numero: %s\n", str);
	mpz_clear(n1);
	mpz_clear(n2);

}

nro negate(nro numero) {
	int i;
	for(i = 0; i < 16; i++) 
		numero.n[i] = ~(numero.n[i]);

	return numero;
}

nro suma1(nro numero) {

	int i;
	short carry = 1;

	for(i = 0; i < 16; i++) {
		if(numero.n[i] != -1) {
			numero.n[i] += carry;
			return numero;
		}
		else {
			numero.n[i] = 0;
			carry = 1;
		}
	}

	return numero;
}

nro negacion_unaria(nro numero) {
	return suma1(negate(numero));
}

int equal(nro num1, nro num2) {

	int i, res = 1;
	for(i = 0; i < 16; i++)
		if(num1.n[i] != num2.n[i])
	 		res = 0;
		
	return res;
}

nro cero_(void) {

	int i;
	nro numero;
	for(i = 0; i < 16; i++)
		numero.n[i] = 0;

	return numero;
}

nro menos1(nro numero) {

	int i,carry = 1;
  nro cero = cero_();
  nro mayor_negativo; /* Mayor negativo representable */

  if(equal(numero, cero)) {
    for(i = 0; i < SIZE; i++) {
      numero.n[i] = -1;
    }
    return numero;
  }

  mayor_negativo = cero_();
  mayor_negativo.n[15] = 0x8000;

  if(equal(mayor_negativo, numero)) {
    printf("ERROR - OVERFLOW (MENOS)\n");
    return numero;
  }

  for(i = 0; i < SIZE; i++) {
    if(numero.n[i] != 0) {
      numero.n[i] = (numero.n[i])-1;
      return numero;
    }
    numero.n[i] = -1;
  }
	return numero;
}


nro producto(nro n1, nro n2) {
	
	unsigned int i, j, tmp, carry;
	nro res = cero_();

	carry = 0;
	for(i = 0; i < SIZE; i++) {
		tmp = 0;
		for(j = 0; j <= i; j++) {
			tmp += ((unsigned short)n1.n[j]*(unsigned short)(n2.n[i-j]));
		}
		tmp += carry;
		carry = (tmp & 0xffff0000)>>16;
		res.n[i] = tmp;
			
	}
	return res;
}



nro shift_d(nro n1) {
  int i;
  short tmp, carry = 0;
  
  for(i = 15; i >= 0; i--){
    if(i == 15) {
      carry = BIT1(n1.n[i]);
      n1.n[i] = SHIFTD(n1.n[i]);
    } else {
      tmp = carry<<15;
      carry = BIT1(n1.n[i]);
      n1.n[i] = SHIFTD((unsigned short)n1.n[i]) | tmp;
    }
  }
  return n1;
}

nro shift_i(nro n1) {
  int i;
  unsigned short tmp, carry = 0;

  for(i = 0; i < SIZE; i++){
    tmp = carry>>15;
    carry = BIT15(n1.n[i]);
    n1.n[i] = SHIFTI(n1.n[i]) | tmp;
  }
  return n1;

}

nro mas_(nro n1, nro n2) {
  int i, tmp;
  short carry = 0;
  nro res, cero;
  cero = cero_();

  if(equal(n1,cero) || equal(n2, cero))
    if(equal(n1, cero))
      return n1;
    else
      return n2;

  for(i = 0; i < SIZE; i++) {
    tmp = (unsigned short)n1.n[i] + 
          (unsigned short)n2.n[i] + carry;
    carry = (tmp & 0xffff0000)>>16;
    n1.n[i] = tmp;
  }
  if(carry != 0)
    printf("ERROR - OVERFLOW (SUMA) \n");

  return n1;
}

nro producto_campesino_ruso(nro n1, nro n2) {
  nro cero = cero_();
  if(equal(n2,cero))
    return cero;
  cero.n[0] = 1; /* cero es numero uno */
  if(equal(n2,cero))
    return n1;
  if(BIT1(n2.n[0]) == 0)
    return producto_campesino_ruso(shift_i(n1),shift_d(n2));
  else
    return mas_(producto_campesino_ruso(shift_i(n1),(shift_d(menos1(n2)))),n1);
}

int main(void) {

	int i;
	nro numero;
	nro n1,n2,cero;

	printf("------ EJ5: NEGACION UNARIA ------- \n");	
	numero = cero_();
	numero.n[0] = -1;
	print(numero);
	numero = negacion_unaria(numero);
	print(numero);



	printf("------ EJ6: PRODUCTO ------- \n");	

  printf("Ejemplo 1: \n");
	n1 = cero_();
	n2 = cero_();
	cero = cero_();

	n1.n[1] = -1;
	n2.n[0] = 2;
	print(n1);
	print(n2);
	numero = producto(n1,n2);
	printf("RESULTADO>> \t");
	print(numero);

  printf("Ejemplo 2: \n");
	n1 = cero_();
  for(i = 0; i < SIZE; i++)
    n1.n[i] = -1;
  n1.n[0] = 0; 
	n2.n[0] = 2;
	print(n1);
	print(n2);
	numero = producto(n1,n2);
	printf("RESULTADO>> \t");
	print(numero);

	printf("------ EJ7: ALG. CAMPESINO RUSO ------ \n");	
  printf("Funciones auxiliares\n");
	printf("--- SHIFT --- \n");	

	n1 = cero_();
	n2 = cero_();
	cero = cero_();

  n1.n[1] = 2;
  n2.n[0] = 32768;

	print(n1);
	numero = shift_d(n1);
	printf("RESULTADO shift_d>>Numero \t");
	print(numero);
	print(n2);
	numero = shift_i(n2);
	printf("RESULTADO shift_i<<Numero \t");
	print(numero);

	printf("--- MENOS1 --- \n");	

  numero = cero_();
  numero.n[2] = 0x7000;
  numero.n[1] = -1;
  print(numero);
  numero = menos1(numero);
	printf("RESULTADO>>\t");	
  print(numero);

	printf("--- MAS_ --- \n");	
  
	n1 = cero_();
	n2 = cero_();
  n1.n[0] = -1;
  n2.n[0] = -1;
	print(n1);
	print(n2);

  numero = mas_(n1, n2);
	printf("RESULTADO>>\t");	
	print(numero);
  
	printf("--- CAMPESINO_RUSO --- \n");	

  numero = cero_();
	n1 = cero_();
	n2 = cero_();
  n1.n[1] = 1;
  n2.n[1] = 20;

	print(n1);
	print(n2);

	printf("RESULTADO>>\t");	
  numero = producto_campesino_ruso(n1, n2);
	print(numero);

	return 0;
}
