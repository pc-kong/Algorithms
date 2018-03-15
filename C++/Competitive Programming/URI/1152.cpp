#include <stdio.h>

int main() {
    int num_lines, max_line = 1;
    scanf("%d", &num_lines);
    while(num_lines--) {
        printf("%d %d %d PUM\n", max_line, max_line + 1, max_line + 2);
        max_line += 4;
    }
    return 0;
}
