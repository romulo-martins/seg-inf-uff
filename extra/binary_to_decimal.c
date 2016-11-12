#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long binary_to_decimal(int* bits, int bits_length) {
	int i;
	long long decimal_value = 0;
	for(i = 0; i < bits_length; i++) {
		int exponent = bits_length - i - 1;
		decimal_value += bits[i]*pow(2, exponent);
	}
	return decimal_value;
}

int main() {
	int n = 5;

	int bits[5] = {0, 1, 1, 0, 1}; 

	printf("Resultado final = %lli\n", binary_to_decimal(bits, n));

}



