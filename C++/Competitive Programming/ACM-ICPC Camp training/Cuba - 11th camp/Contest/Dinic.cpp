#include <bits/stdc++.h>
using namespace std;
#define dprint(v) cout << #v"=" << v << endl //;)
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef pair<int,int> ii;

const int MAX = 300;
int nodes, src, dst;
int dist[MAX], q[MAX], work[MAX];

struct Edge {
	int to, rev;
	ll f, cap;
	Edge(int to, int rev, ll f, ll cap) : to(to), rev(rev), f(f), cap(
	cap) {}
};

vector<Edge> G[MAX];

// Adds bidirectional edge
void addEdge(int s, int t, ll cap){
	G[s].pb(Edge(t, sz(G[t]), 0, cap));
	G[t].pb(Edge(s, sz(G[s])-1, 0, 0));
}

bool dinic_bfs(){
	fill(dist, dist+nodes, -1);
	dist[src]=0;	
	int qt=0;
	q[qt++]=src;
	for(int qh=0; qh<qt; qh++){
		int u =q[qh];
		forall(e, G[u]){
			int v=e->to;
			if(dist[v]<0 && e->f < e->cap){
				dist[v]=dist[u]+1;
				q[qt++]=v;
			}
		}
	}
	return dist[dst]>=0;
}

ll dinic_dfs(int u, ll f){
	if(u==dst) return f;
	for(int &i=work[u]; i<sz(G[u]); i++){
		Edge &e = G[u][i];
		if(e.cap<=e.f) continue;
		int v=e.to;
		if(dist[v]==dist[u]+1){
			ll df=dinic_dfs(v, min(f, e.cap-e.f));
			if(df>0){
				e.f+=df;
				G[v][e.rev].f-= df;
				return df;
			}
		}
	}
	return 0;
}

ll maxFlow(int _src, int _dst){
	src=_src;
	dst=_dst;
	ll result=0;
	while(dinic_bfs()){
		fill(work, work+nodes, 0);
		while(ll delta=dinic_dfs(src,INF))
			result+=delta;
	}
	return result;
}


