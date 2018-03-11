#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main() {

	unsigned long long cases;
	while(scanf("%llu",&cases) && cases!=0) {
		printf("%llu\n", (1+((cases-1)%9)));
	}
	return 0;
}