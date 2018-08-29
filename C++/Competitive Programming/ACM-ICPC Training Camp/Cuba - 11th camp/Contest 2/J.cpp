#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

string ans = "";

void convierte(int n) {
	int residuo = n%3;
	if(n < 3) {
		if(n == 0) {
			ans = "0" + ans;
			return;
		}
		if(n == 1) {
			ans = "+" + ans;
			return;
		}
		if(n == 2) {
			ans = "+-" + ans;
			return;
		}
	}
	if(residuo == 0){
		ans = "0" + ans;
		convierte(n/3);
	}
	if(residuo == 1) {
		ans = "+" + ans; 
		convierte(n/3);
	}
	if(residuo == 2) {
		ans = "-" + ans;
		convierte((n/3)+1); 
	}
}

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		convierte(n);
		cout << ans << endl;
		ans = "";
	}
	return 0;
}