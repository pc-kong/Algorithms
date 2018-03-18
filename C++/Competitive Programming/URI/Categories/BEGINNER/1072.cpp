#include <stdio.h>

int main() {
    int N, number_cases = 0;
    int number;
    int in_interval = 0;
    scanf("%d", &N);
    number_cases = N;
    while(N--) {
        scanf("%d", &number);
        if(number >= 10 && number <= 20)
            in_interval++;
    }
    printf("%d in\n%d out\n", in_interval, number_cases - in_interval);
    return 0;
}
