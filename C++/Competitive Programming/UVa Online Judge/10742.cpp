#include <bits/stdc++.h>

using namespace std;

vector<bool> numeros(1000001,true);
vector<int> primos;

void get_primos() {
	for(int i = 2; i*i<numeros.size(); i++) {
		if(numeros[i] == true) {
			for(int j = 2; i*j < numeros.size(); j++) {
				numeros[i*j] = false;
			}
		}
	}
	for(int i = 2; i<numeros.size(); i++){
		if(numeros[i] == true)
			primos.push_back(i);
	}
}

int main(int argc, char const *argv[])
{
	int n;
	int caso = 1;
	scanf("%d", &n);
	get_primos();
	while(n) {
		vector<int>::iterator low, low2;
		if(n > 2) {
			low = lower_bound(primos.begin(), primos.end(), n);
			long long total = 0;
			for(int i = (low - primos.begin())-1; i > 0; i--) {
				low2 = lower_bound(primos.begin(), primos.begin()+i, n-primos[i]+1);
				total += (low2 - primos.begin());
			}
			printf("Case %d: %lli\n", caso, total);
		} else
			printf("Case %d: 0\n", caso);
		scanf("%d", &n);
		caso++;	
	}
	return 0;
}