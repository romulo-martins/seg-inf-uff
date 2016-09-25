#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_LENGHT 100
#define ALPHABET "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define N 26

int get_char_index(char c) {
	int i;
	for(i = 0; i < N; i++) {
		if(ALPHABET[i] == c) {
			return i;
		}
	}
	return -1;
}

void encrypt(char* text, int key) {
	int i;
	for(i = 0; text[i] != '#'; i++) {
		int index = get_char_index(text[i]);
		if(index != -1) {
			int index_sub = (index + key) % N;
			text[i] = ALPHABET[index_sub];
			key = index_sub + key + 1;			
		}							
	}
}

int main() {

	int i;
	int key;
	char choice;
	char text[STRING_LENGHT];

	printf("Digite D para decriptar e E para encriptar\n");
	scanf("%c", &choice);

	printf("Digite o valor da chave\n");
	scanf("%d", &key);

	setbuf(stdin, NULL); // limpa o buffer para poder ler a string com espaços "%[^\n]"

	printf("Digite o texto\n");
	scanf("%[^\n]", text);

	if(choice == 'E' || choice == 'e') {
		//Função que encripta(ou cifra) o texto
		encrypt(text, key);
	} else {
		//decript
		printf("Voce ainda não pode decriptar!\n");
	}

	// Resultado final, encriptado ou decriptado
	printf("%s\n", text);
}