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

string a, b;

ll dp[15][105][2];

int n;

ll solve(string &s, int idx, ll sum, int constructedPrefixIsEqualtoPrefix){
    if(dp[idx][sum][constructedPrefixIsEqualtoPrefix] != -1)
        return dp[idx][sum][constructedPrefixIsEqualtoPrefix];
    ll res = 0;
    if(idx == n){
        res = sum;
    }else{
       if(constructedPrefixIsEqualtoPrefix){
            for(int i = 0; i <= s[idx]-'0'; i++){
                if(i == s[idx]-'0')
                    res += solve(s, idx+1, sum + s[idx]-'0', 1);
                else
                    res += solve(s, idx+1, sum + i, 0);
            }
       }else{
            for(int i = 0;i < 10; i++)
                res += solve(s, idx+1, sum + i, 0);
       }
    }
    dp[idx][sum][constructedPrefixIsEqualtoPrefix] = res;
    return res;
}

ll f(string& a){
    ll sum = 0;
    for(auto c : a){
        sum += c-'0';
    }
    return sum;
}

int main(){
    io;
    while(1){
        cin >> a >> b;
        if(a == "-1" && b == "-1")
            break;
        memset(dp, -1, sizeof dp);
        n = b.size();
        ll ansR = solve(b, 0, 0, 1);
        memset(dp, -1, sizeof dp);
        n = a.size();
        ll ansL = solve(a, 0, 0, 1);
        ll ans = ansR - ansL + f(a);
        cout << ans << endl;
    }
    return 0;
}