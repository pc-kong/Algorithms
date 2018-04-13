#include <stdio.h>

int main() {
    int X;
    do {
        scanf("%d", &X);
        for(int i = 1; i <= X; i++)
            if(i != X)
                printf("%d ", i);
            else
                printf("%d\n", i);
    } while(X != 0);
    return 0;
}
