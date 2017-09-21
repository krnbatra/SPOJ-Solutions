/*1000000007LLet's get high :D*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define M_PI                3.14159265358979323846
#define NIL					0
#define INF 				1 << 28

template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}

const int MAXN = 1e5+5;
vector<int> adj[MAXN];
int n, m, match[MAXN], dist[MAXN];

bool bfs(){		// returns true if there is an augmenting path
	queue<int> q;
	for(int i = 1;i <= n; i++){
		if(match[i] == NIL){
			dist[i] = 0;
			q.push(i);
		}
		else
			dist[i] = INF;
	}
	dist[NIL] = INF;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		if(u != NIL){
			for(auto v : adj[u]){
				if(dist[match[v]] == INF){
					dist[match[v]] = dist[u] + 1;
					q.push(match[v]);
				}
			}
		}
	}
	return (dist[NIL] != INF);
}

// returns true if there is an augmenting path beginning with free vertex u
bool dfs(int u){
	if(u != NIL){
		for(auto v : adj[u]){
			if(dist[match[v]] == dist[u] + 1){
				if(dfs(match[v])){
					match[v] = u;
					match[u] = v;
					return true;
				}
			}
		}
		// if there is no augmenting path beginning with u.
		dist[u] = INF;
		return false;
	}
	return true;
}

int hopcroft_karp(){
	int matching = 0;
	// match is assumed to be NIL for all vertices
	while(bfs())
		for(int i = 1;i <= n; i++)
			if(match[i] == NIL && dfs(i))
				matching++;
	return matching;
}

int main(){
    io;
    int p;
    cin >> n >> m >> p;
    for(int i = 1;i <= p; i++){
    	int a, b;
    	cin >> a >> b;
    	b += n;
    	adj[a].push_back(b);
    }
    cout << hopcroft_karp() << endl;
    return 0;
}