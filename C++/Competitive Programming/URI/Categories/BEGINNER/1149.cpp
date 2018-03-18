#include <stdio.h>

int main() {
    int A, N = 0, i, count = 1;
    int sum = 0;
    scanf("%d", &A);
    while(N <= 0)
        scanf("%d", &N);
    i = A;
    while(count <= N) {
        sum += i;
        i++;
        count++;
    }
    printf("%d\n", sum);
    return 0;
}
