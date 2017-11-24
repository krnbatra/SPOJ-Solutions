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

ll dp[10][105][105][2];

int n;

ll solve(string &s, int idx, ll sumEven, ll sumOdd, int constructedPrefixIsEqualtoPrefix){
    if(dp[idx][sumEven][sumOdd][constructedPrefixIsEqualtoPrefix] != -1)
        return dp[idx][sumEven][sumOdd][constructedPrefixIsEqualtoPrefix];
    ll res = 0;
    if(idx == n){
        res = (sumEven-sumOdd == 1) ? 1 : 0;
    }else{
       if(constructedPrefixIsEqualtoPrefix){
            for(int i = 0; i <= s[idx]-'0'; i++){
                if(i == s[idx]-'0'){
                    // if(idx&1)
                    //     res += solve(s, idx+1, sumEven, sumOdd + i, 1);
                    // else
                        res += solve(s, idx+1, sumOdd, sumEven + i, 1);
                }
                else{
                    // if(idx&1)
                    //     res += solve(s, idx+1, sumEven, sumOdd + i, 0);
                    // else
                        res += solve(s, idx+1, sumOdd, sumEven + i, 0);
                }
            }
       }else{
            for(int i = 0;i < 10; i++){
                // if(idx&1)
                //     res += solve(s, idx+1, sumEven, sumOdd + i, 0);
                // else
                    res += solve(s, idx+1, sumOdd, sumEven + i, 0);
            }
       }
    }
    dp[idx][sumEven][sumOdd][constructedPrefixIsEqualtoPrefix] = res;
    return res;
}

ll f(string& a){
    ll sumOdd = 0;
    ll sumEven = 0;
    bool odd = true;
    for(int i = (int)a.size()-1; i >= 0; i--){
        if(odd){
            sumOdd += a[i] - '0';
            odd = false;
        }
        else{
            sumEven += a[i] - '0';
            odd = true;
        }
    }
    return (sumEven-sumOdd == 1);
}

int main(){
    io;
    int t;
    cin >> t;
    while(t--){
        cin >> a >> b;
        memset(dp, -1, sizeof dp);
        n = b.size();
        ll ansR = solve(b, 0, 0, 0, 1);
        memset(dp, -1, sizeof dp);
        n = a.size();
        ll ansL = solve(a, 0, 0, 0, 1);
        ll ans = ansR - ansL + f(a);
        cout << ans << endl;
    }
    return 0;
}