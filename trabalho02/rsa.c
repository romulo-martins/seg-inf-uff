#include <stdio.h>
#include <stdlib.h> 

// função para tratar o mod, já que o '%' retorna numeros negativos
int mod(int a, int b) {
    if(a >= 0) {
        return a % b;
    }
    else {
        return a + b*((b - a - 1)/b);
    }
}

// verifica se o número é primo
int is_prime(int n) {
	int i;
	for(i = 2; i < n; i++) {
		if(n % i == 0) return 0;
	}
	return 1;
}

// encontra o primeiro fator primo p, já que n = p*q, 
// podemos descobrir q fazendo q = n/p
int find_first_factor(int n) {
	if(n % 2 == 0) return 2;

	int i;
	// o laço percorre apenas números impares
	for (i = 3; i < n; i += 2) {
		if(is_prime(i) && (n % i == 0)) {
			return i;
		}
	}
	return n; // não é possivel fatorar, ou seja o número é primo
}

int main() {

	int n, e, c;
	scanf("%d %d %d", &n, &e, &c);

	int p = find_first_factor(n);
	int q = n/p;

	int d = mod(1/e, (p-1)*(q-1));

	if(is_prime(q)) {
		printf("p = %d, q = %d, n = %d\n", p, q, p*q);
		printf("d = %d\n", d);
	}
	else {
		printf("ERRO: %d não é primo!\n", q);
	}

	printf("FIM!\n");

}
