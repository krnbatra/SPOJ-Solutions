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
#define F first
#define S second
#define FILL(arr, val)  memset(arr, val, sizeof(arr))
#define read(arr, n)    for(int i = 0;i < n; i++)cin>>arr[i];
#define sp ' '

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

set<ii> visited;

bool check(ii p){
	if(visited.find(p) == visited.end())
		return true;
	else
		return false;
}

int bfs(int a, int b, int c){
	queue<ii> Q;
	Q.push({0,0});
	Q.push({-1,-1});
	int count = 0;
	while(Q.size() > 1){
		ii p = Q.front();
		Q.pop();
		// cout << p.F << sp << p.S << endl;
		if(p.F == c || p.S == c)
			return count;
		if(p.F == -1 && p.S == -1){
			count++;
			Q.push({-1,-1});
			continue;
		}
		if(visited.find(p) != visited.end())
			continue;
		visited.insert({p.F, p.S});
		int x = p.F;
		int y = p.S;
		ii p1 = {0, y};
		ii p2 = {a, y};
		ii p3 = {x, b};
		ii p4 = {x - min(x, b-y), y + min(x, b-y)};
		ii p5 = {x + min(a-x, y), y - min(a-x, y)};
		ii p6 = {x, 0};
		if(check(p1))
			Q.push(p1);
		if(check(p2))
			Q.push(p2);
		if(check(p3))
			Q.push(p3);
		if(check(p4))
			Q.push(p4);
		if(check(p5))
			Q.push(p5);
		if(check(p6))
			Q.push(p6);
	}
	return -1;
}


int main(){
	io;
	int t;
	cin >> t;
	while(t--){
		int a, b, c;
		cin >> a >> b >> c;
		cout << bfs(a, b, c) << endl;
		visited.clear();
	}
	return 0;
}