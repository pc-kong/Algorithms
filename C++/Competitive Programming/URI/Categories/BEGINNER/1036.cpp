#include <stdio.h>
#include <cmath>
using namespace std;

double discriminant(double a, double b, double c) {
    return pow(b, 2) - (4 * a * c);
}

int main() {
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    double divisor = 2 * a;
    double disc = discriminant(a, b, c);
    if(divisor == 0 || disc < 0) {
        printf("Impossivel calcular\n");
    }
    else {
        disc = sqrt(disc);
        double first_root = ((-1 * b) + disc) / divisor;
        double second_root = ((-1 * b) - disc) / divisor;
        printf("R1 = %.5lf\n", first_root);
        printf("R2 = %.5lf\n", second_root);
    }
    return 0;
}
