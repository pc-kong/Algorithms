#include <bits/stdc++.h>

using namespace std;

// limit for array size
const int N = 100000; 
 
int n; // array size
 
// Max size of tree
int tree[2 * N];
 
// function to build the tree
void build( int arr[]) 
{ 
    // insert leaf nodes in tree
    for (int i=0; i<n; i++)    
        tree[n+i] = arr[i];
     
    // build the tree by calculating parents
    for (int i = n - 1; i > 0; --i)     
        tree[i] = tree[i<<1] * tree[i<<1 | 1];    
}
 
// function to update a tree node
void updateTreeNode(int p, int value) 
{ 
    // set value at position p
    tree[p+n] = value;
    p = p+n;
     
    // move upward and update parents
    for (int i=p; i > 1; i >>= 1)
        tree[i>>1] = tree[i] * tree[i^1];
}
 
// function to get sum on interval [l, r)
int query(int l, int r) 
{ 
    int res = 1;
     
    // loop to find the sum in the range
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l&1) 
            res *= tree[l++];
     
        if (r&1) 
            res *= tree[--r];
    }
     
    return res;
}

int main(int argc, char const *argv[])
{
	int N, K;
	while(scanf("%d %d", &N, &K) != EOF) {
		int numeros[N];
		int index = 0;
		int n = N;
		while(N--) {
			int n;
			scanf("%d", &n);
			numeros[index] = n;
			index++;
		}
		string s = "";
		build(numeros);
		while(K--) {
			char c;
			cin >> c;
			int i, v;
			scanf("%d %d", &i, &v);
			if(c == 'C') {
				updateTreeNode(i-1, v);
			} else {
				int signo = query(i-1, v);
				if(signo > 0)
					s += "+";
				else if(signo < 0)
					s += "-";
				else
					s += "0";
			}
		}
		cout << s << endl;
		s = "";
	}
	return 0;
}