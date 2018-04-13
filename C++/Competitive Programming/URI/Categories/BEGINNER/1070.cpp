#include <stdio.h>

int main() {
    int number, count = 0;
    scanf("%d", &number);
    int done;
    for(int i = number; count < 6; i++) {
        if(i & 1) {
            printf("%d\n", i);
            count++;
        }
    }
    return 0;
}
