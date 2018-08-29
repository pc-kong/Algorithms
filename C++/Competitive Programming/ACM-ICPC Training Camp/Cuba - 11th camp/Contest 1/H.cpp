#include <bits/stdc++.h>

using namespace std;

int dp[4001];
int n, a, b, c;

int foo(int n) {
	if(n == 0)
		return 0;
	if(n < 0)
		return -100000000;
	if(dp[n] == -1)
		dp[n] = max(foo(n-a) + 1, max(foo(n-b) + 1, foo(n-c) + 1));
	return dp[n];
}

int main(int argc, char const *argv[]) {
	scanf("%d %d %d %d", &n, &a, &b, &c);
	memset(dp, -1, sizeof dp);
	printf("%d\n", foo(n));
	return 0;
}