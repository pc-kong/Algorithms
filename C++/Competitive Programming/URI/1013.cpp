#include <stdio.h>
#include <stdlib.h>

int maior(int a, int b) {
    return (a + b + abs(a - b)) / 2;
}

int main() {
    int a, b, c;
    int max;
    scanf("%d %d %d", &a, &b, &c);
    max = maior(a, b);
    max = maior(max, c);
    printf("%d eh o maior\n", max);
    return 0;
}
