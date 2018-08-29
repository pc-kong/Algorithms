#include <bits/stdc++.h>

using namespace std;

long long profundidad;

long long binary(long long nodo, int pelota) {
	long long hijoI = nodo * 2;
	long long hijoD = hijoI + 1;
	if(profundidad > hijoI) {
		if(pelota % 2 == 0)
			return binary(hijoD, pelota / 2);
		return binary(hijoI, pelota / 2 + 1);
	}
	return nodo;
}

int main(int argc, char const *argv[])
{
	int l;
	scanf("%d", &l);
	while(l--) {
		int D, I;
		scanf("%d %d", &D, &I);
		profundidad = pow(2,D);
		long long resultado = binary(1, I);
		printf("%lli\n", resultado);
	}
	int dummy;
	scanf("%d", &dummy);
	return 0;
}