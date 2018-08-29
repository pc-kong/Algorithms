#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
	
	int g;
	scanf("%d", &g);
	while(g--) {
		int n, e;
		scanf("%d %d", &n, &e);
		vector<int> vecinos[n];
		vector<int> distancias(n, -1);
		while(e--){
			int u, v;
			scanf("%d %d", &u, &v);
			vecinos[u-1].push_back(v-1);
			vecinos[v-1].push_back(u-1);
		}
		int obj;
		scanf("%d", &obj);
		queue<int> cola;
		cola.push(obj-1);
		distancias[obj-1] = 0;
		while(!cola.empty()){
			int v = cola.front();
			cola.pop();
			for(int u: vecinos[v]){
				if(distancias[u] == -1){
					distancias[u] = 6 + distancias[v];
					cola.push(u);
				}
			}
		}
		for (int i = 0; i < n; ++i)
		{
			if(i == obj-1)
				continue;
		 	cout << distancias[i];
		 	if(i <n-1)
		 		cout << " ";
		}
		cout << "\n";

	}
	return 0;
}