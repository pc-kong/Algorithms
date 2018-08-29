#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
	
	int N, C, S;
	while(scanf("%d %d %d", &N, &C, &S) != EOF) {

		int sequence = 0;
		int actual;
		int respuesta = 0;	
		while(C--) {
			scanf("%d", &actual);
			if(((sequence%N) + N)%N == S-1) {
				respuesta++;
			}
			sequence += actual;
		}
		if(((sequence%N) + N)%N == S-1) {
			respuesta++;
		}
		cout << respuesta << endl;
	}
	return 0;
}