#include<bits/stdc++.h>
using namespace std;
 
// Function to find the total number of distinct ways to get change of N
// from unlimited supply of coins in set S
int count(int S[], int n, int N)
{
    // if total is 0, return 1 (solution found)
    if (N == 0)
        return 1;

    // return 0 (solution do not exist) if total become negative or
    // no elements are left
    if (N < 0 || n < 0)
        return 0;

    // Case 1. include current coin S[n] in solution and recurse
    // with remaining change (N - S[n]) with same number of coins
    int include = count(S, n, N - S[n]);

    // Case 2. exclude current coin S[n] from solution and recurse
    // for remaining coins (n - 1)
    int exclude = count(S, n - 1, N);

    // return total ways by including or excluding current coin
    return include + exclude;
}

// Coin Change Problem
int main()
{
    // n coins of given denominations
    int S[] = {7,11,19,27,31};
    int n = sizeof(S) / sizeof(S[0]);

    // Total Change required
    int N = 12572;

    cout << "Total number of ways to get desired change is "
         << count(S, n - 1, N);

    return 0;
}