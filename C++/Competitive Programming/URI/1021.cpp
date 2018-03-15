#include <stdio.h>

int main() {
    double input;
    scanf("%lf", &input);
    int notes = input;
    int coins = input * 100;

    printf("NOTAS:\n");
    printf("%d nota(s) de R$ 100.00\n", notes/100);
    notes %= 100;
    printf("%d nota(s) de R$ 50.00\n", notes/50);
    notes %= 50;
    printf("%d nota(s) de R$ 20.00\n", notes/20);
    notes %= 20;
    printf("%d nota(s) de R$ 10.00\n", notes/10);
    notes %= 10;
    printf("%d nota(s) de R$ 5.00\n", notes/5);
    notes %= 5;
    printf("%d nota(s) de R$ 2.00\n", notes/2);
    notes %= 2;
    
    printf("MOEDAS:\n");
    coins = (int) coins;
    printf("%d moeda(s) de R$ 1.00\n", notes);
    coins %= 100;
    printf("%d moeda(s) de R$ 0.50\n", coins/50);
    coins %= 50;
    printf("%d moeda(s) de R$ 0.25\n", coins/25);
    coins %= 25;
    printf("%d moeda(s) de R$ 0.10\n", coins/10);
    coins %= 10;
    printf("%d moeda(s) de R$ 0.05\n", coins/5);
    coins %= 5;
    printf("%d moeda(s) de R$ 0.01\n", coins/1);
    return 0;
}
