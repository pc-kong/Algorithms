#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    double A, B, C;
    scanf("%lf %lf %lf", &A, &B, &C);
    if(A < B)
        swap(A, B);
    if(A < C)
        swap(A,C);
    if(B < C)
        swap(B,C);
    if(A >= B + C)
        printf("NAO FORMA TRIANGULO\n");
    else if(pow(A,2) == pow(B,2) + pow(C,2))
        printf("TRIANGULO RETANGULO\n");
    else if(pow(A,2) > pow(B,2) + pow(C,2))
        printf("TRIANGULO OBTUSANGULO\n");
    else if(pow(A,2) < pow(B,2) + pow(C,2))
        printf("TRIANGULO ACUTANGULO\n");
    if(A == B && B == C)
        printf("TRIANGULO EQUILATERO\n");
    else if(A == B || B == C)
        printf("TRIANGULO ISOSCELES\n");
    return 0;
}
