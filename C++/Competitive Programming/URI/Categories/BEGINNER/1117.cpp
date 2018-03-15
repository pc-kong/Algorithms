#include <stdio.h>

int main() {
    int count_valids = 0;
    double first_score, second_score, sum_valids = 0.0;
    while(1) {
        if(count_valids == 2) {
            printf("media = %.2lf\n", sum_valids / 2);
            break;
        }
        scanf("%lf %lf", &first_score, &second_score);
        if(first_score < 0 || first_score > 10)
            printf("nota invalida\n");
        else {
            count_valids++;
            sum_valids += first_score;
        }
        if(second_score < 0 || second_score > 10)
            printf("nota invalida\n");
        else {
            count_valids++;
            sum_valids += second_score;
        }

    }
    return 0;
}
