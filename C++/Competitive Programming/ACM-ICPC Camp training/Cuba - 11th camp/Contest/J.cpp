#include <bits/stdc++.h>

using namespace std;

int actual = 0;
int total_a, total_b, total_c; 

void res_0_c(int divc) {
	int saltos = divc*3;
	int vuelta = 0;
	bool regreso = false;
	while(true) {
		if(vuelta < divc && !regreso) {
			printf("%d ", actual);
			actual += 3;
			vuelta++;
			total_c--;
			saltos--;
			if(!saltos) {
				printf("%d ", actual);
				break;
			}
		} 
		if (vuelta == divc) {
			printf("%d ", actual);
			actual++;
			total_a--;
			regreso = true;
		} 
		if (regreso && vuelta > 0) {
			printf("%d ", actual);
			actual -= 3;
			vuelta--;
			saltos--;
			total_c--;
		}	
		if(vuelta == 0) {
			printf("%d ", actual);
			actual++;
			total_a--;
			regreso = false;
		}
	}
}

void res_1_c() {
	actual += 3;
	total_c--; 
	printf("%d ", actual);
	actual -= 2;
	total_b--;
	printf("%d ", actual);
	actual++;
	total_a--;
	printf("%d ", actual);
	actual += 2;
	total_b--;
	printf("%d ", actual);
} 

void res_2_c() {
	actual += 3;
	total_c--;
	printf("%d ", actual);
	actual--;
	total_a--;
	printf("%d ", actual);
	actual--;
	total_a--;
	printf("%d ", actual);
	actual += 3;
	total_c--;
	printf("%d ", actual);
}

void res_0_b(int divb) {
	int saltos = 0;
	while(saltos < divb) {
		actual+=2;
		total_b--;
		printf("%d ", actual);
		saltos++;
	}
	actual++;
	total_a--;
	if(total_b == 0) { 
		printf("%d\n", actual);
	}
	else printf("%d ", actual);
	while(saltos > 1) {
		actual-=2;
		total_b--;
		printf("%d ", actual);
		saltos--;
	}
	actual-=2;
	total_b--;
	printf("%d\n", actual);
	saltos--;
}

void res_1_b(int divb) {
	int saltos = 0;
	while(saltos < divb) {
		actual+=2;
		total_b--;
		printf("%d ", actual);
		saltos++;
	}
	actual+=2;
	total_b--;
	printf("%d ", actual);
	actual--;
	total_a--;
	if(total_b == 0) { 
		printf("%d\n", actual);
	}	
	else printf("%d ", actual);
	while(saltos > 1) {
		actual-=2;
		total_b--;
		printf("%d ", actual);
		saltos--;
	}
	if(total_b > 0) {
		actual-=2;
		total_b--;
		printf("%d\n", actual);
		saltos--;
	}

}

int main(int argc, char const *argv[])
{
	freopen("jumping.in", "r", stdin);
	freopen("jumping.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while(T--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		int max = a+b+c;
		total_a = a;
		total_b = b;
		total_c = c;
		int modc = c%3;
		res_0_c(c/3);
		if(modc == 1)
			res_1_c();
		if(modc == 2)
			res_2_c();
		while(total_a > 1) {
			actual++;
			total_a--;
			printf("%d ", actual);
		}	
		int divb = total_b%2;
		if(divb == 0) 
			res_0_b(total_b/2);
		if(divb == 1)
			res_1_b(total_b/2);
		total_a = 0;
		total_b = 0;
		total_c = 0;
		actual = 0;
	}
	return 0;
}