#include <bits/stdc++.h>
using namespace std;

int main() {

	int a, b, c, d;
	while(scanf("%d %d %d %d", &a, &b, &c, &d) != EOF) {
		int players[4] = {a,b,c,d};
		sort(players, players+4);
		cout << abs((players[0]+players[3])-(players[2]+players[1])) << endl;
	}
	return 0;
}