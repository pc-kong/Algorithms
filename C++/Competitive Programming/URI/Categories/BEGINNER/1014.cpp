#include <stdio.h>

int main() {
    int distance;
    double spent_f;
    scanf("%d %lf", &distance, &spent_f);
    printf("%.3lf km/l\n", distance / spent_f);
    return 0;
}   
