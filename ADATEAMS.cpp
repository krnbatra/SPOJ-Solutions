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

const int MAXN = 1e6+5;
ll fact[MAXN], invp[MAXN];

void init(){
    fact[0] = 1, invp[0] = 1;
    for(int i = 1; i < MAXN; i++)
        fact[i] = (fact[i-1] * i) % MOD;
    invp[MAXN-1] = invFermat(fact[MAXN-1], MOD);
    for(int i = MAXN-2; i >= 1; i--)
        invp[i] = (invp[i+1] * (i+1)) % MOD;
}

ll nCr(int n, int r){
    if(r < 0 || r > n)  return 0;
    return (fact[n] * ((invp[n-r] * invp[r]) % MOD)) % MOD;
}

int main(){
    io;
    init();
    ll n, a, b, d;
    while(cin >> n){
    	cin >> a >> b >> d;
    	ll ans1 = nCr(n, a);
    	ll ans2 = nCr(b, d);
    	ll ans3 = mod_exp(ans2, a, MOD);
    	ll final_ans = ans1*ans3;
    	final_ans %= MOD;
    	cout << final_ans << endl;
    }
    return 0;
}