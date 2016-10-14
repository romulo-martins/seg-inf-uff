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

// algoritmo de euclides extendido para achar o inverso multiplicativo
int inverse_mult(int a, int b) {
	int r = a;
	int r1 = b;
	int u = 1;
	int v = 0;
	int u1 = 0;
	int v1 = 1;
        // variáveis auxiliares para efetuar trocas
	int rs, us, vs, q;

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

int main() {

	int a;
	printf("Informe o a: \n");
	scanf("%d", &a);

	int n;
	printf("Informe o n: \n");
	scanf("%d", &n);

	printf("(a^-1)mod(n) = %d\n", inverse_mult(a, n));
}