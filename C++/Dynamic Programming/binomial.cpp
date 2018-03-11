#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

long long coeficientes[100][100];

string getVar(int x, int y) {
	if(x == 0)
		return "y^" + to_string(y);
	if(y == 0)
		return "x^" + to_string(x);
	if(x == 1 && y == 1)
		return "xy";
	if(x == 1)
		return "xy^" + to_string(y);
	if(y == 1)
		return "x^"+to_string(x)+"y";
	return "x^"+to_string(x)+"y^"+to_string(y);
}
 /*
int askCoef(int n, int k){
	if(k==0){
		coeficientes[n][k] = 1;
		return coeficientes[n][k];
	}
	if(k==n){
		coeficientes[n][n] = 1;
		return coeficientes[n][n];
	}
	coeficientes[n][k] = askCoef(n-1,k-1) + askCoef(n-1,k);
	return coeficientes[n][k];
} */

string getCoef(int n, int k){
	//if(coeficientes[n][k] != 0){
		if(coeficientes[n][k] == 1)
			return "";
		return to_string(coeficientes[n][k]);
	//}
	/*
	int c = askCoef(n,k);
	if(c == 1){
		return "";
	}
	return to_string(c);*/
}



int main() {
	int n, inp;
	scanf("%d", &inp);
	coeficientes[0][0] = 1;
	coeficientes[1][0] = 1;
	coeficientes[1][1] = 1;
	for (int i = 2; i < 100; i++) {
		coeficientes[i][i] = 1;
		coeficientes[i][0] = 1;
		for (int j = 1; j < i; j++) {
			coeficientes[i][j] = coeficientes[i-1][j-1] + coeficientes[i-1][j];
		}
	}
	while(inp--) {
		scanf("%d", &n);
		if(n == 0)
			printf("1\n");
		else if(n==1)
			printf("x+y\n");
		else {
			string str = "";
			int y = 0;
			int k = 0;
			int consti = n;
			while(n>=0) {
				str += getCoef(consti,k) + getVar(n,y);
				if(n > 0) str += "+";
				k++;
				y++;
				n--;
			}
			printf("%s\n", str.c_str());
		}
	}
	return 0;
}