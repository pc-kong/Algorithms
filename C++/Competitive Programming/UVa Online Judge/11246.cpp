#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d", &T);
	vector<long long> coins;
	long long total = 0;
	while(T--) {
		int n;
		scanf("%d", &n);
		while(n--) {
			long long c;
			scanf("%lli", &c);
			coins.push_back(c);
		}
		total = coins[0];
        int diff = 1;
		for(int i=1; i < coins.size()-1; i++) {
			if(total + coins[i] < coins[i+1]) {
				diff++;
				total += coins[i];
			}
		}
		diff++;
		printf("%d\n", diff);
	}
	return 0;
}