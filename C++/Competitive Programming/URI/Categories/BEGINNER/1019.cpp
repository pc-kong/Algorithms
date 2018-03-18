#include <stdio.h>

int main() {
    int hours, minutes, seconds;
    int input;
    scanf("%d", &input);
    hours = input / 3600;
    input %= 3600;
    minutes = input / 60;
    input %= 60;
    seconds = input;
    printf("%d:%d:%d\n", hours, minutes, seconds);
    return 0;
}
