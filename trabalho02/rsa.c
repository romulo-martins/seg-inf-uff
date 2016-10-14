#include <stdio.h>
#include <stdlib.h> 

// verifica se o número é primo
int is_prime(int n) {
	int i;
	for(i = 2; i < n; i++) {
		if(n % i == 0) return 0;
	}
	return 1;
}

int mult_inverse(int n) {
	
}


// fatora n, para descobrir quais primos p e q são n = p*q
void factoring(int n) {
	int i;
	int p, q;
	for (i = 3; i < n; i += 2) {
		if(is_prime(i) && (n % i == 0)) {
			p = i;
			q = n / i;
			break;
		}
	}
	printf("p = %d, q = %d, n = %d\n", p, q, p*q);
}

int main() {

	int n;

	printf("Informe um número: \n");
	scanf("%d", &n);

	factoring(n);
}
