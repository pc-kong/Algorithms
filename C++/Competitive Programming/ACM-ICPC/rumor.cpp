#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> costo(n,0);
	vector<int> vecinos[n];
	vector<bool> visitado(n, false);
	int c;
	for(int i=0; i<n; i++) {
		scanf("%d", &c);
		costo[i] = c;
	}
	int u, v;
	while(m--){
		scanf("%d %d", &u, &v);
		vecinos[u-1].push_back(v-1);
		vecinos[v-1].push_back(u-1);
	}
	queue<int> cola;
	int menor;
	long long total = 0;
	for(int i=0; i<n; i++){
		if(visitado[i] == false){
			menor = costo[i];
			cola.push(i);
			visitado[i] = true;
			while(!cola.empty()){
				int actual = cola.front();
				cola.pop();
				for(int u: vecinos[actual]){
					if(visitado[u] == false){
						if(menor > costo[u]) {
							menor = costo[u];
						}
						cola.push(u);
						visitado[u] = true;
					}
				}
			}
			total += menor;
		}
	}
	cout << total << endl;
	return 0;
}

pedrojssp
d.bHp/51BW

