/*Let's get high :D*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define M_PI                3.14159265358979323846

template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}

const int MAXN = 1e4+5;
const int LG = log2(MAXN) + 1;

int n;
vector<pair<int, int> > adj[MAXN];
int level[MAXN], par[MAXN][LG], cost[MAXN];

void dfs(int u, int parent, int c){
	cost[u] = cost[parent] + c;
	level[u] = level[parent] + 1;
	par[u][0] = parent;
	for(auto v : adj[u]){
		if(v.first == parent)	continue;
		dfs(v.first, u, v.second);
	}
}

int lca(int u, int v){
	if(level[u] < level[v])	swap(u, v);
	int log = log2(level[u]);
	for(int i = log; i >= 0; i--)
		if(level[u]-level[v] >= (1 << i))
			u = par[u][i];
	if(u == v)
		return u;
	for(int i = log; i >= 0; i--){
		if(par[u][i] != -1 && par[u][i] != par[v][i]){
			u = par[u][i];
			v = par[v][i];
		}
	}
	return par[u][0];
}

int kth(int n, int k){
	int log = log2(level[n]);
	for(int i = 0; i <= log; i++){
		if(k & (1 << i))
			n = par[n][i];
	}
	return n;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
	    scanf("%d", &n);
	    for(int i = 1;i <= n; i++){
	    	adj[i].clear();
	    	level[i] = 0;
	    }
	    for(int i = 0;i < n-1; i++){
	    	int a, b, c;
	    	scanf("%d%d%d", &a, &b, &c);
	    	adj[a].push_back({b, c});
	    	adj[b].push_back({a, c});
	    }
	    memset(par, -1, sizeof par);
	    level[0] = -1;
	    dfs(1, 0, 0);
	    for(int j = 1; j < LG; j++){
	    	for(int i = 1; i <= n; i++){
	    		if(par[i][j-1] != -1)
	    			par[i][j] = par[par[i][j-1]][j-1];
	    	}
	    }
	    char query[8];
	    while(scanf("%s", query) == 1){
	    	if(query[1] == 'O')	break;
	    	int a, b;
	    	scanf("%d%d", &a, &b);
	    	if(query[1] == 'I'){
	    		int lc = lca(a, b);
	    		int ans = cost[a] + cost[b] - 2*cost[lc];
	    		printf("%d\n", ans);
	    	}else{
	    		int k;
	    		scanf("%d", &k);
	    		int lc = lca(a, b);
	    		int left = level[a]-level[lc]+1;
	    		if(k <= left)
	    			printf("%d\n", kth(a, k-1));
	    		else
	    			printf("%d\n", kth(b, (level[b]-level[lc])-(k-left)));
	    	}
	    }
	    printf("\n");
	}
    return 0;
}