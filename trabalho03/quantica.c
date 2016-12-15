#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BASE_SIZE 3 // o tamanho do vetor com as bases.

char base[BASE_SIZE] = {'+', 'x', 'o'};
char table[BASE_SIZE][2] = {{'^', '>'}, 
							{'/', '\\'}, 
							{'@', 'G'}};

char* create_char_array(int size) {
	return (char*)malloc(sizeof(char)*size);
}

int* create_integer_array(int size) {
	return (int*)malloc(sizeof(int)*size);
} 

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

// procura o indice na tabela do caractere passado como parametro, utilizando a tabela de caracteres
int get_element_index(char c) {
	int i, j; 
	for (i = 0; i < BASE_SIZE; ++i)	{
		for (j = 0; j < 2; j++) {
			if(table[i][j] == c) return j;
		}		
	}
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

// realiza a polarização
char* polarize(int* bits, char* chosen_base, int bits_size) {
	char* p = create_char_array(bits_size);

	int i;
	for (i = 0; i < bits_size; i++)	{
		int base_index = get_base_index(chosen_base[i]);
		int bit_index = bits[i];
		p[i] = table[base_index][bit_index];
	}

	return p;
}

// a partir de uma polarização descobre sua base
char* polarize_to_base(char* polarized, char* chosen_base, int n) {
	char* temp = create_char_array(n);	

	int i;
	for (i = 0; i < n; i++)	{
		temp[i] = chosen_base[get_element_index(polarized[i])];
	}
	return temp;
}

// compara as bases e retorna os bits do resultado final em binário, atribui -1 aos bits jogados fora (ou seja, não estão nas mesmas bases)
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

// gera um array de bits binários aleatóriamente 
int* generate_bits(int n) {
	int* bits = create_integer_array(n);

	int i;
	for (i = 0; i < n; i++)	{
		bits[i] = rand() % 2;
	}

	return bits;
}

// passa de um array de bits binários para a base em relação ao vetor de bases
char* bits_to_base(int* bits, char* chosen_base, int n) {
	char* base_temp = create_char_array(n);

	int i;
	for (i = 0; i < n; i++)	{
		base_temp[i] = chosen_base[bits[i]];
	}

	return base_temp;	
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

void execute_test1() {
	int s, n;
	s = 0, n = 8; // inicialização para teste

	char b[2]; // bases a serem escolhidas	
	b[0] = '+', b[1] = 'x'; // inicialização para teste

	int bits[] = {0, 1, 1, 0, 1, 1, 0, 1};
	
	int alice_base_bits[] = {0, 1, 0, 0, 0, 0, 0, 0};

	char* alice_base = bits_to_base(alice_base_bits, b, n);		

	char* polarized = polarize(bits, alice_base, n);
	print_base(polarized, n);
	
	// char bob_base[] = {'+', 'x', 'x', 'x', '+', 'x', '+', '+'};
	char* bob_base = read_base(n);

	int* result = compare_bases(polarized, alice_base, bob_base, n);
	long long final_result = binary_to_decimal(result, n);

	printf("%lli\n", final_result);

	free(alice_base);
	free(polarized);
	free(result);	
}

void execute_test2() {
	int s, n;
	s = 0, n = 8; // inicialização para teste

	char b[2]; // bases a serem escolhidas	
	b[0] = 'x', b[1] = 'o'; // inicialização para teste

	int bits[] = {0, 1, 1, 0, 1, 1, 0, 1};

	int alice_base_bits[] = {0, 1, 0, 0, 0, 0, 0, 0};

	char* alice_base = bits_to_base(alice_base_bits, b, n);		

	char* polarized = polarize(bits, alice_base, n);
	print_base(polarized, n);
		
	// char bob_base[] = {'x', 'o', 'o', 'o', 'x', 'o', 'x', 'x'};
	char* bob_base = read_base(n);

	int* result = compare_bases(polarized, alice_base, bob_base, n);
	long long final_result = binary_to_decimal(result, n);

	printf("%lli\n", final_result);

	free(alice_base);
	free(polarized);
	free(result);
}

void execute_test3() {
	int s, n;
	s = 42, n = 100; // inicialização para teste

	char b[2]; // bases a serem escolhidas	
	b[0] = '+', b[1] = 'o'; // inicialização para teste

	char* polarized = read_base(n);
	print_base(polarized, n);

	char* alice_base = polarize_to_base(polarized, b, n);		
	char* bob_base = read_base(n);

	int* result = compare_bases(polarized, alice_base, bob_base, n);
	long long final_result = binary_to_decimal(result, n);

	printf("%lli\n", final_result);

	free(alice_base);
	free(result);
}

void execute_program() {
	int s, n;
	scanf("%d %d\n", &s, &n);

	char b[2]; // bases a serem escolhidas	
	scanf("%c %c", &b[0], &b[1]);	

	srand(s);

	int* bits = generate_bits(n);
	
	int* alice_base_bits = generate_bits(n);

	char* alice_base = bits_to_base(alice_base_bits, b, n);		

	char* polarized = polarize(bits, alice_base, n);
	print_base(polarized, n);
	
	char* bob_base = read_base(n); 

	int* result = compare_bases(polarized, alice_base, bob_base, n);
	long long final_result = binary_to_decimal(result, n);

	printf("%lli\n", final_result);

	free(bits);
	free(alice_base);
	free(polarized);
	free(result);
	free(bob_base);
}


int main() {
	// execute_test1();
	// execute_test2();
	execute_test3();
	// execute_program();	

	return 0;
}
