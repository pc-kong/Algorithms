#include <stdio.h>

long long unsigned int fibo_memo[61];

void fill_fibo_memo() {
    fibo_memo[0] = 0;
    fibo_memo[1] = 1;
    for(int i = 2; i <= 60; i++)
        fibo_memo[i] = fibo_memo[i - 1] + fibo_memo[i - 2];
}

int main() {
    int test_cases, input;
    int ans = 0;
    fill_fibo_memo();
    scanf("%d", &test_cases);
    while(test_cases--) {
        scanf("%d", &input);
        printf("Fib(%d) = %llu\n", input, fibo_memo[input]);
    }
    return 0;
}
