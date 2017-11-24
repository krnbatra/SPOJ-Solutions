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
ll dp[205][205][205];
ll n;
string s;

ll go(ll pos, ll one, ll zero){
    if(pos == n)    return ((one > zero) ? one+zero : 0);
    
    if(s[pos] == '1')
        one++;
    else
        zero++;
    if(dp[pos][one][zero] != -1)    return dp[pos][one][zero];
    
    ll ans = 0;
    if(one > zero){
        ll j = one + zero + go(pos+1, 0, 0);
        ll k = go(pos+1, one, zero);
        ans = max(j, k);
    }else{
        ll j = go(pos+1, 0, 0);
        ll k = go(pos+1, one, zero);
        ans = max(j, k);
    }
    dp[pos][one][zero] = ans;
    return dp[pos][one][zero];
}

int main(){
    io;
    int t;
    cin >> t;
    while(t--){
        cin >> n >> s;
        memset(dp, -1, sizeof dp);
        cout << go(0, 0, 0) << endl;
    }
    return 0;
}