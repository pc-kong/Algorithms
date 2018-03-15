#include <stdio.h>

int main() {
    int number;
    int evens = 0, odds = 0, positives = 0, negatives = 0;
    for(int i = 0; i < 5; i++) {
        scanf("%d", &number);
        if(number > 0)
            positives++;
        if(number < 0)
            negatives++;
        if(number % 2 == 0)
            evens++;
        else   
            odds++;
    }
    printf("%d valor(es) par(es)\n%d valor(es) impar(es)\n%d valor(es) positivo(s)\n%d valor(es) negativo(s)\n", evens, odds, positives, negatives);
    return 0;
}
