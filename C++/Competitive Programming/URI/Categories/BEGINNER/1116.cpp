#include <stdio.h>

int main() {
    int N;
    int x,y;
    scanf("%d", &N);
    while(N--) {
        scanf("%d %d", &x, &y);
        if(y == 0)
            printf("divisao impossivel\n");
        else
            printf("%.1lf\n", x * 1.0/ y);
    }
    return 0;
}
