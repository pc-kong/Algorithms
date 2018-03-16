#include <stdio.h>

int main() {
    int age, sum = 0, count = 0;
    while(1) {
        scanf("%d", &age);
        if(age < 0) break;
        sum += age;
        count++;
    }
    printf("%.2lf\n", sum * 1.0 / count);
    return 0;
}
