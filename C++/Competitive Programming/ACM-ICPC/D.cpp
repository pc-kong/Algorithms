#include <bits/stdc++.h>
using namespace std;

int main() {

	string N, M;
	cin >> N >> M; 
	string N2 = "", M2 = "";
	int lenN = N.size() - 1, lenM = M.size() - 1;
	while(lenN >= 0 && lenM >= 0) {
		if(N[lenN] < M[lenM]) {
			M2 = M[lenM] + M2;
		} else if (M[lenM] < N[lenN]) {
			N2 = N[lenN] + N2;
		} else {
			M2 = M[lenM] + M2;;
			N2 = N[lenN] + N2;
		}
		lenN--;
		lenM--;
	}

	if(lenN >= 0) {
		for(int i=lenN; i>=0; i--)
			N2 = N[i] + N2;
	}
	if(lenM >= 0) {
		for(int i=lenM; i>=0; i--)
			M2 = M[i] + M2;
	}
	if(N2 == "") {
		printf("YODA\n");
		printf("%d\n", stoi(M2));
	} else if (M2 == "") {
		printf("%d\n", stoi(N2));
		printf("YODA\n");
	} else {
		printf("%d\n", stoi(N2));
		printf("%d\n", stoi(M2));
	}

	return 0;
}