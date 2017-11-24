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
int n;
int dp[52][52][52][52][2];

int solve(string &s, int idx, int count3, int count6, int count9, int isPrefixEqual){
    if(dp[idx][count3][count6][count9][isPrefixEqual] != -1)
        return dp[idx][count3][count6][count9][isPrefixEqual];
    ll res = 0;
    if(idx == n){
        if(count3 == count6 && count6 == count9 && count3 > 0)
            res = 1;
    }else{
        if(isPrefixEqual){
            for(int i = 0;i <= s[idx]-'0'; i++){
                if(i == s[idx]-'0'){
                    if(i == 3){
                        res += solve(s, idx + 1, count3 + 1, count6, count9, 1);
                    }
                    else if(i == 6){
                        res += solve(s, idx + 1, count3, count6 + 1, count9, 1);
                    }
                    else if(i == 9){
                        res += solve(s, idx + 1, count3, count6, count9 + 1, 1);
                    }
                    else{
                        res += solve(s, idx + 1, count3, count6, count9, 1);
                    }
                    res %= MOD;
                }else{
                    if(i == 3){
                        res += solve(s, idx + 1, count3 + 1, count6, count9, 0);
                    }
                    else if(i == 6){
                        res += solve(s, idx + 1, count3, count6 + 1, count9, 0);
                    }
                    else if(i == 9){
                        res += solve(s, idx + 1, count3, count6, count9 + 1, 0);
                    }
                    else{
                        res += solve(s, idx + 1, count3, count6, count9, 0);
                    }
                    res %= MOD;
                }
            }
        }else{
            for(int i = 0;i < 10; i++){
                if(i == 3){
                    res += solve(s, idx + 1, count3 + 1, count6, count9, 0);
                }
                else if(i == 6){
                    res += solve(s, idx + 1, count3, count6 + 1, count9, 0);
                }
                else if(i == 9){
                    res += solve(s, idx + 1, count3, count6, count9 + 1, 0);
                }
                else{
                    res += solve(s, idx + 1, count3, count6, count9, 0);
                }
                res %= MOD;
            }
        }
    }
    dp[idx][count3][count6][count9][isPrefixEqual] = res;
    return res;
}

int f(string &a){
    int count3 = 0, count6 = 0, count9 = 0;
    for(auto c : a){
        if(c == '3')
            count3++;
        else if(c == '6')
            count6++;
        else if(c == '9')
            count9++;
    }
    return (count3 > 0 && count3 == count6 && count6 == count9) ? 1 : 0;
}

int main(){
    io;
    int t;
    cin >> t;
    while(t--){
        cin >> a >> b;
        memset(dp, -1, sizeof dp);
        n = b.size();
        ll ansR = solve(b, 0, 0, 0, 0, 1);
        memset(dp, -1, sizeof dp);
        n = a.size();
        ll ansL = solve(a, 0, 0, 0, 0, 1);
        ll ans = (ansR - ansL + f(a)) % MOD;
        if(ans < 0)
            ans += MOD;
        cout << ans << endl;
    }
    return 0;
}