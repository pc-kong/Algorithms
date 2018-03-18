#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main() {
	string name;
	double fixed_salary, sales_total, sales_worker;
	cin >> name;
	scanf("%lf", &fixed_salary);
	scanf("%lf", &sales_total);
	sales_worker = sales_total * 0.15;
		printf("TOTAL = R$ %.2lf\n", fixed_salary + sales_worker);	
	return 0;
}
