#include <bits/stdc++.h>

using namespace std;

vector<int> numeros;

int binary(int i, int base, int limite, int query) {
	int j = (limite + base)/2;
	if(limite - base < 2) {
		if(abs(numeros[i]+numeros[base]-query) > abs(numeros[i]+numeros[limite]-query))
			return numeros[i] + numeros[limite];
		return numeros[i] + numeros[base];
	}
	if(numeros[i]+numeros[j] == query) {

		return query;
	}
	if(numeros[i]+numeros[j] > query) {

		return binary(i, base, j, query);
	}
	if(numeros[i]+numeros[j] < query) {

		return binary(i, j, limite, query);
	}
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	int caso = 1;
	while(n) {
		while(n--) {
			int actual;
			scanf("%d", &actual);
			numeros.push_back(actual);
		}
		sort(numeros.begin(), numeros.end());
		int m;
		scanf("%d", &m);
		vector< pair<int, int> > answers;
		while(m--) {
			int q;
			scanf("%d", &q);
			int minimo = binary(0, 1, numeros.size()-1, q);

			for(int i = 1; i < numeros.size()-1; i++) {
				int actual = binary(i, i+1, numeros.size()-1, q);

				if(abs(minimo-q) > abs(actual-q))
					minimo = actual;
			}
			answers.push_back(make_pair(q,minimo));
		}
		printf("Case %d:\n", caso);
		for(pair<int, int> p: answers) {
			printf("Closest sum to %d is %d.\n", p.first, p.second);
		}
		numeros.clear();
		caso++;
		scanf("%d", &n);
	}
	return 0;
}