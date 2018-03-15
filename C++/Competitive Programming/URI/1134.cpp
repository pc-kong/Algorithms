#include <stdio.h>

int main() {
    int a = 0, b = 0, c = 0;
    int input;
    while(scanf("%d", &input) != EOF) {
        if(input >= 0 && input <= 4) {
            if(input == 4) break;
            if(input == 1) a++;
            if(input == 2) b++;
            if(input == 3) c++;
        }
    }
    printf("MUITO OBRIGADO\n");
    printf("Alcool: %d\nGasolina: %d\nDiesel: %d\n", a, b, c);
    return 0;
}
