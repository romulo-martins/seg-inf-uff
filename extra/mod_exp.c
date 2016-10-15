#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int mod_exp(int g, int a, int n) {
  int result, pot;

  pot = g % n;
  result = 1;

  for( ; a > 0; a /= 2) {
    if (a % 2 == 1)  /* O bit menos significativo e 1 */
      result = (result * pot) % n;

    pot = (pot * pot) % n;
  }
  return result;
}


int main() {
	int g, a, n;
	printf("Informe g, a, n: \n");
	scanf("%d %d %d", &g, &a, &n);

	int k = mod_exp(g, a, n);

	printf("(%d^%d)mod(%d) = %d\n", g, a, n, k);

}