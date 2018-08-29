#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	while(scanf("%d", &n) != EOF) {
		vector<long long> numbers[51];
		for (int i = 0; i < n; i++) {
			int num;
			scanf("%d", &num);
			numbers[num].push_back(0);
		}
		long long suma = 0;
		long long maximo = 1;
		for (int i = n; i >= 1; i--) {
			for (int j = 0; j < numbers[i].size(); j++) {
				if (numbers[i][j] == 0) {
					numbers[i][j] = maximo; 
					suma += numbers[i][j];
				}        
			}

			for (int j = 0; j < numbers[i].size(); j+=2) {
				numbers[i-1].push_back(numbers[i][j] + numbers[i][j+1]);
				maximo = max(maximo, max(numbers[i][j], numbers[i][j+1]));
			}
		}
		printf("%lli\n", suma);
	}    
	return 0;
}