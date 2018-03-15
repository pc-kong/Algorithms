#include <stdio.h>

int main() {
    int N;
    int rabbits = 0, rats = 0, frogs = 0, quantity;
    char type;
    scanf("%d", &N);
    while(N--) {
        scanf("%d %c", &quantity, &type);
        if(type == 'C') rabbits += quantity;
        else if(type == 'R') rats += quantity;
        else frogs += quantity;
    }
    int total = rabbits + rats + frogs;
    printf("Total: %d cobaias\n", total);
    printf("Total de coelhos: %d\n", rabbits);
    printf("Total de ratos: %d\n", rats);
    printf("Total de sapos: %d\n", frogs);
    printf("Percentual de coelhos: %.2lf %%\n", (rabbits * 100.00) / total);
    printf("Percentual de ratos: %.2lf %%\n", (rats * 100.00) / total );
    printf("Percentual de sapos: %.2lf %%\n", (frogs * 100.00) / total);
    return 0;
}
