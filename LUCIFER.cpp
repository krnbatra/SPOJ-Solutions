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

const int MAXN = 1e3+5;

string a, b;
int n;
int dp[12][100][100][2];

bool isPrime[MAXN];

void sieve(){
    memset(isPrime, true, sizeof isPrime);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2;i <= 1000; i++){
        if(isPrime[i]){
            for(int j = i*i;j <= 1000; j+=i)
                isPrime[j] = false;
        }
    }
}

ll solve(string &s, int idx, ll sumEven, ll sumOdd, int isPrefixEqual){
    if(dp[idx][sumEven][sumOdd][isPrefixEqual] != -1)
        return dp[idx][sumEven][sumOdd][isPrefixEqual];
    ll res = 0;
    if(idx == n){
        if(sumEven-sumOdd >= 0 && isPrime[sumEven-sumOdd])
            res = 1;
    }else{
        if(isPrefixEqual){
            for(int i = 0;i <= s[idx]-'0'; i++){
                if(i == s[idx]-'0'){
                    res += solve(s, idx+1, sumOdd, sumEven + i, 1);
                }else{
                    res += solve(s, idx+1, sumOdd, sumEven + i, 0);
                }
            }
        }else{
            for(int i = 0;i < 10; i++){
                res += solve(s, idx+1, sumOdd, sumEven + i, 0);
            }
        }
    }
    dp[idx][sumEven][sumOdd][isPrefixEqual] = res;
    return res;
}

int f(string &a){
    bool odd = true;
    ll sumOdd = 0, sumEven = 0;
    for(int i = (int)a.size()-1;i >= 0; i--){
        if(odd){
            sumOdd += a[i]-'0';
            odd = false;
        }else{
            sumEven += a[i]-'0';
            odd = true;
        }
    }
    return (sumEven-sumOdd >= 0 && isPrime[sumEven-sumOdd]);
}

int main(){
    io;
    sieve();
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