#include <stdio.h>

int main() {
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    double area_rectangled_triangle = a * c / 2;
    double area_circle = 3.14159 * c * c;
    double area_trapezium = c * ((a + b) / 2); 
    double area_square = b * b;
    double area_rectangle = a * b;
    printf("TRIANGULO: %.3lf\n", area_rectangled_triangle);
    printf("CIRCULO: %.3lf\n", area_circle);
    printf("TRAPEZIO: %.3lf\n", area_trapezium);
    printf("QUADRADO: %.3lf\n", area_square);
    printf("RETANGULO: %.3lf\n", area_rectangle);
    return 0;
}
