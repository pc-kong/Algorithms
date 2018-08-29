#include <bits/stdc++.h>

using namespace std;

bool migue(string a, string b){
	unsigned long long n1 = stoull(a);
	unsigned long long n2 = stoull(b);
	return n1 > n2;
}

int main(){
	int n;
	cin >> n;
	vector<string> numeros;
	while(n--){
		string in = "";
		cin >> in;
		numeros.push_back(in);

	}
	sort(numeros.begin(), numeros.end(), migue);
	for (int i = numeros.size()-1; i >= 0; i--)
	{
		cout << numeros[i] << "\n";
	}
	return 0;
}