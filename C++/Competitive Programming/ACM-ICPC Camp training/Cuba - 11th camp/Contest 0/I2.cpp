#include <bits/stdc++.h>

using namespace std;

int INF = INT_MAX;

int tree[4000004];
int posicion[4000004];
int A[1000002];

void Build(int node, int start, int end){
	if(start == end){
		tree[node] = A[start];
		posicion[start] = node;
	}else{
		int mid = (start + end) / 2;
		Build(2*node, start, mid);
		Build(2*node+1, mid+1, end);
		tree[node] = tree[2*node] * tree[2*node+1];
	}
}

void Update(int ind, int x){
	A[ind] = x;
	int pos = posicion[ind];
	tree[pos] = x;
	while(pos != 1){
		pos /= 2;
		tree[pos] = tree[pos*2] * tree[pos*2+1];
	}
}
int Query(int node, int start, int end, int l, int r){
	if(start > end || r < start || end < l)
		return 0;
	if(l <= start && end <= r)
		return tree[node];
	int mid = (start + end) / 2;
	int iz = Query(node*2, start, mid, l, r);
	int der = Query(node*2 + 1, mid + 1, end, l, r); 
	return (iz * der);
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
		Build(1,1,n);
		while(K--) {
			char c;
			cin >> c;
			int i, v;
			scanf("%d %d", &i, &v);
			if(c == 'C') {
				Update(i-1, (A[i])%2);
			} else {
				int signo = Query(1, 1, n, i-1, v-1);
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