#include <stdio.h>

int main() {
    for(int i = 1; i <= 100; i++)
        if(i & 1) continue;
        else printf("%d\n", i);
    return 0;
}
