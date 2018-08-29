#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	vector<long long> numeros;
	while(n--) {
		long long actual;
		scanf("%lli", &actual);
		numeros.push_back(actual);
	}
	int queries;
	scanf("%d", &queries);
	while(queries--) {
		long long q;
		scanf("%lli", &q);
		vector<long long>::iterator low, up;
		low = lower_bound(numeros.begin(), numeros.end(), q);
		up = upper_bound(numeros.begin(), numeros.end(), q);
		if((low - numeros.begin()) == 0 && numeros[0] >= q)
			cout << "X";
		else
			cout << numeros[low - numeros.begin()-1];
		if((up - numeros.begin()) == numeros.size() && numeros[numeros.size()-1] <= q)
			cout << " X" << endl;
		else
			cout << " " << numeros[up - numeros.begin()] << endl;
	}
	return 0;
}