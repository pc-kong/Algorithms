#include <bits/stdc++.h>

using namespace std;

bool comp(string a, string b) {
	for(int i=0; i<a.size(); i++) {
		if(a[i] > b[i]) {
			return false;
		}	
	}
	return true;
} 

string rev(string a) {
	string aux = "";
	for(int i=a.size()-1; i>=0; i-- ) {
		aux += a[i]; 
	}
	return aux;
}

int main() {
	int n;
	vector<long long> v;
	scanf("%d", &n);
	int n2 = n;
	while(n--) {
		int val;
		scanf("%d", &val);
		v.push_back(val);
	}
	long long total = 0;
	string a;
	string b;
	n2--; 
	bool can = true;
	int i = 0;
	cin >> a;
	while(n2--) {
		cin >> b;
		if(a.size() > b.size()) {
			can = false;
			break;
		}
		if(comp(a,b)) {
			i++;
			a = b;
			continue;
		} else {
			a = rev(a);
			if(comp(a,b)) {
				total += v[i];
				i++;
				a = b;
				continue;
			} else {
				can = false;
				break;
			}
		}
	}
	if(can)
		printf("%lli\n", total);
	else
		printf("-1\n");
	return 0;
}