#include <stdio.h>

int main() {
    int N, number, sum = 0;
    scanf("%d", &N);
    while(N--) {
        scanf("%d", &number);
        for(int i = 1; i < number; i++)
            if(number % i == 0)
                sum += i;
        if(sum != number)
            printf("%d nao eh perfeito\n", number);
        else
            printf("%d eh perfeito\n", number);
        sum = 0;
    }
    return 0;
}
