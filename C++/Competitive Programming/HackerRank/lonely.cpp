#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	vector<int> numeros;
	scanf("%d", &n);
	while(n--){
		int numero;
		scanf("%d", &numero);
		numeros.push_back(numero);
	}
	int respuesta;
	for (int i = 0; i < count; ++i)
	{
		respuesta ^= numeros[i];
	}
	cout << respuesta << "\n"
	return 0;
}