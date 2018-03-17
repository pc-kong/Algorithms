#include <stdio.h>

int main() {
    int X, sum = 0, count = 0, i;
    while(1) {
        scanf("%d", &X);
        if(X == 0)
            break;
        i = X;
        while(count != 5) {
            if(i % 2 == 0) {
                sum += i;
                count++;
            }
            i++;
        }
        printf("%d\n", sum);
        sum = 0;
        count = 0;
    }
    return 0;
}
