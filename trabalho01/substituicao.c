#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_LENGHT 100
#define MAX_STRING_LENGHT 1000

#define TRUE 1
#define FALSE 0

#define ALPHABET "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define N 26

// Pega indice em relação ao afabeto
int get_char_index(char c) {
	int i;
	for(i = 0; i < N; i++) {
		if(ALPHABET[i] == c) {
			return i;
		}
	}
	return -1;
}

// Ler linha dados do teclado até receber o caractere #
char* read_text(){
	char* text = (char*)malloc(MAX_STRING_LENGHT * sizeof(char));
	char* text_aux = (char*)malloc(STRING_LENGHT * sizeof(char));
	int exit = FALSE;

	printf("Digite o texto\n");
	do {
		setbuf(stdin, NULL);
		scanf("%[^\n]s", text_aux);
		if(strstr(text_aux, "#") != NULL) {
			exit = TRUE;
		}
		strcat(text, "\n");
		strcat(text, text_aux);
	} while(!exit);	

	free(text_aux);

	return text;
}

// Condição para verificar se 
int choice_condition(char choice) {
	return choice == 'E' || choice == 'e' || choice == 'D' || choice == 'd';
}

char read_choice() {
	char choice;
	do {
		printf("Digite D para decriptar e E para encriptar: \n");
		scanf("%c", &choice);
		if(!choice_condition(choice)) {
			printf(" -> Opcao invalida! Voce deve informar E ou D!\n");
			setbuf(stdin, NULL);
		}
	} while(!choice_condition(choice));

	return choice;
}

// Le a chave
int read_key() {
	int key;
	do {
		printf("Digite o valor da chave: \n");
		scanf("%d", &key);
		if(key < 0) {
			printf(" -> Opcao Invalida! Informe um numero positivo!\n");
			setbuf(stdin, NULL);
		}
	} while(key < 0);

	return key;
}

// Algoritmo para encriptar o texto
void encrypt(char* text, int key) {
	int i;
	for(i = 0; text[i] != '\0'; i++) {
		int index = get_char_index(text[i]);
		if(index != -1) {
			int index_sub = (index + key) % N;
			text[i] = ALPHABET[index_sub];
			key = index_sub + key + 1;			
		}							
	}
}

// Algoritmo para desencriptar o texto
void decrypting(char* text, int key) {
	int i;
	for(i = 0; text[i] != '\0'; i++) {
		int index = get_char_index(text[i]);
		if(index != -1) {
			int index_sub = (index - key) % N;
			text[i] = ALPHABET[index_sub];
			key = index + key + 1;			
		}							
	}
}

int main() {
	int i;
	
	char choice = read_choice();
	int key = read_key();
	char* text = read_text();

	if(choice == 'E' || choice == 'e') {
		//Função que encripta(ou cifra) o texto
		encrypt(text, key);
	} else {
		//decript
		decrypting(text, key);
	}

	// Resultado final, encriptado ou decriptado
	printf("%s\n", text);

	free(text);
}