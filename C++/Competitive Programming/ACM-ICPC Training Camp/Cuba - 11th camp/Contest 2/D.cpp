#include <bits/stdc++.h>

using namespace std;

int tam;
int aux[100];

int main(int argc, char const *argv[])
{
	int n, m;
	scanf("%d %d", &n, &m);
	while(m || n) {
		vector<int> permutacion;
		vector<int> rest[n];
		int completos = 0;
		int i, j;
		while(m--) {
			scanf("%d %d", &i, &j);
			rest[j-1].push_back(i);
		}

		for(int i=0; i<n; i++) {
			if(rest[i].empty()) {
				permutacion.push_back(i+1);
				completos++;
			}
		}

		while(completos < n) {
			for(int i=0; i<n; i++) {
				if(rest[i].empty())
					continue;
				int l = 0;
				for(int j=0; j<rest[i].size(); j++) {
					for(int k=0; k<permutacion.size(); k++) {
						if(rest[i][j] == permutacion[k]) {
							l++;
						}
					}
				}
				if(l == rest[i].size()) {
					permutacion.push_back(i+1);
					rest[i].clear();
					completos++;
				}
			}
		}

		for(int i=0; i<permutacion.size() -1; i++)
			printf("%d ", permutacion[i]);

		printf("%d\n", permutacion[permutacion.size()-1]);
		scanf("%d %d", &n, &m);
	}
	return 0;
}