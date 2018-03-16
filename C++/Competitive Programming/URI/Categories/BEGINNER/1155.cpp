#include <stdio.h>

int main() {
    double S = 0.0;
    double denominator = 1.0;
    while(denominator <= 100) {
        S += (1 / denominator);
        denominator++;
    }
    printf("%.2lf\n", S);
    return 0;
}
