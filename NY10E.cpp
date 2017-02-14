/*My First Template :D*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
 
#define MOD (ll)1000000007
#define pb   push_back
#define EPS 1e-9
#define FOR(i,n)  for(int i = 0;i < n; i++)
#define FORE(i,a,b) for(int i = a;i <= b; i++)
#define tr(container, it)   for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
#define F first
#define S second
#define sp ' '

template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}

ll dp[65][10];

int main(){
    io;
    for(int j = 0;j <= 9; j++)
            dp[0][j] = 1;
    for(int i = 1;i <= 64; i++){
        for(int j = 0;j <= 9; j++){
            for(int k = 0;k <= j; k++){
                dp[i][j] += dp[i-1][k];
            }
        }
    }
    int t;
    cin >> t;
    while(t--){
        int num;
        cin >> num;
        int len;
        cin >> len;        
        cout << num << sp << dp[len][9] << endl;
    }
    return 0;
}
