#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, K;
	scanf("%d %d", &N, &K);
	vector<int> houses;
	while(N--) {
		int house;
		scanf("%d", &house);
		houses.push_back(house);
	}
	sort(houses.begin(), houses.end());
	int i = 0;
	int antenas = 0;
	while(i < houses.size()) {
		int radio = houses[i] + K;
		
		int anterior = houses[i];
		
		antenas++;
		i++;
		while(i < houses.size() && houses[i] <= radio) {
			i++;
		}
		i--;
		radio = houses[i] + K;
		while(i < houses.size() && houses[i] <= radio) {
			i++;
		}
	}
	printf("%d\n", antenas);
	return 0;
}