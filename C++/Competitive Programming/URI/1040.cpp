#include <stdio.h>

int main() {
    double a,b,c,d;
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    double average = ((a*2) + (b*3) + (c*4) + (d*1)) / 10;
    printf("Media: %.1lf\n", average);
    if(average >= 7)
        printf("Aluno aprovado.\n");
    else if(average < 5)
        printf("Aluno reprovado.\n");
    else if(average >= 5 && average <= 6.9) {
        printf("Aluno em exame.\n");
        double exam_score;
        scanf("%lf", &exam_score);
        printf("Nota do exame: %.1lf\n", exam_score);
        double new_average = (average + exam_score) / 2;
        if(new_average >= 5)
            printf("Aluno aprovado.\n");
        if(new_average <= 4.9)
            printf("Aluno reprovado.\n");
        printf("Media final: %.1lf\n", new_average);
    }
    return 0;
}
