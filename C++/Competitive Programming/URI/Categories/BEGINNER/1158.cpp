#include <stdio.h>

int main() {
    int N;
    int X, Y, sum = 0, count = 0;
    scanf("%d", &N);
    while(N--) {
        scanf("%d %d", &X, &Y);
        while(count != Y) {
            if(X % 2 != 0) {
                sum += X;
                count++;
            }
            X++;
        }
        printf("%d\n", sum);
        sum = 0;
        count = 0;
    }
    return 0;
}
