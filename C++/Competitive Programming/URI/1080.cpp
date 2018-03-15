#include <stdio.h>

int main() {
    int current;
    int max = 0, max_index = 0;
    for(int i = 1; i <= 100; i++) {
        scanf("%d", &current);
        if(current > max) {
            max = current;
            max_index = i;
        }
    }
    printf("%d\n%d\n", max, max_index);
    return 0;
}
