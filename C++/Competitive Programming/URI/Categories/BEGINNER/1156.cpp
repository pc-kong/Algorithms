#include <stdio.h>

int main() {
    double S = 0;
    double numerator = 1, denominator = 1;
    while(numerator <= 39) {
        S += numerator / denominator;
        numerator += 2;
        denominator *= 2;
    }
    printf("%.2lf\n", S);
    return 0;
}
