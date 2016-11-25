#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BASE_SIZE 3 // o tamanho do vetor com as bases.

char base[BASE_SIZE] = {'+', 'x', 'o'};
char table[BASE_SIZE][2] = {{'^', '>'}, 
							{'/', '\\'}, 
							{'@', 'G'}};

long long binary_to_decimal(int* bits, int bits_length) {
	int i;
	long long decimal_value = 0;
	int exponent = 0;
	for(i = bits_length-1; i > 0; i--) {
		if(bits[i] != -1) {
			decimal_value += bits[i]*pow(2, exponent++);
		}		
	}
	return decimal_value;
}

// devolve o indice do elemento da base
int get_base_index(char c) {
	int i;
	for (i = 0; i < BASE_SIZE; i++)	{
		if(base[i] == c) return i;
	}
	return -1; // não achou
}

int get_element_index(char c) {
	int i, j; 
	for (i = 0; i < BASE_SIZE; ++i)	{
		for (j = 0; j < 2; j++) {
			if(table[i][j] == c) return j;
		}		
	}
}

char* create_char_array(int size) {
	return (char*)malloc(sizeof(char)*size);
}

int* create_integer_array(int size) {
	return (int*)malloc(sizeof(int)*size);
} 

char* read_base(int n) {
	char* base_to_read = create_char_array(n);
	int i;
	for (i = 0; i < n-1; ++i) {
		scanf("%c ", &base_to_read[i]);
	}
	scanf("%c", &base_to_read[i]);
	
	return base_to_read;
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

int* compare_bases(char* polarized, char* a_base, char* b_base, int n) {
	int* r_base = create_integer_array(n);
	int i;
	for(i = 0; i < n; i++) {
		if(a_base[i] == b_base[i]) {
			r_base[i] = get_element_index(polarized[i]);
		}
		else {
			r_base[i] = -1;
		}
	}
	return r_base;
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
		if(b[i] != -1) {
			printf("%d", b[i]);	
		}
		else {
			printf("-");
		}		
	}
	printf("\n");
}

int* generate_bits(int n) {
	int* bits = create_integer_array(n);

	int i;
	for (i = 0; i < n; i++)	{
		bits[i] = rand() % 2;
	}

	return bits;
}

char* generate_base(char* b, int n) {
	char* base = create_char_array(n);

	int i;
	for (i = 0; i < n; i++)	{
		int random_index = rand() % 2;
		if(random_index) {
			base[i] = b[1];
		}
		else {			
			base[i] = b[0];
		}		
	}

	return base;	
}

int main() {

	int s, n;
	// scanf("%d %d\n", &s, &n);
	s = 0, n = 8; // inicialização para teste

	char b[2]; // bases a serem escolhidas	
	// scanf("%c %c", &b[0], &b[1]);	
	b[0] = '+', b[1] = 'x'; // inicialização para teste

	srand(s);
	
	int* bits = generate_bits(n);
	// int bits[] = {0, 1, 1, 0, 1, 1, 0, 1};
	print_bits(bits, n);

	char* alice_base = generate_base(b, n);
	// char alice_base[] = {'+', 'x', '+', '+', '+', '+', '+', '+'};		
	print_base(alice_base, n);

	char* polarized = polarize(bits, alice_base, n);
	print_base(polarized, n);
	
	char bob_base[] = {'+', 'x', 'x', 'x', '+', 'x', '+', '+'};
	// char* bob_base = read_base(n); 

	int* result = compare_bases(polarized, alice_base, bob_base, n);
	long long final_result = binary_to_decimal(result, n);

	printf("%lli\n", final_result);

	free(bits);
	free(alice_base);
	free(polarized);
	free(result);

	return 0;
}
