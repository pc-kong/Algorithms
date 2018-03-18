#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
    int M, N, sum = 0;
    while(scanf("%d %d", &M, &N) != EOF) {
        if(M <= 0 || N <= 0)
            break;
        if(M > N)
            swap(M, N);
        for(int i = M; i <= N; i++) {
            printf("%d ", i);
            sum += i;
        }
        printf("Sum=%d\n", sum);
        sum = 0;
    }
    return 0;
}
