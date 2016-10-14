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
	int v_2 = 1;
	int u_2 = 0;

	int u = v_2;
	int v = u_2;
	while (mod(a, b) != 0) {
		int q = a/b;
		int r = mod(a, b);
		a = b;
		b = r;
		int u_1 = u;
		u = u_2;
		u_2 = u_1 - q*u;
		int v_1 = v;
		v = v_2;
		v_2 = v_2 - q*v;
	}

	printf("a = %d, b = %d\n", a, b);
	printf("u = %d, v = %d\n", u, v);
	printf("a*u + v*b = %d\n", a*u + v*b);

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