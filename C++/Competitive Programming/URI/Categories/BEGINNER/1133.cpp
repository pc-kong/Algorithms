#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
    int X, Y;
    scanf("%d %d", &X, &Y);
    if(X > Y)
        swap(X, Y);
    for(int i = X+1; i < Y; i++)
        if(i % 5 == 2 || i % 5 == 3)
            printf("%d\n", i);
    return 0;
}
