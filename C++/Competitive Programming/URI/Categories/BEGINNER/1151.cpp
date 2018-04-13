#include <stdio.h>

int easy_fibo(int N) {
    if(N == 1) return 0;
    else if(N == 2) return 1;
    return easy_fibo(N - 1) + easy_fibo(N - 2);
}

int main() {
    int N;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
        if(i != N)
            printf("%d ", easy_fibo(i));
        else
            printf("%d\n", easy_fibo(i));
    return 0;
}
