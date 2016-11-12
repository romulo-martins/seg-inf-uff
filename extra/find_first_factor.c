#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// verifica se o número é primo.
// neste caso evitamos os números pares e vamos até raiz de n.
// 	visto que, se d é maior que a raiz de n e d é um
//	divisor de n, então n/d é menor que raiz de n e é também divisor de n,
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
	long n;
	scanf("%li", &n);

	long p = find_first_factor(n);
	long q = n/p;

	printf("p = %li, q = %li\n", p, q);
}