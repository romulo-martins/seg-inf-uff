#include <stdio.h>
#include <stdlib.h> 
#include <math.h>

// função para tratar o mod, já que o '%' retorna numeros negativos
long mod(long a, long b) {
    if(a >= 0) {
        return a % b;
    }
    else {
        return a + b*((b - a - 1)/b);
    }
}

// algoritmo para executar k = (g^a)mod(n) de forma eficiente
long mod_exp(long g, long a, long n) {
  long result, pot;

  pot = g % n;
  result = 1;

  for( ; a > 0; a /= 2) {
    if (a % 2 == 1)  // O bit menos significativo e 1
      result = (result * pot) % n;

    pot = (pot * pot) % n;
  }
  return result;
}

// algoritmo de euclides extendido para achar o inverso multiplicativo
long inverse_mult(long a, long b) {
	long r = a;
	long r1 = b;
	long u = 1;
	long v = 0;
	long u1 = 0;
	long v1 = 1;
        // variáveis auxiliares para efetuar trocas
	long rs, us, vs, q;

	while (r1 != 0){
		q = r / r1; // pega apenas a parte inteira
		rs = r;
		us = u;
		vs = v;
		r = r1;
		u = u1;
		v = v1;
		r1 = rs - q*r1;
		u1 = us - q*u;
		v1 = vs - q*v1;
	}
	return r*u + v*b;
}

// verifica se o número é primo
long is_prime(long n) {
	long i;
	for(i = 2; i < n; i++) {
		if(n % i == 0) return 0;
	}
	return 1;
}

// encontra o primeiro fator primo p, já que n = p*q, 
// podemos descobrir q fazendo q = n/p
long find_first_factor(long n) {
	if(n % 2 == 0) return 2;

	long i;
	// o laço percorre apenas números impares
	for (i = 3; i < n; i += 2) {
		if(is_prime(i) && (n % i == 0)) {
			return i;
		}
	}
	return n; // não é possivel fatorar, ou seja o número é primo
}

int main() {

	long n, e, c;
	scanf("%li %li %li", &n, &e, &c);

	long p = find_first_factor(n);
	long q = n/p;

	long d = inverse_mult(e, (p-1)*(q-1));
	long m = mod_exp(c, d, n);

	printf("%li\n", m);

	printf("FIM!\n");

}
