#include <stdio.h>

int main() {
    int T;
    int PA, PB, time = 0, increaseA = 0, increaseB = 0;
    double G1, G2;
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d %lf %lf", &PA, &PB, &G1, &G2);
        G1 /= 100;
        G2 /= 100;
        while(PA <= PB) {
           increaseA = (int) PA * G1;
           increaseB = (int) PB * G2;
           PA += increaseA;
           PB += increaseB;
           time++;
        }
        if(time > 100)
            printf("Mais de 1 seculo.\n");
        else
            printf("%d anos.\n", time);
        time = 0;
        increaseA = 0;
        increaseB = 0;
    }
    return 0;
}
