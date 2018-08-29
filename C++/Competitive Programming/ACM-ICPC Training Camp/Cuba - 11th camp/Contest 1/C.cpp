#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	string s;
	cin >> s;
	while(s != "*") {
		vector<int> diferencias;
		diferencias.push_back(s[0] - 'a');
		for(int i=0; i<s.size() - 1; i++) {
			if(s[i+1] >= s[i])
				diferencias.push_back(s[i+1] - s[i]);
			else
				diferencias.push_back(26 - abs(s[i+1] - s[i]));
		}
		if(s[s.size()-1] == 'a')
			diferencias.push_back(0);
		else
			diferencias.push_back(26 - (s[s.size()-1] - 'a'));

		int ans = 0;
		int ini = 0;
		int fin = 0;
		while(true) {
			int minimo = 26;
			int maximo = -1;
			for(int i = 0; i< diferencias.size(); i++) {
				if(diferencias[i] <= minimo && diferencias[i] != 0) {
					minimo = diferencias[i];
					ini = i;
				}	
			}

			for(int i = 0; i< diferencias.size(); i++) {
				if(diferencias[i] > maximo) {
					maximo = diferencias[i];
					fin = i;
				}	
			}

/*
			printf("\ninicial : %d valor: %d  | final : %d valor : %d \n", ini, diferencias[ini], fin, diferencias[fin]);
			for(int h: diferencias) {
				printf("%d ", h);
			}*/

			if(diferencias[ini]%26 != 0 && diferencias[fin]%26 != 0) {
				diferencias[ini]--;
				diferencias[fin]++;
				ans++;
			}
			int ceros = 0;
			for(int i=0; i< diferencias.size(); i++) {
				ceros += diferencias[i]%26;
				if(diferencias[i] == 26)
					diferencias[i] = 0;
			}

			if(ceros == 0)
				break;

		}
		printf("%d\n", ans);
		cin >> s;
	}	
	return 0;
}

	