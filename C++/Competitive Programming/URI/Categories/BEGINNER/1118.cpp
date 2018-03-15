#include <stdio.h>

int main() {
    int count, input; 
    double grades[2];
    double grade;
    do {
        count = 0;
        while(count < 2) {
            scanf("%lf", &grade);
            if(grade >= 0 && grade <= 10) {
                grades[count] = grade;
                count++;
            }
            else {
                printf("nota invalida\n");
            }
        }
        printf("media = %.2lf\n", (grades[0] + grades[1]) / 2);
        do {
            printf("novo calculo (1-sim 2-nao)\n");
            scanf("%d", &input);
        } while(input != 1 && input != 2);
    } while(input == 1);
    return 0;
}
