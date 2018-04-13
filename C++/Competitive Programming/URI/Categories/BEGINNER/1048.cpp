#include <stdio.h>

int main() {
    double salary;
    double increase_porcentual;
    double increase;
    scanf("%lf", &salary);
    if(salary >= 0 && salary <= 400.00)
        increase_porcentual = .15;
    else if(salary >= 400.01 && salary <= 800.00)
        increase_porcentual = .12;
    else if(salary >= 800.01 && salary <= 1200.00)
        increase_porcentual = .10;
    else if(salary >= 1200.01 && salary <= 2000.00)
        increase_porcentual = .07;
    else if(salary > 2000)
        increase_porcentual = .04;
    increase = salary * increase_porcentual;
    printf("Novo salario: %.2lf\n", salary + increase);
    printf("Reajuste ganho: %.2lf\n", increase);
    printf("Em percentual: %.0lf %%\n", increase_porcentual * 100);
    return 0;
}
