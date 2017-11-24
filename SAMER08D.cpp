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
int dp[MAXN][MAXN];

int main(){
    io;
    int n;
    while(1){
        memset(dp, 0, sizeof dp);
        cin >> n;
        if(n == 0)
            break;
        string s1, s2;
        cin >> s1 >> s2;
        for(int i = 1;i <= s1.size(); i++){
            for(int j = 1;j <= s2.size(); j++){
                int c = 1;
                while(i-c >= 0 && j-c >= 0 && s1[i-c] == s2[j-c]){
                    if(c >= n)
                        dp[i][j] = max(dp[i][j], c + dp[i-c][j-c]);
                    c++;
                }
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
                dp[i][j] = max(dp[i][j], dp[i][j-1]);
            }
        }
        cout << dp[s1.size()][s2.size()] << endl;
    }
    return 0;
}