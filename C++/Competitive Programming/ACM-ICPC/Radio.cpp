#include <bits/stdc++.h>

using namespace std;

int main() {

	int n, k;
	scanf("%d %d", &n, &k);
	vector<int> casas;
	int casa;
	while(n--) {
		scanf("%d", &casa);
		casas.push_back(casa);
	}
	sort(casas.begin(), casas.end());
	casa = casas[0];
	int post = 0;
	int distancia = k;
	bool sale = false;
	for(int i=1; i<casas.size(); i++) {
		if(casas[i]-casa <= distancia) {
			distancia -= casas[i]-casa;
		} else {
			if(!sale) {
				post++;
				sale = true;
			} else {
				sale = false;
			}
			distancia = k;
		}
		casa = casas[i];
	}
	return 0;
}