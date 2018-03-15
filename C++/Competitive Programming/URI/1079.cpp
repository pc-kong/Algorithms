#include <stdio.h>

int main() {
    int cases;
    scanf("%d", &cases);
    double a, b, c;
    while(cases--) {
        scanf("%lf %lf %lf", &a, &b, &c);
        printf("%.1lf\n", (a*2 + b*3 + c*5)/10);
    }
    return 0;
}
