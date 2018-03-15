#include <stdio.h>

int main() {
	float a, b;
	float weight_1 = 3.5;
	float weight_2 = 7.5;
	float weight_total = weight_1 + weight_2;
	scanf("%f", &a);
	scanf("%f", &b);
	printf("MEDIA = %.5f\n", (a * weight_1 + b * weight_2) / weight_total);
	return 0;
}
