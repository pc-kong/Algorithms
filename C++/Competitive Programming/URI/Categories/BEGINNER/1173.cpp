#include <stdio.h>

int main() {
    int input;
    int array[10];
    scanf("%d", &input);
    for(int i = 0; i < 10; i++) {
        array[i] = input;
        printf("N[%i] = %d\n", i, input);
        input *= 2;
    }
    return 0;
}
