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
#define si(a)   scanf("%d", &a) 
#define pi(a)   printf("%d\n", a)
 
template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}

const int MAXN = 2e3+5;
vector<int> adj[MAXN];
int gender[MAXN];

int dfs(int source){
	int res = 1;
	for(int i = 0;i < adj[source].size(); i++){
		int adjacent = adj[source][i];
		if(gender[adjacent] == gender[source])
			return 0;
		if(gender[adjacent] == 0){
			gender[adjacent] = -gender[source];
			res = res&dfs(adjacent);
		}
	}
	return res;
}

int main(){
    int sce;
    si(sce);
    for(int i = 1; i<= sce; i++){
    	int n;
    	si(n);	
    	int se;
    	si(se);
    	memset(gender, 0, sizeof(gender));
    	for(int j = 1; j < MAXN; j++){
    		adj[j].clear();
    	}
    	for(int j = 1;j <= se; j++){
    		int a, b;
    		si(a);
    		si(b);
    		adj[a].pb(b);
    		adj[b].pb(a);
    	}
    	int res = 1;
    	for(int j = 1;j <= n; j++){
    		if(gender[j] == 0){
    			gender[j] = 1;
    			res = res&dfs(j);
    		}
    	}
    	printf("Scenario #%d:\n", i);
    	if(!res){
    		printf("Suspicious bugs found!\n");
    	}else{
    		printf("No suspicious bugs found!\n");
    	}
    }
    return 0;
}