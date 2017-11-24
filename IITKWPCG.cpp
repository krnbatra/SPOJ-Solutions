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

const int MAXN = 1e5+5;
int parent[MAXN], n, m;
pair<ll, pair<int, int> > table[MAXN];	// table stores <ll, pair of ints>, weight and in between what n the edge is. 

// numbering of vertices from 1 to n.

void init(){
	for(int i = 1;i <= n; i++){
		parent[i] = i;
	}
}

int root(int x){
	while(parent[x] != x){
		parent[x] = parent[parent[x]];
		x = parent[x];
	}
	return x;
}

void union1(int x, int y){
	int root_a = root(x);
	int root_b = root(y);
	parent[root_a] = root_b;
}

ll kruskal(){
	ll minCost = 0;
	for(int i = 0;i < m; i++){
		int x = table[i].second.first;
		int y = table[i].second.second;
		ll cost = table[i].first;
		//check if the selected edge makes a cycle or not.
		if(root(x) != root(y)){
			minCost += cost;
			union1(x, y);
		}
	}
	return minCost;
}

int main(){
	io;
	int t;
	cin >> t;
	while(t--){
		cin >> n >> m;
		init();
		for(int i = 0;i < m; i++){
			int x, y;
			ll weight;
			cin >> x >> y >> weight;
			weight = log2(weight);
			table[i] = {weight, {x, y}};
		}
		sort(table, table+m);
		ll minCost = kruskal();
		cout << minCost+1 << endl;
	}
	return 0;
}