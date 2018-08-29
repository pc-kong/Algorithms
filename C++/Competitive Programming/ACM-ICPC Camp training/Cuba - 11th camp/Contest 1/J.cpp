#include <bits/stdc++.h>

using namespace std;

string a, b;
int dp[1001][1001];
int n, m;

int LCS() {
	for(int i=1; i < n+1; i++) {
		for(int j=1; j < m+1; j++) {
			if(a[i-1] == b[j-1])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	return dp[n][m];
}

int main(int argc, char const *argv[])
{
	
	while(getline(cin, a) && getline(cin, b)) {
		n = a.size(), m = b.size();
		printf("%d\n", LCS());
		memset(dp, 0, sizeof dp);
	}

	return 0;
}

