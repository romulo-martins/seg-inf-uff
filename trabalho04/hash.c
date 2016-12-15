#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void read_bits(int* bits, int n) {
	int i;
	for (i = 0; i < n; i++) {
		scanf("%d ", &bits[i]);
	}
	scanf("\n");	
}

void print_bits(int* bits, int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", bits[i]);
	}
	printf("\n");
}


int main() {
	
	int k, d; // k bits de paridade
	scanf("%d %d\n", &k, &d);

	int n = pow(2, k) - 1 - k; // onde n é o tamanho dos bits

	int* bits = (int*)malloc(n*sizeof(int));
	read_bits(bits, n);

	print_bits(bits, n);

	free(bits);
}