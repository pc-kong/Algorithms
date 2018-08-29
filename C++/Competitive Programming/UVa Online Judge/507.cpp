#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	while(scanf("%d", &n) != EOF) {
		int ruta = 1;
		while(n--) {
			int r;
			scanf("%d", &r);
			r--;
			vector<int> rutas;
			while(r--) {
				int nice;
				scanf("%d", &nice);
				rutas.push_back(nice);
			}
			int ini = 0, fin = 0, global = rutas[0], ini2 = 0, fin2 = 0;
			int dp = rutas[0];
			for(int i = 1; i < rutas.size(); i++) {
				if(rutas[i] != max(rutas[i], dp + rutas[i])) {
					fin++;
				}
				else {
					ini = i;
					fin = i;
				}
				dp = max(rutas[i], dp + rutas[i]);	
				if(dp >= global) {
					global = dp;
					ini2 = ini;
					fin2 = fin;
				}
			}
			if(global < 0)
				printf("Route %d has no nice parts\n", ruta);
			else
				printf("The nicest part of route %d is between stops %d and %d\n", ruta, ini2, fin2);
			ruta++;
		}
	}
	return 0;
}