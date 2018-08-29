#include <bits/stdc++.h>
using namespace std;

int main() {

	string s;
	cin >> s;
	bool h = true;
	for(int i=0; i<s.size()-1; i++) {
		if(s[i] == s[i+1] && s[i] == 's') {
			h = false; 
			break;
		}
	}
	if(h)
		printf("no hiss\n");
	else
		printf("hiss\n");
	return 0;
}