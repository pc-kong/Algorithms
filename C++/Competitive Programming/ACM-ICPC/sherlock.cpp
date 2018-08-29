#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	string s;
	cin >> s;
	if(s.size() == 0 || s.size() == 1)
		cout << "YES" << endl;
	else {
		vector<int> letters(30,0);
		for(int i=0; i<s.size(); i++){
			letters[s[i]-97]++;
		}
		bool aux = false;
		vector<int> limpio;
		cout << endl;
		for(int i=0; i<letters.size(); i++){
			cout << letters[i] << " ";
			if(letters[i] == 0)
				continue;
			else 
				limpio.push_back(letters[i]);
		}
		int res = 0;
		cout << endl;
		for(int i=0; i<limpio.size()-1; i++){
 			cout << limpio[i] << " ";
			if(limpio[i] != limpio[i+1] && !aux) {
				if(abs(limpio[i] - limpio[i+1]) == 1) {
					aux = true;
					res++;
					continue;
				}
				else {
					cout << "NO" << endl;
					break;
				}
			}
			if(aux) {
				cout << "NO" << endl;
				break;
			}

			res++;
		}
		if(res == limpio.size()-1)
			cout << "YES" << endl;
	}
	return 0;
}