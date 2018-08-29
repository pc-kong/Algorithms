#include <bits/stdc++.h>
using namespace std;

vector<int> clases[21];
long long dp[1048577][21];
int allmask;
int n;


long long buttom_up(int i, int j) {
    unsigned long long ways = 0;
    for(int mask = allmask; mask >= 0; mask--) {
        if(__builtin_popcount(mask) != n-1) 
            continue;
        if(mask == allmask) {
            dp[mask][n-1] = 1;
            continue;
        }
        dp[mask][n-1] = 0;
        for(int i = 0; i < clases[n-1].size(); i++) {
            if(mask & (1<<clases[n-1][i])) {
                continue;
            }
            dp[mask][n-1]++;
        }
    }
    for(int k = n-2; k >= 0; k--) {
        for(int mask = allmask; mask >= 0; mask--) {
            if(__builtin_popcount(mask) != k) 
                continue;
            ways = 0;
            if(mask == allmask) {
                dp[mask][k] = 1;
                continue;
            }
            int size = clases[k].size();
            for(int j = 0; j < size; j++) {
                if(mask & (1 << clases[k][j])) 
                    continue;
                else{
                    int newmask = mask | (1 << clases[k][j]);
                    ways += dp[newmask][k+1];  
                }
            }
            dp[mask][k] = ways;
        }
    }
    return dp[i][j];

}

int main() {
    int casos;
    scanf("%d", &casos);
    while(casos--) {
        for(int i = 0; i < 21; i++) {   
            clases[i].clear();
        }
        scanf("%d", &n);
        int x;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                scanf("%d", &x);
                if(x == 1) {
                    clases[j].push_back(i);
                }
            }
        }
        allmask = (1 << n) - 1;
        printf("%lli\n", buttom_up(0,0));
    }    
    return 0;
}
