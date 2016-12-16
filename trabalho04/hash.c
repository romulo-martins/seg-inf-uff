#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// função devolve um array com os bits de paridade
// k não deveria ser passado como parametro mas para facilitar vou fazer isso
int* hamming_code(int* bits, int n, int k) {
	int i, j, t, sum, jump;

	// cria os bits da paridade
	int* p = (int*)malloc(k*sizeof(int));

	int b_size = k + n;
	// cria o array que vai ser o resultado da concatenação da paridade com os bits
	int* b = (int*)malloc(b_size*sizeof(int));

	// marca todos os bits de paridade com -1	
	for(i = 0; i < k; i++) {
		jump = pow(2, i)-1;
		b[jump] = -1;
	}

	// coloca os bits no array de bits concatenados
	j = 0;
	for (i = 0; i < b_size; i++) {
		if(b[i] != -1) {
			b[i] = bits[j++];
		}
	}
	
	// calcula a paridade
	for(i = 0; i < k; i++) {
		sum = 0;
		jump = pow(2, i)-1;
		for(j = jump; j < b_size; j += jump+1){
			for(t = 0; t < jump+1; t++) {
				if(b[j] != -1) sum += b[j];
				j++;
			}
		}
		p[i] = sum % 2;
	}
	free(b);

	return p;
}

void print_bits(int* bits, int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d", bits[i]);
	}
}

void read_bits(int* bits, int n) {
	int i;
	for (i = 0; i < n; i++) {
		scanf("%d", &bits[i]);
	}
}

int main() {
	
	int k, d; // k bits de paridade
	scanf("%d %d\n", &k, &d);

	int n = pow(2, k) - 1 - k; // onde n é o tamanho dos bits

	// limpa o buffer, não sei pq, mas as vezes tem que se fazer isso para imprimir bonitinho no console 
	// fflush(stdin); 

	int* bits = (int*)malloc(n*sizeof(int));
	read_bits(bits, n);

	int* p = hamming_code(bits, n, k);

	print_bits(bits, n);
	printf(" - ");
	print_bits(p, k);
	printf("\n");

	free(bits);
	free(p);
}

