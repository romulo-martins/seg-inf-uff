#include <stdio.h>
#include <stdlib.h>

#define BASE_SIZE 3 // o tamanho do vetor com as bases.

char base[BASE_SIZE] = {'+', 'x', 'o'};
char table[BASE_SIZE][2] = {{'^', '>'}, 
							{'/', '\\'}, 
							{'@', 'G'}};

// devolve o indice do elemento da base
int base_index(char c) {
	int i;
	for (i = 0; i < BASE_SIZE; i++)	{
		if(base[i] == c) return i;
	}
	return -1; // não achou
}


int main() {

	int s, n;
	scanf("%d %d", &s, &n);	
	

	return 0;
}