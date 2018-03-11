#include <string>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main() {

	string s;
	cin >> s;
	string ans = "";
	long long i = 0;
	while(i < s.size()) {
		if(s[i] == 'R'){
			if(s[i+1] == 'B'){
				if(s[i+2] == 'L'){
					ans += 'C';
					i += 3;
					continue;
				}
			}
			if(s[i+1] == 'L'){
				if(s[i+2] == 'B'){
					ans+= 'C';
					i+=3;
					continue;
				}
			}
			ans += 'S';
			i++;
			continue;
		}
		if(s[i] == 'B'){
			if(s[i+1] == 'R'){
				if(s[i+2] == 'L'){
					ans += 'C';
					i += 3;
					continue;
				}
			}
			if(s[i+1] == 'L'){
				if(s[i+2] == 'R'){
					ans+= 'C';
					i+=3;
					continue;
				}
			}
			ans += 'K';
			i++;
			continue;
		}
		if(s[i] == 'L'){
			if(s[i+1] == 'R'){
				if(s[i+2] == 'B'){
					ans += 'C';
					i += 3;
					continue;
				}
			}
			if(s[i+1] == 'B'){
				if(s[i+2] == 'R'){
					ans+= 'C';
					i+=3;
					continue;
				}
			}
			ans += 'H';
			i++;
			continue;
		}
	}
	cout << ans <<'\n';
	return 0;
}