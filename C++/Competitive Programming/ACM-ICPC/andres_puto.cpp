#include <bits/stdc++.h>

using namespace std;

int main() {
	
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		vector<long long> numeros;
		while(n--) {
			long long x;
			scanf("%lli", &x);
			numeros.push_back(x);
		}
		long long subsequence = 0;
		for(long long i: numeros) {
			if(i>0) {
				subsequence += i;
			}
		}
		if(subsequence == 0){
			subsequence = numeros[0];
			for(long long i: numeros) {
				if(i > subsequence)
					subsequence = i;
			}
		}
		long long subarray = numeros[0];
		long long actual = numeros[0];
		for(long long i = 1; i<numeros.size(); i++) {
			subarray = max(numeros[i], numeros[i] + subarray);
			actual = max(subarray, actual);
		}
		cout << actual << " " << subsequence << endl;
	}
	return 0;
}