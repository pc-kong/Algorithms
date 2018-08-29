#include <bits/stdc++.h>
using namespace std;

//long long memo[251][50];

long change(int n, int coin, vector<int> coins) {
	if(n == 0)
		return 1;
	if(n<0)
		return 0;
	if(coin <= 0 && n > 0)
		return 0;
	//long long ways = memo[n][coin-1];
	//cout << ways << " resultado\n";
	//if(ways <= 0) {
	return change(n-coins[coin-1], coin, coins) + change(n, coin-1, coins);
		//return memo[n][coin-1];
	//}
	//return ways;
}

int main(int argc, char const *argv[])
{
	int n, m;
	scanf("%d %d", &n, &m);
	vector <int> coins;
	while(m--) {
		int coin;
		scanf("%d", &coin);
		coins.push_back(m);
	}
	long ways = change(n, coins.size(), coins);
	cout << ways << " resultado\n";

	return 0;
}