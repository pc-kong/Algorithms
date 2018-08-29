#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	while(n) {
		vector<int> vecinos[n];
		vector<bool> visitado(n, false);
		vector<bool> color(n, false);
		int edge;
		scanf("%d", &edge);
		while(edge--) {
			int u, v;
			scanf("%d %d", &u, &v);
			vecinos[u].push_back(v);
			vecinos[v].push_back(u);
		}
		queue<int> cola;
		cola.push(0);
		color[0] = true;
		bool se_puede = true;
		visitado[0] = true;
		while(!cola.empty()) {
			int actual = cola.front();
			cola.pop();
			for(int u: vecinos[actual]) {
				if(!visitado[u]) {
					color[u] = !color[actual];
					cola.push(u);
					visitado[u] = true;
				} else {
					if(color[u] == color[actual]) {
						se_puede = false;
						break;
					}
				}
			}
		}
		if(se_puede)
			printf("BICOLORABLE.\n");
		else
			printf("NOT BICOLORABLE.\n");
		scanf("%d", &n);
	}
	return 0;
}