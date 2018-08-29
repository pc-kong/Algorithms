#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int n, k;
	scanf("%d %d", &n, &k);
	while(n || k) {
		if(k > n-k) 
			k = n-k;
		long long n_k = 1;
		for(int i=1; i<=k; i++) {
			n_k = ((n-k+i)*n_k)/i;
		}
		printf("%lli\n", n_k);
		scanf("%d %d", &n, &k);
	}
	return 0;
}