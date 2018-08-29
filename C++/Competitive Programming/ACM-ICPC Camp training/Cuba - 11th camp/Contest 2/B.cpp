#include <bits/stdc++.h>

using namespace std;

struct ingrediente {
    long double cantidad;
    int orden;
    long double joy;
    long double unjoy;
    ingrediente(long double cantidad = 0, int orden = 0, long double joy = 0, long double unjoy = 0)
    : cantidad(cantidad), orden(orden),  joy(joy), unjoy(unjoy) {}
};

bool fong(ingrediente p1, ingrediente p2) {

	return p1.joy*p2.unjoy > p1.unjoy*p2.joy;
}

bool fong2(pair<int, long double> p1, pair<int, long double> p2) {
	return p1.first < p2.first;
}

int main(int argc, char const *argv[])
{
	/*
	freopen("burrito.in", "r", stdin);
	freopen("burrito.out", "w", stdout);*/
	long double acumulado = 0;
	int n;
	long double joy, unhap;
	vector< pair<int, long double> > cantidades;
	scanf("%d %Lf %Lf", &n, &joy, &unhap);
	vector< ingrediente > costo;
	for(int i=0; i<n; i++) {
		long double cant, mas, men;
		scanf("%Lf %Lf %Lf", &cant, &mas, &men);
		if(mas && men) {
			costo.push_back(ingrediente(cant, i, mas, men));
		} if(!men) {
			acumulado += cant*mas;
			cantidades.push_back(make_pair(i, cant));
		}

	}

	sort(costo.begin(), costo.end(), fong);

	long double max_joy = acumulado;
	long double unhappy = 0;
	bool termina = true;
	for(int i=0; i<costo.size(); i++) {
		termina = false;
		ingrediente p = costo[i];
		long double dif = unhap - unhappy;
		long double cantidad = 0;
		if(dif > 0) {

			if(p.cantidad*p.unjoy <= dif) {
				unhappy += p.cantidad*p.unjoy;
				max_joy += p.joy*p.cantidad;
				cantidad += p.cantidad;
			} else {
				long double cacho = dif/p.unjoy;
				max_joy += cacho*p.joy;
				cantidad += cacho;
				termina = true;
			}

			cantidades.push_back(make_pair(p.orden, cantidad));
			if(termina)
				break;
		}

	}
	
	if(max_joy < joy) {
		printf("-1 -1\n");
		termina = false;
	}

	if(termina){
		sort(cantidades.begin(), cantidades.end(), fong2);
		printf("%.10Lf %.10Lf\n", max_joy, unhappy);
		for(int j=0; j<cantidades.size()-1; j++)
			printf("%.10Lf ", cantidades[j].second);
		printf("%.10Lf \n", cantidades[cantidades.size()-1].second);
	}

	return 0;
}


