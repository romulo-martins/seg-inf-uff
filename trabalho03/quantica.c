#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BASE_SIZE 3 // o tamanho do vetor com as bases.

char base[BASE_SIZE] = {'+', 'x', 'o'};
char table[BASE_SIZE][2] = {{'^', '>'}, 
							{'/', '\\'}, 
							{'@', 'G'}};

// devolve o indice do elemento da base
int get_base_index(char c) {
	int i;
	for (i = 0; i < BASE_SIZE; i++)	{
		if(base[i] == c) return i;
	}
	return -1; // não achou
}

char* polarize(int* bits, char* chosen_base, int bits_size) {
	char* p = (char*)malloc(sizeof(char)*bits_size);

	int i;
	for (i = 0; i < bits_size; i++)	{
		int base_index = get_base_index(chosen_base[i]);
		int bit_index = bits[i];
		p[i] = table[base_index][bit_index];
	}

	return p;
}

void print_base(char* c, int bits_size) {
	int i;
	for (i = 0; i < bits_size; i++)	{
		printf("%c", c[i]);
	}
	printf("\n");
}

void print_bits(int* b, int bits_size) {
	int i;
	for (i = 0; i < bits_size; i++)	{
		printf("%d", b[i]);
	}
	printf("\n");
}

int* generate_bits(int n) {
	int* bits = (int*)malloc(sizeof(int)*n);
	
	srand(time(NULL));

	int i;
	for (i = 0; i < n; i++)	{
		bits[i] = rand() % 2;
	}

	return bits;
}

char* generate_base(char b1, char b2, int n) {
	char* base = (char*)malloc(sizeof(char)*n);
	
	srand(time(NULL));

	int i;
	for (i = 0; i < n; i++)	{
		int random_index = rand() % 2;
		if(random_index) {
			base[i] = b1;
		}
		else {
			base[i] = b2;
		}
		
	}

	return base;	
}

int main() {

	int s, n;
	scanf("%d %d", &s, &n);

	char b1 = '+', b2 = 'x'; // bases a serem escolhidas	
	//scanf("%c %c", &b1, &b2);

	printf("%c %c\n", b1, b2);

	int* bits = generate_bits(n);
	char* chosen_base = generate_base(b1, b2, n);

	print_bits(bits, n);
	print_base(chosen_base, n);

	char* polarized = polarize(bits, chosen_base, n);
	print_base(polarized, n);

	free(bits);
	free(chosen_base);
	free(polarized);

	return 0;
}