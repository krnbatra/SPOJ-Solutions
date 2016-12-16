/*My First Template :D*/
#include <bits/stdc++.h>
#include <limits.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
 
#define MOD (ll)1000000007
#define pb   push_back
#define EPS 1e-9
#define FOR(i,n)  for(int i = 0;i < n; i++)
#define FORE(i,a,b) for(int i = a;i <= b; i++)
#define pi(a)   printf("%d\n", a)
#define all(c)  c.begin(), c.end()
#define tr(container, it)   for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define gc getchar_unlocked
#define sdi(a, b)   si(a);si(b)
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'

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

const int MAXN = 4e5+5;
int parent[MAXN], nodes, edges, count1;
pair<long long, pair<int, int> > p[MAXN];
// int visited[MAXN];
// vector<int> adj[MAXN];

// void dfs(int source){
// 	visited[source] = 1;
// 	for(int i = 0;i < adj[source].size(); i++){
// 		if(!visited[adj[source][i]]){
// 			dfs(adj[source][i]);
// 		}
// 	} 
// }
void initialize(){
	for(int i = 0;i <= nodes; i++){
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

long long kruskal(pair<long long, pair<int, int> > p[]){
	int x, y;
	long long cost, minimumCost = 0;
	for(int i = 0;i < edges+count1; i++){
		x = p[i].second.first;
		y = p[i].second.second;
		cost = p[i].first;
		//check if the selected edge makes a cycle or not.
		if(root(x)!=root(y)){
			minimumCost += cost;
			union1(x, y);
		}
	}
	return minimumCost;
}

int main(){
	io;
	int t;
	cin>>t;
	while(t--){
		int x, y;
		long long weight, cost, minimumCost;
		cin>>nodes>>edges;
		// for(int i = 0;i <= nodes; i++){
		// 	adj[i].clear();
		// 	visited[i] = 0;
		// }
		initialize();
		int arr[nodes];
		FOR(i,nodes)	cin>>arr[i];
		count1 = 0;
		FOR(i,nodes)	if(arr[i] == 1)	count1++;
		int i;
		int k = 0;
		for(i = 0;i < edges; i++){
			cin>>x>>y>>weight;
			p[k] = make_pair(weight, make_pair(x, y));
			k++;
			// adj[x].pb(y);
			// adj[y].pb(x);
		}
		FOR(j,nodes){
			if(arr[j] == 1){
				p[k] = make_pair(0, make_pair(j+1,0));
				// adj[0].pb(j+1);
				// adj[j+1].pb(0);
				k++;
			}
		}
		// dfs(1);
		
		// for(auto i : roots){
		// 	cout<<i<<endl;
		// }
		
		// if(flag == 0){
			sort(p, p+edges+count1);
			minimumCost = kruskal(p);
			int flag = 0;
			set<int> roots;
			roots.clear();
			for(int i = 0 ;i < nodes; i++){
				// cout<<i<<endl;
				if(arr[i] == 1){
					roots.insert(root(i+1));
				}
			}
			// for()
			for(int i = 0;i < nodes; i++){
				// cout<<i<<endl;
				if(arr[i] == 0){
					int rootTemp = root(i+1);
					// cout<<rootTemp<<endl;
					if(roots.find(rootTemp) == roots.end()){
						flag= 1;
						cout<<"impossible"<<endl;
						break;
					}
				}
			}
			if(flag == 0)
				cout<<minimumCost<<endl;
		// }
	}
	return 0;
}