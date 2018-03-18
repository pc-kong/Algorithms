#include <stdio.h>

int main() {
    double number;
    for(int i = 0; i < 100; i++) {
        scanf("%lf", &number);
        if(number <= 10)
            printf("A[%d] = %.1lf\n", i, number);
    }
}
