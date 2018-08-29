#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	
	int n;
	scanf("%d", &n);
	while(n--){
		int nodos, aristas;
		scanf("%d %d", &nodos, &aristas);
		int matriz[nodos][nodos];
		for (int i = 0; i < nodos; ++i)
		{
			for (int j = 0; j < nodos; ++j)
			{
				matriz[i][j] = 1e5; 
			}
		}
		for (int i = 0; i < nodos; ++i)
		{
			matriz[i][i] = 0;
		}

		while(aristas--) {
			int u, v;
			scanf("%d %d", &u, &v);
			matriz[u-1][v-1] = 6;
			matriz[v-1][u-1] = 6;
		}
		/*
		for (int i = 0; i < nodos; ++i)
		{
			for (int j = 0; j < nodos; ++j)
			{
				cout << matriz[i][j] << " ";
			}
			cout << "\n";
		}*/
		int s;
		scanf("%d", &s);
		//Floyd-Warshall 
		for (int k = 0; k < nodos; ++k)
		{
			for (int i = 0; i < nodos; ++i)
			{
				for (int j = 0; j < nodos; ++j)
				{
					int min = matriz[i][k] + matriz[k][j];
					if(matriz[i][j] > min)
						matriz[i][j] = min;
				}
			}
		}
		/*
		cout << "floyd\n";
		for (int i = 0; i < nodos; ++i)
		{
			for (int j = 0; j < nodos; ++j)
			{
				cout << matriz[i][j] << " ";
			}
			cout << "\n";
		}*/
		for (int i = 0; i < nodos; ++i)
		{
			if(i == s-1)
				continue;
			if(matriz[s-1][i] == 1e5)
				cout << -1;
		 	else
		 		cout << matriz[s-1][i];
		 	if(i <nodos -1)
		 		cout << " ";
		}
		cout << "\n";
	}
	return 0;
}