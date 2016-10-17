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
long mod_exp(long g, unsigned long a, long n) {
  long long pow = g % n;
  long long result = 1;

  for ( ; a > 0; a /= 2) {
    if (a % 2 == 1) {  // O bit menos significativo e 1
      result = (result * pow) % n;
  	}
    pow = (pow * pow) % n;
  }
  return result;
}

// algoritmo de euclides extendido para achar o inverso multiplicativo (a^(-1))mod(m)
long mod_inverse(long a, long m) {
    long m0 = m, t, q;
    long x0 = 0, x1 = 1;
 
    if (m == 1) return 0;
 
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
 
    if (x1 < 0) x1 += m0;
 
    return x1;
}

// verifica se o número é primo.
// neste caso evitamos os números pares e vamos até raiz de n.
// 	visto que, se d é maior que a raiz de n e d é um
//	divisor de n, então n/d é menor que raiz de n e é também divisor de n; 
//	por consequência, se n tem um divisor, encontraremos no instante em que chegar a raiz de n
int is_prime(long n) {
	if(n % 2 == 0) return 0; 

	long i;
	for(i = 3; i < sqrt(n) + 1; i += 2) { 
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
	return n; // não é possivel fatorar, ou seja o número n é primo
}

int main() {

	long n, e, c;
	scanf("%li %li %li", &n, &e, &c);

	long p = find_first_factor(n);
	long q = n/p;

	long d = mod_inverse(e, (p-1)*(q-1));
	long m = mod_exp(c, d, n);

	printf("%li\n", m);

}
