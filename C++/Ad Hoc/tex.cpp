#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main(){
	string cad;
	bool par = false;
	string aux = "";
	while(getline(cin,cad)) {
		for (int i = 0; i < cad.size(); i++){
			if(cad.at(i) == '"' && par == false) {
				aux += "``";
				par = true;
			} else if(cad.at(i) == '"' && par) {
				aux += "''";
				par = false;
			} else {
				aux += cad.at(i);
			}
		}
		aux += '\n';
	}
	cout << aux;

	return 0;
}