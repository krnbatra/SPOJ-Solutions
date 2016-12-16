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



const int MAXN = 2e5+5;
int parent[MAXN], buildings, streets;
pair<ll, pair<int, int> > p[MAXN];

void initialize(){
	for(int i = 0;i <= buildings; i++){
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

ll kruskal(pair<ll, pair<int, int> > p[]){
	int x, y;
	ll cost, minimumCost = 0;
	for(int i = 0;i < streets; i++){
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
	// int t;
	// cin>>t;
	while(1){

		// int price;
		cin>>buildings>>streets;
		if(buildings == 0 && streets == 0)
			break;

		ll weight, cost, minimumCost;
		initialize();
		int x,y;
		ll totalCost = 0;
		for(int i = 0;i < streets; i++){
			cin>>x>>y>>weight;
			totalCost += weight;
			p[i] = make_pair(weight, make_pair(x, y));
		}
		sort(p, p+streets);
		minimumCost = kruskal(p);
		ll ans = totalCost-minimumCost;
		cout<<ans<<endl;
	}
	return 0;
}
