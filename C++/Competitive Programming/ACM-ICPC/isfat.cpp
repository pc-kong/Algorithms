#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int c;
	scanf("%d", &c);
	while(c--) {
		int i;
		scanf("%d", &i);
		vector<int> coeficientes;
		i++;
		while(i--) {
			int coef;
			scanf("%d", &coef);
			coeficientes.push_back(coef);
		}
		int d, k;
		scanf("%d %d", &d, &k);
		long long posicion = 0;
		for(int n=1; n<=k; n++) {
			posicion += n*d;
			if(posicion >= k) {
				long long an = 0;
				for(int i = 0; i < coeficientes.size(); i++) {
					an += coeficientes[i] * pow(n,i);
				}
				printf("%llu\n", an);
				break;
			}
		}

	}
	return 0;
}