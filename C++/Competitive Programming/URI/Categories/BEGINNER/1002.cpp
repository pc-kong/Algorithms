#include <stdio.h>
#include <cmath>
using namespace std;

int main() {
	double PI = 3.14159;
	double radius, area;
	scanf("%lf", &radius);
	area = PI * pow(radius, 2);
	printf("%s%.4lf\n", "A=", area);
	return 0;
}	
