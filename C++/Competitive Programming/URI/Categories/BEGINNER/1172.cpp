#include <stdio.h>

int main() {
    int array[10];
    for(int i = 0; i < 10; i++)
        scanf("%d", &array[i]);
    for(int i = 0; i < 10; i++) {
        if(array[i] <= 0)
            array[i] = 1;
        printf("X[%d] = %d\n", i, array[i]);
    }
    return 0;
}
