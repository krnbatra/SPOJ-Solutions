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

int main(){
    io;
    ll fact[305];
    fact[0] = 1;
    for(int i = 1;i <= 300; i++){
    	fact[i] = (i*fact[i-1]) % MOD;
    }
    int n, w, t, r;
    cin >> n >> w >> t >> r;
    ll num = fact[w+t+r];
    ll den = (fact[w]*fact[t]) % MOD;
    den *= fact[r];
    den %= MOD;
    ll ans = num*invFermat(den, MOD);
    ans %= MOD;
    cout << ans << endl;
    return 0;
}