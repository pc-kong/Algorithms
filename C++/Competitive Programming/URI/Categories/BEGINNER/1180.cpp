#include <stdio.h>

int main() {
    int number_elements;
    scanf("%d", &number_elements);
    int X[number_elements];
    for(int i = 0; i < number_elements; i++)
        scanf("%d", &X[i]);
    int minimum = X[0], index_minimum = 0;
    for(int i = 1; i < number_elements; i++)
        if(X[i] < minimum) {
            minimum = X[i];
            index_minimum = i;
        }
    printf("Menor valor: %d\nPosicao: %d\n", minimum, index_minimum);
    return 0;
}
