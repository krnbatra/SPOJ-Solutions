/*My First Template :D*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
 
#define MOD (ll)1000000007
#define pb   push_back
#define EPS 1e-9
#define FOR(i,n)  for(int i = 0;i < n; i++)
#define FORE(i,a,b) for(int i = a;i <= b; i++)
#define tr(container, it)   for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
#define F first
#define S second
#define sp ' '
# define M_PI   3.14159265358979323846

template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}

const int MAXN = 1e5+5;
int n;
vector<int> adj[MAXN];
int dp[2][MAXN];
bool vis[MAXN];

int solve(bool isPresent, int curr, int par){
	// cout << isPresent << sp << curr << sp << par << endl;
	if(dp[isPresent][curr] != 0)
		return dp[isPresent][curr];
	int ret = 0;
	if(isPresent == 0){
		for(int j = 0;j < adj[curr].size(); j++){
			if(adj[curr][j] != par)
				ret += solve(true, adj[curr][j], curr);
		}
	}else{
		ret = 1;
		for(int j = 0;j < adj[curr].size(); j++){
			if(adj[curr][j] != par){
				ret += min(solve(true, adj[curr][j], curr), solve(false, adj[curr][j], curr));
			}
		}
	}
	dp[isPresent][curr] = ret;
	return dp[isPresent][curr];
}

int main(){
    io;
    cin >> n;
    FORE(i,1,n-1){
    	int a, b;
    	cin >> a >> b;
    	adj[a].pb(b);
    	adj[b].pb(a);
    }
    memset(dp, 0, sizeof dp);
    solve(0, 1, -1);
    memset(vis, false, sizeof vis);
    solve(1, 1, -1);
    cout << min(dp[0][1], dp[1][1]) << endl;
    return 0;
}
