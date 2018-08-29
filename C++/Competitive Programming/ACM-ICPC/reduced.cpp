#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	
	string s;
	cin >> s;
	int l = 0;
	int size = s.size();
	while(l < size-1) {
		if(s[l] == s[l+1]) {
			s.erase(l,2);
			l = 0;
			size = s.size();
		}
		else
			l++;
	}
	if(s.size() == 0)
		cout << "Empty String" << endl;
	else 
		cout << s << endl;
	return 0;
}