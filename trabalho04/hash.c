#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// interface
int* hamming_code(int* bits, int n, int k);
void print_bits(int* bits, int n);
void read_bits(int* bits, int n);
int** create_matrix(int lin, int row);
void free_matrix(int** mat, int lin);
void collision_analisys(int** p_mat, int d, int k);

// função devolve um array com os bits de paridade.
// k não deveria ser passado como parametro mas para facilitar fiz isto.
// o correto seria a função hamming code retornar o array "b" que é a 
// concatenação da paridade com os bits
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
			b[i] = bits[j];
			j++;
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

	// retorna os bits de paridade
	return p;
}

// verifica se dois arrays de paridade são iguais
int are_equals(int* p1, int* p2, int k) {
	int i;
	for(i = 0; i < k; i++) {
		if(p1[i] != p2[i]) return 0;
	}
	return 1;
}

// realiza a análise de colisoes que ocorreram
void collision_analisys(int** p_mat, int d, int k) {
	int i, j, colisions = 0, sum = 0;

	int visit[d]; // flag para marcar visitados
	for(i = 0; i < d; i++) visit[i] = 0;
	 
	for(i = 0; i < d-1; i++) {
		colisions = 0;
		for(j = i+1; j < d; j++) {
			if(!visit[j] && are_equals(p_mat[i], p_mat[j], k)) {
				colisions++;
				visit[j] = 1;	
			} 
		}
		if(colisions > 0) sum += (colisions + 1); // acrescenta 1 pra contar com o proprio 
	}
	float percent = ((float) sum / d)*100;

	printf("O numero de colisoes foi %.2f %%\n", percent);
}

// exibe na tecla do console os bits
void print_bits(int* bits, int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d", bits[i]);
	}
}

// le os bits a partir do console
void read_bits(int* bits, int n) {
	int i;
	for (i = 0; i < n; i++) {
		scanf("%d", &bits[i]);
	}
}

// aloca uma matriz dinamicamente
int** create_matrix(int lin, int row) {
	int** mat = (int**)malloc(lin*sizeof(int));
	int i;
	for(i = 0; i < lin; i++) {
		mat[i] = (int*)malloc(row*sizeof(int));
	}
	return mat;
}

// libera a matriz criada dinamicamente
void free_matrix(int** mat, int lin) {
	int i;
	for (i = 0; i < lin; i++) free(mat[i]);
	free(mat);

	return ;
}

int main() {
	
	int k, d; // k bits de paridade, e d entradas
	scanf("%d %d\n", &k, &d);

	int n = pow(2, k) - 1 - k; // onde n é o tamanho dos bits

	// limpa o buffer, não sei pq, mas as vezes tem que se fazer isso para exibir bonitinho no console 
	// fflush(stdin);

	// array de bits a serem lidos no console
	int* bits = (int*)malloc(n*sizeof(int));

	// matriz de paridades
	int** p_mat = create_matrix(d, k);

	int i, j;
	// executa d vezes para realizar a análise de colisoes
	for (i = 0; i < d; ++i) {
		read_bits(bits, n);

		// recebe o array de bits de paridade que são calculados pela função hamming code
		p_mat[i] = hamming_code(bits, n, k);

		print_bits(bits, n);
		printf(" - ");
		print_bits(p_mat[i], k);
		printf("\n");
	}

	// realiza a análise das colisoes
	collision_analisys(p_mat, d, k);

	free(bits);
	// free_matrix(p_mat, d); // está dando problema
}

