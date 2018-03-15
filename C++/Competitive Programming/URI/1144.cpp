#include <stdio.h>

int main() {
    int N, i = 1;
    scanf("%d", &N);
    while(N--) {
        printf("%d %d %d\n", i, i * i, i * i * i);
        printf("%d %d %d\n", i, i * i + 1, i * i * i + 1);
        i++;
    }
    return 0;
}
