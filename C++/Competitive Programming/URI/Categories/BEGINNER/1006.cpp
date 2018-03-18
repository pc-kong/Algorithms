#include <stdio.h>

int main() {
	float a, b, c;
	float weight_1 = 2;
	float weight_2 = 3;
	float weight_3 = 5;
	float weight_total = weight_1 + weight_2 + weight_3;
	scanf("%f", &a);
	scanf("%f", &b);
	scanf("%f", &c);
	float average = ((a * weight_1) + (b * weight_2) + (c * weight_3)) / weight_total;
	printf("MEDIA = %.1f\n", average);
	return 0;
}	
