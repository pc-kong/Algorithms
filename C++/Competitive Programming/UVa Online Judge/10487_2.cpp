#include <bits/stdc++.h>

using namespace std;

vector<int> numeros;

int binary(int i, int query) {
	int minimo = numeros[0] + numeros[1];
	for(int j = 0; j < numeros.size(); j++) {
		if(j != i) {
			if(abs(minimo-query) > abs((numeros[i]+numeros[j])-query))
					minimo = numeros[i]+numeros[j];
		}
	}
	return minimo;
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
			int minimo = binary(0,q);
			for(int i = 1; i < numeros.size(); i++) {
				int actual = binary(i,q);
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