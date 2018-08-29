#include <bits/stdc++.h>
using namespace std;

vector<int> candidatos;

int palindromo(string s) {
	string pal = "";
	pal = s + s[2] + s[1] +s[0];
	return stoi(pal);
}

int busca(string s) {
	int numero = stoi(s);
	string aux = "";
	aux += s[0];
	aux += s[1];
	aux += s[2];
	int min = palindromo(aux);
	for(int c: candidatos) {
		if(abs(c-numero) < abs(min-numero))
			min = c;
	}
	vector<int> empate;
	empate.push_back(min);
	for(int c: candidatos) {
		if(abs(c-numero) == abs(min-numero))
			empate.push_back(c);
	}
	sort(empate.begin(), empate.end());
	
	return empate[0];
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i=0; i<10; i++) {
		for(int j=0; j<10; j++) {
			for(int k=0; k<10; k++) {
				int actual = palindromo(to_string(i)+to_string(j)+to_string(k));
				candidatos.push_back(actual);
			}
		}
	}
	while(n--) {
		string s;
		cin >> s;
		int res = busca(s);
		printf("%d\n", res);		
	}
}