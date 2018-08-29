#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n); 
	int h = 0, m = 0;
	vector<char> cadena;
	if(n == 1) {
		char c;
		cin >> c;
		cout << "HM" << endl;
	} else { 
		n--;
		while(n--){
			char c;
			cin >> c;
			if(c == 'H')
				h++;
			if(c == 'M')
				m++;
			cadena.push_back(c);
		}

		if(h > m)
			cout << 'H' << endl;
		if(m > h)
			cout << 'M' << endl;
		if(m == h)
			if(cadena[cadena.size()-1] == 'M')
				cout << 'H' << endl;
			else
				cout << 'M' << endl;
	}		
	return 0;
}