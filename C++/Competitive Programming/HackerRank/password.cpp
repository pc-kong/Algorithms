#include <bits/stdc++.h>

using namespace std;

bool esta(char c, string str){
	for (int i = 0; i < str.size(); ++i)
	{
		if(c == str[i])
			return true;
	}
	return false;
}

int main(){
	int n;
	scanf("%d", &n);
	string pass = "";
	cin >> pass;
	int res = 4;
	bool digit = false;
	bool lower = false;
	bool upper = false;
	bool symbol = false;
	string numbers = "0123456789";
	string lower_case = "abcdefghijklmnopqrstuvwxyz";
	string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string special_characters = "!@#$%^&*()-+";
	for (int i = 0; i < pass.size(); ++i)
	{
		if(esta(pass[i], numbers) && !digit){
			digit = true;
			res-=1;
		}
		
		if(esta(pass[i], lower_case) && !lower){
			lower = true;
			res-=1;
		}
		if(esta(pass[i], upper_case) && !upper){
			upper = true;
			res-=1;
		}
		if(esta(pass[i], special_characters) && !symbol){
			symbol = true;
			res-=1;
		}
	}
	if(n+res < 6){
		cout << 6-n << "\n";
	} else {
		cout << res << "\n";
	}

}