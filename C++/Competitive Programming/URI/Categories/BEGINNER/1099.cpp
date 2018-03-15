#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
    int N, X, Y, sum = 0;
    scanf("%d", &N);
    while(N--) {
        scanf("%d %d", &X, &Y);
        if(X > Y)
            swap(X, Y);
        for(int i = X + 1; i < Y; i++) {
            if(i % 2 != 0)
                sum += i;
        }
        printf("%d\n", sum);
        sum = 0;
    }
    return 0;
}
