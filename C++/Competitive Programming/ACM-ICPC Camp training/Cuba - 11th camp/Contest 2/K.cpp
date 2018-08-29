#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int n, p, c, h;
	scanf("%d %d %d %d", &n, &p, &c, &h);
	vector<long long> numeros;
	int index = 1;
	while(n--) {
		long long c_in;
		scanf("%lli", &c_in);
		numeros.push_back(c_in);
	}
	long long mio;
	scanf("%lli", &mio);
	p--;
	int quita = p;
	while(p--) {
		long long c_in;
		scanf("%lli", &c_in);
		numeros.push_back(c_in);
	}
	printf("%d\n", quita);
	for(int i=0; i<numeros.size(); i++) {
		if(numeros[i] == h && quita--) {
			numeros[i] = -1;
		} 
		if (!quita)
			break;
	}		
	for(long long i: numeros)
		printf("%lli ", i);
	vector<int> cantidad(1000001);
	for(int i: numeros) {
		cantidad[i]++;
	}
	printf("\n");
	for(int i=0; i<7; i++) {
		printf("%d %d \n", i, cantidad[i]);
	}
	int para = numeros.size() - quita;
	int mi_cantidad = cantidad[h];
	vector<int> posiciones;
	int posibles = 0;
	index = 1;
	bool gano = true;
	for(int i: numeros) {
		if(i == -1) {
			index++;
			continue;
		} 
		if(cantidad[i] > mi_cantidad) {
			if(mio == h && mi_cantidad+1 > cantidad[i]-1) {
				posibles++;
				posiciones.push_back(index);
			} else {
				printf("0\n");
				gano = false;
				break;
			}
			index++;	
		}
		if(cantidad[i] < mi_cantidad) {
			posibles++;
			posiciones.push_back(index);
			index++;
			continue;
		}
		if(cantidad[i] == mi_cantidad) {
			if(mio == h) {
				posibles++;
				posiciones.push_back(index);
				index++;	
				continue;
			} else {
				printf("0\n");
				gano = false;
				break;
			}
		}
		if(index > para )
			break;
	}
	if(gano) {
		printf("%d\n", posibles);
		for(int i=0; i<posiciones.size()-1; i++)
				printf("%d ", posiciones[i]);
			printf("%d\n", posiciones[posiciones.size()-1]);
	}		
	return 0;
}