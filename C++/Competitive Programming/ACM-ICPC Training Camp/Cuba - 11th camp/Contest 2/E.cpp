#include <bits/stdc++.h>

using namespace std;

vector< pair<int, unsigned long long> > cajas[20];

bool eder(pair<int, unsigned long long> p1, pair<int, unsigned long long> p2) {
	return p1.second > p2.second;
}

int main(int argc, char const *argv[])
{
	unsigned long long x; 
	int n;
	scanf("%llu %i", &x, &n);
	unsigned long long valor;
	int caja; 
	int index = 1;
	while(n--) {
		scanf("%d %llu", &caja, &valor);
		cajas[caja].push_back(make_pair(index, valor)); 
		index++;
	}	
	for(int i=0; i<20; i++) {
		if(!cajas[i].empty())
			sort(cajas[i].begin(), cajas[i].end(), eder);
	}
/*
	for(vector< pair<int, unsigned long long> > v : cajas)
		for(int i=0; i<v.size(); i++)
			printf("%d, %llu\n", v[i].first, v[i].second);*/


	unsigned long long actual = x%10;
	int exponente = 0;
	int abiertas = 0;
	unsigned long long total = 0;
	
	vector<int> orden;
	if(actual > 0 && cajas[exponente].empty()) {
			printf("-1\n");
	} else {
		while(exponente <= 18) {
			//printf("1 ---- >%llu, %llu\n", total, actual);
			if(actual) {
				printf("entreee exponente %d\n", exponente);
				printf("%d\n", (int)cajas[exponente].size());
				for(int i=0; i<cajas[exponente].size(); i++) {
					abiertas++;
					total += cajas[exponente][i].second*pow(10,exponente);
					orden.push_back(cajas[exponente][i].first);
					if(total > actual) {
						break;
					}
				}
				actual = x%(unsigned long long)(pow(10,exponente+1));
			} else {
				actual = x%(unsigned long long)(pow(10,exponente+1));

			}	
			//printf("%llu, %llu\n", total, actual);
			if(total >= x) {
				printf("%d\n", abiertas);
				for(int i=0; i<orden.size()-1; i++)
					printf("%d ", orden[i]);
				printf("%d\n", orden[orden.size()-1]);
				break;
			}
			exponente++;
		}
		if(total < x) {
			printf("-1\n");
		}
	}	


	return 0;
}