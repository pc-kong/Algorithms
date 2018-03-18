#include <stdio.h>

int main() {
    int X, Z = 0;
    int how_many = 0, sum = 0;
    scanf("%d", &X);
    while(Z <= X) scanf("%d", &Z);
    int i = X;
    while(sum <= Z) {
        sum += i;
        i++;
        how_many++;
    }
    printf("%d\n", how_many);
    return 0;
}
