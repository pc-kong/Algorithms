#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	scanf("%d", &n);
	int bats = n;
	double total = 0;
	while(n--) {
		double bat;
		scanf("%lf", &bat);
		if(bat != -1)
			total += bat;
		else {
			bats--;
		}

	}
	double res = total/bats;
	printf("%.15lf\n", res);
	return 0;
}