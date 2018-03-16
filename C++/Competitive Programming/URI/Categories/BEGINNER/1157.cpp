#include <stdio.h>

int main() {
    int N, current = 1;
    scanf("%d", &N);
    while(current <= N) {
        if(N % current == 0)
            printf("%d\n", current);
        current++;
    }
    return 0;
}
