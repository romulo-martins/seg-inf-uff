#include <stdio.h>
#include <stdlib.h>

int mdc(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	int m, r = 0;
	int i;

	scanf("%d", &m);

	for(i = 1; r < m-1; i++) {
		r = i % m;
		if(mdc(r, m) == 1) {
			printf(" %d ", r);
		}
	}
}