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
	int u = 1;
	int v = 0;
	int v_2 = 1;
	int u_2 = 0;

	int A = a;
	int B = b;
	while (mod(A, B) != 0) {
		int q = A/B;
		int r = mod(A, B);
		A = b;
		B = r;
		int u_1 = u;
		u = u_2;
		u_2 = u_1 - q*u;
		int v_1 = v;
		v = v_2;
		v_2 = v_2 - q*v;
	}

	printf("a = %d, b = %d\n", a, b);
	printf("u = %d, v = %d\n", u, v);
	printf("a*u + v*b = %d\n", a*v + u*b);

	return u;
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