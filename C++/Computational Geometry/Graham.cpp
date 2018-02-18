#include <bits/stdc++.h>
using namespace std;

struct punto {
    int x;
    int y;
    punto(int x = 0, int y = 0)
    : x(x), y(y) {}
};

punto pivot = punto(0,0);
vector <punto> cierre;

int prod_cruz(punto a, punto b){
	return a.x * b.y - b.x * a.y;
}

punto resta(punto a, punto b){
	return punto(a.x-b.x, a.y-b.y);
}

int giro(punto a, punto b, punto c){
	punto ab = resta(b,a);
	punto ac = resta(c,a);
	return prod_cruz(ab, ac);
}

double distancia(punto a, punto b){
	punto ab = resta(b, a);
	return sqrt(ab.x * ab.x + ab.y * ab.y);
}

bool compara(punto a, punto b) {
	if(giro(pivot, a, b) == 0){
		return distancia(pivot, a) < distancia(pivot, b);
	}
	punto pa = resta(a,pivot);
	punto pb = resta(b,pivot);
	return (atan2(pa.y, pa.x) - atan2(pb.y, pb.x) < 0);
}

void convex_hull(int n, vector<punto> puntos){
	//if puntos.size() is < 3, the CH is puntos.
	if(n <= 3){
		cierre = puntos;
		return;
	}
	//finding the lowest point on the Y axis and the rightmost on X
	int aux = 0;
	for(int i = 0; i < n; i++){
		if(puntos[i].y < puntos[aux].y){
			aux = i;
		}else if(puntos[aux].y == puntos[i].y && puntos[aux].x < puntos[i].x){
			aux = i;
		}
	}
	//puting the pivot in puntos[0]
	punto temp = puntos[0];
	puntos[0] = puntos[aux];
	puntos[aux] = temp;
	pivot = puntos[0];
	//Sorting all the points with respect to pivot
	sort(++puntos.begin(), puntos.end(), compara);
	//finding the CH
	cierre.push_back(puntos[n-1]);
	cierre.push_back(puntos[0]);
	cierre.push_back(puntos[1]);
	int i = 2;
	int j;
	while(i < n){
		j = cierre.size()-1;
		if(giro(cierre[j-1], cierre[j], puntos[i]) > 0){
			cierre.push_back(puntos[i++]);
		} else {
			cierre.pop_back();
		}
	}
	cierre.pop_back();
}	

int main() {
	int n;
	scanf("%d", &n);
	
	vector<punto> puntos;
	for(int i = 0; i < n; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		puntos.push_back(punto(x, y));
	}
	convex_hull(puntos.size(), puntos);
	cout << "\nConvex Hull points: ";
	cout << cierre.size() << "\n";
	for(int i = 0; i < cierre.size(); i++){
		cout << cierre[i].x << " " << cierre[i].y << endl;
	}
	return 0;
}