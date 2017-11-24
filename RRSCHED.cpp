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

const int MAXN = 5e4+5;

ll n;
pair<int, int> table[MAXN];
ll res[MAXN];
ll BIT[MAXN];

void update(int idx, ll val){
	while(idx <= 50000){
		BIT[idx] += val;
		idx += idx & -idx;
	}
}

ll query(int idx){
	ll sum = 0;
	while(idx > 0){
		sum += BIT[idx];
		idx -= idx & -idx;
	}
	return sum;
}

int main(){
	io;
	cin >> n;
	for(int i = 1;i <= n; i++){
		int x;
		cin >> x;
		table[i] = {x, i};
	}
	sort(table+1, table+n+1);
	for(int i = 1;i <= n; i++)
		update(i, 1);
	ll delta, tot = 0;
	for(int i = 1;i <= n; i++){
		delta = table[i].first - ((i > 1) ? table[i-1].first : 0);
		tot += (n-(i-1))*delta;
		res[table[i].second] = tot - (n-(i-1)) + query(table[i].second);
		update(table[i].second, -1);
	}
	for(int i = 1; i <= n; i++)
		cout << res[i] << endl;
	return 0;
}