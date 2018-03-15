#include <stdio.h>

int main() {
	int emp_number, worked_hours;
	float salary_per_h;
	scanf("%d", &emp_number);
	scanf("%d", &worked_hours);
	scanf("%f", &salary_per_h);
	printf("NUMBER = %d\n", emp_number);
	printf("SALARY = U$ %.2f\n", worked_hours * salary_per_h);
	return 0;
}
