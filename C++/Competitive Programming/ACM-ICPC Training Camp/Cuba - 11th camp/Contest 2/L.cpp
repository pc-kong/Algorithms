#include <bits/stdc++.h>

using namespace std;

vector<long long> comp1;
vector<long long> comp2; 

bool simula_juego() {
	bool gana = false;
	while(true) {
		if(comp1[comp1.size()-1] > comp2[comp2.size()-1]) {
				comp2.pop_back();
				if(comp2.empty()) {
					gana = true;
					break;
				}
				if(comp2[comp2.size()-1] > comp1[comp1.size()-1]) {
					comp1.pop_back();
					if(comp1.empty()) {
						break;
					}
				} else {
					long long ultimo = comp2[comp2.size()-1];
					comp2.pop_back();
					if(comp2.empty()) {
						gana = true;
						break;
					}
					comp2[comp2.size()-1] += ultimo;
				}
				
		} else {
			long long ultimo = comp1[comp1.size()-1];
			comp1.pop_back();
			if(comp1.empty()) 
				break;
			comp1[comp1.size()-1] += ultimo;
			if(comp2[comp2.size()-1] > comp1[comp1.size()-1]) {
				comp1.pop_back();
				if(comp1.empty())
					break;
			} else {
				long long ultimo = comp2[comp2.size()-1];
				comp2.pop_back();
				if(comp2.empty()) {
					gana = true;
					break;
				}

				comp2[comp2.size()-1] += ultimo;
			}
			
		}
	}
	return gana;
}

bool simula_ataque() {
	comp2.pop_back();
	if(comp2.empty())
		return true;
	if(comp2[comp2.size()-1] > comp1[comp1.size()-1]) {
		comp1.pop_back();
		if(comp1.empty())
			return false;
	} else {
		long long ultimo = comp2[comp2.size()-1];
		comp2.pop_back();
		if(comp2.empty())
			return true;
		comp2[comp2.size()-1] += ultimo;
	}
	return simula_juego();
}

bool simula_fusion() {
	long long ultimo = comp1[comp1.size()-1];
	comp1.pop_back();
	if(comp1.empty())
		return false;
	comp1[comp1.size()-1] += ultimo;
	if(comp2[comp2.size()-1] > comp1[comp1.size()-1]) {
		comp1.pop_back();
		if(comp1.empty())
			return false;
	} else {
		long long ultimo = comp2[comp2.size()-1];
		comp2.pop_back();
		if(comp2.empty())
			return true;
		comp2[comp2.size()-1] += ultimo;
	}
	return simula_juego();
}

int main(int argc, char const *argv[])
{
	int n, m, caso = 1;
	while(scanf("%d %d", &n, &m) != EOF) {
		while(n--) {
			long long score;
			scanf("%lli", &score);
			comp1.push_back(score);
		}
		while(m--){
			long long score;
			scanf("%lli", &score);
			comp2.push_back(score);
		}
		sort(comp1.begin(), comp1.end());
		sort(comp2.begin(), comp2.end());

		vector<long long> aux1; 
		for(long long i: comp1)
			aux1.push_back(i);
		vector<long long> aux2; 
		for(long long i: comp2)
			aux2.push_back(i);
		
		bool gana = false;

		if(comp1[comp1.size()-1] > comp2[comp2.size()-1])
			gana = simula_ataque();
		comp1.clear();
		comp2.clear();
		for(long long i: aux1)
			comp1.push_back(i);
		for(long long i: aux2)
			comp2.push_back(i);
		gana |= simula_fusion();

		if(gana) {
			printf("Case %d: Takeover Incorporated\n", caso++);
		} else
			printf("Case %d: Buyout Limited\n", caso++);
		comp1.clear();
		comp2.clear();	
	}	

	return 0;
}