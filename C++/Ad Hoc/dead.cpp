#include <bits/stdc++.h>
using namespace std;

int main(){

	int jugadores;
	int dead;
	int rounds;
	int actual;
	int bud;
	int total = 0;
	int ganancia = 0;
	while(cin >> jugadores){
		cin  >> rounds;
		ganancia = 0;
		for (int i = 0; i < rounds; i++)
		{
			cin >> bud >> dead;
			total = 0;
			for (int j = 0; j < jugadores-1; j++)
			{
				cin >> actual;
				total += actual;

			}
			if(total+dead > bud)
				dead = 0;
			if(total >= bud)
				continue;
			if(total+10000 <= bud) {
				ganancia += 10000-dead;
				continue;
			}
			if(total+1000 <= bud) {
				ganancia += 1000-dead;
				continue;
			}
			if(total+100 <= bud) {
				ganancia += 100-dead;
				continue;
			}
			if(total+10 <= bud) {
				ganancia += 10-dead;
				continue;
			}
			if(total+1 <= bud) {
				ganancia += 1-dead;
				continue;
			}
		}
		cout << ganancia << endl;

	}

	return 0;
}