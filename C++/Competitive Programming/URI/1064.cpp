#include <stdio.h>

int main() {
    int count = 0;
    float sum_positives, current_num = 0;
    for(int i = 0; i < 6; i++) {
        scanf("%f", &current_num);
        if(current_num > 0) {
            sum_positives += current_num;
            count++;
        }
    }
    printf("%d valores positivos\n%.1f\n", count, sum_positives/count);
    return 0;
}
