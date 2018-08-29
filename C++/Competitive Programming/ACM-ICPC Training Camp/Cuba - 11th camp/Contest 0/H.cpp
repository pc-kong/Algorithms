#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		vector< pair<int,char> > cards;
		while(n--) {
			int v;
			char c;
			cin >> v >> c;
			cards.push_back(make_pair(v,c));
		}
		pair<int, char> p = cards[0];
		bool se_pudo = true;
		for(int i = 1; i < cards.size(); i++) {
			pair<int, char> aux = cards[i];
			if(p.first == aux.first || p.second == aux.second) {
				printf("M\n");
				se_pudo = false;
				break;
			}
			p = aux;
		}
		if(se_pudo)
			printf("B\n");
	}
	return 0;
}