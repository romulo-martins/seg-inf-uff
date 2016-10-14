#include <stdio.h>
#include <stdlib.h>

int mod(int a, int b) {
    if(a >= 0) {
        return a % b;
    }
    else {
        return a + b*((b - a - 1)/b);
    }
}

int main() {

	int m, i, j;
	 printf("Informe um numero m: \n");
	 scanf("%d", &m);

	 printf("Tabela de adicao: \n");
	 for(i = 0; i < m; i++) {
	 	for (j = 0; j < m; j++) {
	 		printf(" %d ", mod(i + j, m));
	 	}
	 	printf("\n");
	 }

	 printf("Tabela de multiplicacao: \n");
	 for(i = 0; i < m; i++) {
	 	for (j = 0; j < m; j++) {
	 		printf(" %d ", mod(i*j, m));	
	 	}
	 	printf("\n");
	 }
}