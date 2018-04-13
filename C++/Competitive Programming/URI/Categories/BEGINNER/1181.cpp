#include <stdio.h>

int main() {
    int line;
    char operation;
    double sum = 0.0;
    double M[12][12];
    scanf("%d", &line);
    scanf(" %c", &operation);
    for(int i = 0; i < 12; i++) {    
        for(int j = 0; j < 12; j++) {
            scanf("%lf", &M[i][j]);
        }
    }
    for(int j = 0; j < 12; j++)
        sum += M[line][j];
    if(operation == 'S')
        printf("%.1lf\n", sum);
    else
        printf("%.1lf\n", sum / 12);
    return 0;
}
