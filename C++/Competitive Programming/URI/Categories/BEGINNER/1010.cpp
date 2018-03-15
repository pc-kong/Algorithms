#include <stdio.h>

int main() {
	int code, units;
	double price, result;
	int lines = 2;
	while(lines--) {
		scanf("%d %d %lf", &code, &units, &price);
		result += units * price;
	}
	printf("VALOR A PAGAR: R$ %.2lf\n", result);
	return 0;
}	
