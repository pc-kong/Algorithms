#include <stdio.h>

int main() {
    int input;
    int years, months, days;
    scanf("%d", &input);
    years = input / 365;
    input = input % 365;
    months = input / 30;
    days = input % 30;
    printf("%d ano(s)\n%d mes(es)\n%d dia(s)\n", years, months, days);
    return 0;
}
