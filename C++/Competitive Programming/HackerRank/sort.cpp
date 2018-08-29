#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int> arreglo;
	int n;
	for(int i = 0; i < 3; ++i){
		cin >> n;
		arreglo.push_back(n);	
	}
	sort(arreglo.begin(), arreglo.end());
	for(int i = 0; i < arreglo.size(); ++i){
		cout << i;	
	}
	
	return 0;
}