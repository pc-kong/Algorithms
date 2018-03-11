#include <string>
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = unsigned long long;

bool is_possible(ll a, ll b, ll c) {
	if(a+b <= c)
		return false;
	if(a+c <= b)
		return false;
	if(c+b <= a)
		return false;
	return true;
}

/*string check(vector <ll> lados) {
	for(int i = 0; i < lados.size(); i++){
		for(int j = i+1; j < lados.size(); j++) {
			for(int k = j+1; k < lados.size(); k++){
				if(i == j || i == k || j == k)
					continue;
				if(is_possible(lados[i], lados[j], lados[k])) {
					return "possible";
				}
			}
		}
	}
	return "impossible";
}*/

string check(vector <ll> lados) {
	for(int i = 0; i < lados.size()-2; i++){
		if(is_possible(lados[i], lados[i+1], lados[i+2])) {
			return "possible";
		}
	}
	return "impossible";
}



int main(){

	ll in;
	cin >> in;
	ll l;
	vector<ll> lados;
	while(in) {
		cin >> l;
		lados.push_back(l);
		in--;
	}
	sort(lados.begin(), lados.end());
	printf("%s\n", check(lados).c_str());
	return 0;
}