#include <bits/stdc++.h>

using namespace std;

long long counting[100001];
unsigned long long dp[100001];


long long f() {

	dp[1] = counting[1];

	for(int i = 2; i < 100001; i++) {
		dp[i] = max(dp[i-2] + counting[i]*i, dp[i-1]);
	}
	return dp[100000];
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	while(n--) {
		int num;
		scanf("%d", &num);
		counting[num]++;
	}
	printf("%llu\n", f());
	return 0;
}