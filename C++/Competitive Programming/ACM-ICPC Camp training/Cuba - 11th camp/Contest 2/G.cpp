#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

bool maik(pair<int, int> p1, pair<int, int> p2) {
	int dif1 = p1.second - p1.first;
	int dif2 = p2.second - p2.first;
	return dif1 < dif2;
}

int main(int argc, char const *argv[])
{
	int n;
	vector<int> players;
	scanf("%d", &n);
	while(n--) {
		int p;
		scanf("%d", &p);
		players.push_back(p);
	}
	sort(players.begin(), players.end());
	vector< pair<int, int> > costo;
	for(int i=0; i<players.size()-1; i+=2) {
		costo.push_back(make_pair(players[i], players[i+1]));
	}
	sort(costo.begin(), costo.end(), maik);

	int german = 0;
	int gianina = 0;
	bool pierde = false;
	for(int i=0; i<players.size(); i++) {
		if(i%2)
			german+=players[i];
		else
			gianina+=players[i];
	}

	if(german <= gianina) 
		pierde = true;

	int turnos = 0;
	for(int i=0; i<costo.size(); i++) {
		pair<int,int> p = costo[i];
		int dif = p.second - p.first;
		if(german-dif > gianina+dif){
			turnos++;
			german-=dif;
			gianina+=dif;
		} else 
			break;	
	}	

	if(pierde)
		printf("%d\n", -1);
	else
		printf("%d\n", turnos);			

	return 0;
}