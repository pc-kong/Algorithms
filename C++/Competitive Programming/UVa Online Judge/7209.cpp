#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> get_digits(unsigned long long n)
{
	vector<int> digits;
	while(n > 0) {
		digits.push_back(n%10);
		n = n/10;
	}
	reverse(digits.begin(), digits.end());
	return digits;
}

int max_digit_ticket(vector<int> tickets) {
	for(int i = tickets.size() - 1; i >= 0; i--)
		if(tickets[i] > 0)
			return i;
	return -1;
}

void print_digits(vector<int> digits) {
	for(int i = 0; i < digits.size(); i++)
		cout << digits[i];
	cout << "\n";
}

int main () {
	unsigned long long n = 0;
	while(cin >> n) {
		vector<int> tickets(10,2);

		vector<int> digits = get_digits(n);

		int i = 0;

		while(tickets[digits[i]] > 0 && i < digits.size()) {
			tickets[digits[i]]--;
			i++;
		}

		int j = i;
		
		while(digits[i] > 0){
			if(tickets[digits[i]-1] > 0)
				digits[i] = digits [i-1]

		}
	}
	return 0;
}