#include <stdio.h>

int main() {
    double salary, ans;
    scanf("%lf", &salary);
    if(salary <= 2000) 
        printf("Isento\n");
    else {
        if(salary > 3000) {
            salary -= 2000;
            salary -= 1000;
            ans = 1000 * .08;
            if(salary > 1500) {
                salary -= 1500;
                ans += 1500 * .18;
                if(salary > 0) {
                    ans += salary * .28;
                }
            }
            else {
                ans += salary * .18;
            }
        }
        else {
            ans = (salary - 2000) * .08;
        }
        printf("R$ %.2lf\n", ans);
    }
    return 0;
}
