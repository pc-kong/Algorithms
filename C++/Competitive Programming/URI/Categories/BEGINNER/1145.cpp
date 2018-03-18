#include <stdio.h>

int main() {
    int nums_per_line, top;
    scanf("%d %d", &nums_per_line, &top);
    for(int i = 1; i <= top;) {
        for(int j = 0; j < nums_per_line; j++) {
            if(j == nums_per_line - 1)
                printf("%d\n", i++);
            else
                printf("%d ", i++);
        }
    }
    return 0;
}
