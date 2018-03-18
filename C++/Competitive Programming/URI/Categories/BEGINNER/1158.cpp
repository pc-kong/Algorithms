#include <stdio.h>

int main() {
    int N;
    int X, Y, sum = 0, i;
    scanf("%d", &N);
    while(N--) {
       scanf("%d %d", &X, &Y);
       i = X;
       while(Y) {
           if(i % 2 != 0) {
               Y--;
               sum += i;
           }
           i++;
       }
       printf("%d\n", sum);
       sum = 0;
    }
    return 0;
}
