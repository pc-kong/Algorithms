#include <stdio.h>

int main() {
    double consumption = 12;          //km/L.
    double hours, avg_speed;
    scanf("%lf %lf", &hours, &avg_speed);
    printf("%.3lf\n", hours * avg_speed / consumption);
    return 0;
}
