/*My First Template :D*/
#include <bits/stdc++.h>
#include <climits>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
 
#define INF 1000000000
#define MOD (ll)10000007
#define pb 	push_back
#define EPS 1e-9
#define FOR(i, n)	for(int i = 0;i < n; i++)
 
template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}

 
int t;
int main(){
    ll n, k;
    cin>>n>>k;
    while(n!=0 || k!=0){
        ll ans = 0;
        ans = (ans+mod_exp(n, k, MOD))%MOD;
        // cout<<ans<<endl;
        ans=(ans+mod_exp(n, n, MOD))%MOD;
        // cout<<ans<<endl;
        ll temp1 = (2*(mod_exp(n-1, n-1, MOD)))%MOD;
        ll temp2 = (2*(mod_exp(n-1, k, MOD)))%MOD;
        ans = (ans+(temp1+temp2)%MOD)%MOD;
        cout<<ans<<endl;
        cin>>n>>k;
    }
	return 0;
}