#include <stdio.h>
#include <cmath>
using namespace std;

int main() {
    int test_cases, number, count = 0;
    scanf("%d", &test_cases);
    while(test_cases--) {
        scanf("%d", &number);
        for(int i = 1; i <= number; i++) {
            if(number % i == 0) {
                count++;
            }
            if(count > 2) {
                printf("%d nao eh primo\n", number);
                break;
            }
        }
        if(count == 2) 
            printf("%d eh primo\n", number);
        count = 0;
    }
    return 0;
}
