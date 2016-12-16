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


int main(){
    io;
    int t;
    cin >> t;
    while(t--){
    	ll a, b, c, n;
    	cin >> a >> b >> c >> n;
    	priority_queue<int, vi, less<int> > lowers;
    	priority_queue<int, vi, greater<int> > uppers;
    	lowers.push(1);
    	ll f = 1;
    	ll sum = 1;
    	int fsize = 1;
    	int ssize = 0;
    	for(int i = 2;i <= n; i++){
  			ll m = lowers.top();
    		f = a*m + b*i + c;
    		if(f >= MOD)
    			f %= MOD;	
    		sum += f;
    		if(ssize < fsize){
    			if(f < lowers.top()){
    				int ele = lowers.top();
    				lowers.pop();
    				uppers.push(ele);
    				lowers.push(f);
    			}else{
    				uppers.push(f);
    			}
    			ssize++;
    		}else{
    			if(f > uppers.top()){
    				lowers.push(uppers.top());
    				uppers.pop();
    				uppers.push(f);
    			}else{
    				lowers.push(f);
    			}
    			fsize++;
    		}
    		// if(f < lowers.top()){
    		// 	lowers.push(f);
    		// }else{
    		// 	uppers.push(f);
    		// }
    		// if(lowers.size()-uppers.size() >= 2){
    		// 	uppers.push(lowers.top());
    		// 	lowers.pop();
    		// }
    		// if(uppers.size()-lowers.size() >= 2){
    		// 	lowers.push(uppers.top());
    		// 	uppers.pop();
    		// }
    	}
    	cout << sum << endl;
    }
    return 0;
}
