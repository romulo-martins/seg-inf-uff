#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_LENGHT 100
#define MAX_STRING_LENGHT 10000

#define ALPHABET "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define N 26

int mod(int a, int b) {
    if(a >= 0) {
        return a % b;
    }
    else {
        return a + b*((b - a - 1)/b);
    }
}

int get_char_index(char c) {
	int i;
	for(i = 0; i < N; i++) {
		if(ALPHABET[i] == c) {
			return i;
		}
	}
	return -1;
}

void decypher(char* text, int n) {
	char* aux_text = (char*)malloc(MAX_STRING_LENGHT * sizeof(char));

	int i = 0;
	while(text[i] != '\0') {
		int index = mod(get_char_index(text[i]) + n, N);
		aux_text[i] = ALPHABET[index];
		i++;		
	}
	aux_text[i] = '\0';

	printf("Delocamento: %d, Texto: %s \n", n, aux_text);

	free(aux_text);
} 


int main() {
	char text[MAX_STRING_LENGHT];

	printf("Informe o texto: \n");
	setbuf(stdin, NULL);
	scanf("%[^\n]s", text);

	int i;
	for (i = 0; i < N; i++)	{
		decypher(text, i);
	}

}
