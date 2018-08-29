#include <bits/stdc++.h>

using namespace std;

vecto<int> fase_adivinadora(int J, int nodos) {
	int rnd;
	vector<int> candidatos;
	bool agrega = true;
	while(J > 0) {
		rnd = rand() % nodos;
		for(int i=0; i<candidatos.size(); i++) {
			if(rnd == candidatos[i])
				agrega = false;
		}
		if(agrega) {
			candidatos.push_back(rnd);
			J--
		}
		agrega = true;
	}
	return candidatos;
}

int main() {
	
	int nodos = rand() % 10 + 5;
	vecto<int> grafica[nodos];
	for(int i=0; i<nodos; i++) {
		for(int j=i+1; j<nodos; j++) {
			int volado = rand() % 10 + 1;
			if(volado > 5) {
				grafica[i].push_back(j);
				grafica[j].push_back(i); 
			}
		}
	}
	int J = rand() % nodos + 1;

	return 0; 
}