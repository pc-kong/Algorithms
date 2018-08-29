#include <bits/stdc++.h>

using namespace std;

int main() {

	int t;
	scanf("%d", &t);
	while(t--){
		string s;
		cin >> s;
		int abc[3] = {0,0,0};
		for(int i = 0; i<s.length(); i++) {
			abc[s[i]-97] += 1;
		}
		if(abc[0] == 0 && abc[1] == 0 || abc[1] == 0 && abc[2] == 0 || abc[0] == 0 && abc[2] == 0)
			cout << s.length() << endl;
		else if(abc[0] % 2 == 0 && abc[1] % 2 == 0 && abc[2] % 2 == 0)
			cout << 2 << endl;
		else if(abc[0] % 2 == 1 && abc[1] % 2 == 1 && abc[2] % 2 == 1)
			cout << 2 << endl;
		else
			cout << 1 << endl;
	}
	return 0;
}