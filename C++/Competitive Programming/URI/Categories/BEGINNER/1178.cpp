#include <stdio.h>

int main() {
    double X;
    scanf("%lf", &X);
    double N[100];
    for(int i = 0; i < 100; i++) {
        N[i] = X;
        X /= 2;
    }
    for(int i = 0; i < 100; i++)
        printf("N[%d] = %.4lf\n", i, N[i]);
    return 0;
}
