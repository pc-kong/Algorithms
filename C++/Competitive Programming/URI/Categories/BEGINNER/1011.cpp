#include <stdio.h>

int main() {
    double radius;
    double PI = 3.14159;
    scanf("%lf", &radius);
    printf("VOLUME = %.3lf\n", (4.0/3) * PI * radius * radius * radius);
    return 0;
}
