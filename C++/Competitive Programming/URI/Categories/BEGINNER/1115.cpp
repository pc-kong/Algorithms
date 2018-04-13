#include <stdio.h>

int main() {
    int x, y;
    while(scanf("%d %d", &x, &y) != EOF) {
        if(x == 0 || y == 0) break;
        if(x > 0 && y > 0) printf("primeiro\n");
        if(x < 0 && y > 0) printf("segundo\n");
        if(x < 0 && y < 0) printf("terceiro\n");
        if(x > 0 && y < 0) printf("quarto\n"); 
    }
    return 0;
}
