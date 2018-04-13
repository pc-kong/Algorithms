#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
    int a, b;
    int sum_odds = 0;
    scanf("%d %d", &a, &b);
    if(a > b)
        swap(a,b);
    for(int i = a; i < b; i++)
        if(i % 2 != 0)
            sum_odds += i;
        if(a % 2 != 0)
            sum_odds -= a;
    printf("%d\n", sum_odds);
    return 0;
}
