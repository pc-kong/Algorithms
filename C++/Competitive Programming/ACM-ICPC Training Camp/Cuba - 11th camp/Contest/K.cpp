#include <bits/stdc++.h>

using namespace std;   

long long sieve_size;
bitset<100000000> bs;
vector<int> primos;

void sieve(long long upper) {
	sieve_size = upper + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for(long long i=2; i<= sieve_size; i++) {
		if(bs[i]) {
			for(long long j=i*i; j <= sieve_size; j += i) {
				bs[j] = 0;
			}
			primos.push_back((int)i);
		}
	} 
} 

long long numPF(long long N) {
	long long PF_idx = 0, PF = primos[PF_idx], ans = 0;
		while (PF * PF <= N) {
			while (N % PF == 0) { N /= PF; ans++; }
				PF = primos[++PF_idx];
	}
	if (N != 1) ans++;
	return ans;
}

int main(int argc, char const *argv[])
{
	sieve(100000000);
	long long m;
	while(scanf("%lli", &m) != EOF) {
		for(int i=2; i<1000000000; i++) {
			long long p = numPF(i);
			if(p == m) {
				printf("%lli %d\n", m, i); 
				break;
			}
		}
	}

	return 0;
}