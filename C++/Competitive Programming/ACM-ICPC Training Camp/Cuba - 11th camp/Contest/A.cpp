#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	while(n) {
		double bob = ceil(log2(n));
		if(pow(2,bob) - 1 == n)
			printf("Bob\n");
		else
			printf("Alice\n");
		scanf("%d", &n);
	}	
	return 0;
}