#include <bits/stdc++.h>
using namespace std;

int main() {
	int sabor;
	int t1, t2, t3, t4, t5;
	int x;
	int type[5];
	while(cin >> sabor)
	{
		for(int i = 0; i < 5; i++)
			type[i] = 0;
		cin >> t1 >> t2 >> t3 >> t4 >> t5;
		type[t1-1] += 1;
		type[t2-1] += 1;
		type[t3-1] += 1;
		type[t4-1] += 1;
		type[t5-1] += 1;
		cout << type[sabor-1] << endl;

	}
	return 0;
}