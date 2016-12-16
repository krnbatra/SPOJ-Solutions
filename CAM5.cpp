/*My First Template :D*/
#include <bits/stdc++.h>
#include <limits.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
 
#define MOD (ll)1000000007
#define pb 	push_back
#define EPS 1e-9
#define FOR(i, n)	for(int i = 0;i < n; i++)
#define pi(a)   printf("%d\n", a)
#define all(c)  c.begin(), c.end()
#define tr(container, it)   for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define gc getchar_unlocked

template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}

void si(int &x){
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
const int MAXN = 1e5+5;
vector<int> adj[MAXN];
int visited[MAXN];

void dfs(int source){
	visited[source] = 1;
	for(int i = 0;i < adj[source].size(); i++){
		if(!visited[adj[source][i]])
			dfs(adj[source][i]);
	}
}


int main(){
    int t;
    si(t);
    while(t--){
    	int n;
    	si(n);
    	for(int i = 0;i < n; i++){
    		visited[i] = 0;
    		adj[i].clear();
    	}
    	int e;
    	si(e);
    	for(int i = 0;i < e; i++){
    		int a, b;
    		si(a);
    		si(b);
    		adj[a].pb(b);
    		adj[b].pb(a);
    	}
    	int ans = 0;
    	for(int i = 0;i < n; i++){
    		if(!visited[i]){
    			ans++;
    			dfs(i);
    		}
    	}
    	pi(ans);
    }
    return 0;
}