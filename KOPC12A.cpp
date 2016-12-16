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

int n;
ll height[10005];
ll cost[10005];
int isIncreasing(ll mid){
	//find cost at mid
	//find cost at (mid+1)
	ll ans1 = 0;
	ll ans2 = 0;
	for(int i = 0;i < n; i++){
		ans1 = ans1 + (cost[i]*(abs(height[i]-mid)));
		ans2 = ans2 + (cost[i]*(abs(height[i]-(mid+1))));
	}
	if(ans2 >= ans1)
		return 1;
	else
		return 0;
}

int main(){
    int t;
    si(t);
    while(t--){
    	// int n;
    	si(n);
    	// cout<<n<<endl;
    	// int height[n];
    	FOR(i, n)	cin>>height[i];
    	// int cost[n];
    	FOR(i, n)	cin>>cost[i];
    	ll minn = LONG_MAX, maxx = LONG_MIN;
    	for(int i = 0;i < n; i++){
    		minn = min(minn, height[i]);
    		maxx = max(maxx, height[i]);
    	}
    	// cout<<minn<<' '<<maxx<<endl;
    	ll lo = minn-1, hi = maxx;
    	while(hi-lo > 1){
    		ll mid = (hi+lo)/2;
    		// cout<<mid<<endl;
    		if(isIncreasing(mid)){
    			hi = mid;
    		}else{
    			lo = mid;
    		}
    	}
    	ll ans1 = 0;
		for(int i = 0;i < n; i++){
			ans1 = ans1 + (cost[i]*(abs(height[i]-hi)));
		}
		cout<<ans1<<endl;
    }
    return 0;
}