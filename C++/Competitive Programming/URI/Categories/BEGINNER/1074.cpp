#include <stdio.h>

int main() {
    int N, read_val;
    scanf("%d", &N);
    while(N--){
        scanf("%d", &read_val);
        if(read_val == 0)
            printf("NULL\n");
        else {
            if(read_val % 2 == 0) 
                printf("EVEN ");
            else
                printf("ODD ");
            if(read_val > 0)
                printf("POSITIVE\n");
            else
                printf("NEGATIVE\n");
        }
    }
    return 0;
}
