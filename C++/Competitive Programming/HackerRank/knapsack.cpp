#include <bits/stdc++.h>
#include <iostream>


using namespace std;

long long memo[2000][2000];
vector<pair<int,int>> objetos;

int main(int argc, char const *argv[])
{
	int n, m;
	scanf("%d %d", &n, &m);
	int size, val;
	for(int i=0; i<m; i++){
		scanf("%d %d", &size, &val);
		pair<int, int> obj(size,val);
		objetos.push_back(obj);
	}
	for(int i=1; i<n+1; i++) {
		for(int j=1; j<m+1; j++) {
			if(objetos[j-1].first > i){
				memo[i][j] = memo[i][j-1];
			} else {
				memo[i][j] = max(memo[i][j-1], memo[i-objetos[j-1].first][j-1]+objetos[j-1].second);
			}
		}
	}

	cout << memo[n][m] << endl;

	return 0;
}