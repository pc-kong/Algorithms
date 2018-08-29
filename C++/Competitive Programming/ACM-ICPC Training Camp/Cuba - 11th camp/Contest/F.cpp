#include <bits/stdc++.h>

using namespace std;   

vector<long long> coprimos;

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

long long euler(long long n) {
	long long id = 0, pf = primos[id], ans = n;
	while(pf * pf <= n) {
		if(n % pf == 0) {
			ans -= ans / pf;
		}	
		while(n % pf == 0) n /= pf;
		pf = primos[++id];
	}
	if(n != 1) ans -= ans / n;
	return ans;  
}

int main(int argc, char const *argv[])
{
	sieve(100000000);
	long long m;
	scanf("%lli", &m);
	while(m) {
		printf("%lli\n", euler(m)); 
		scanf("%lli", &m);
	}

	return 0;
}