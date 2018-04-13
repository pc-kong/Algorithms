#include <stdio.h>

int main() {
    int num_lines, i = 1;
    scanf("%d", &num_lines);
    while(num_lines--) {
        printf("%d %d %d\n", i, i * i, i * i * i);
        i++;
    }
    return 0;
}
