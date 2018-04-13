#include <stdio.h>

void invert_two_array(int array[], int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

int main() {
    int array[20];
    int begin = 0, end = 19;
    for(int i = 0; i < 20; i++)
        scanf("%d", &array[i]);
    for(int i = 0; i < 10; i++)
        invert_two_array(array, begin++, end--);
    for(int i = 0; i < 20; i++)
        printf("N[%d] = %d\n", i, array[i]);
    return 0;
}
