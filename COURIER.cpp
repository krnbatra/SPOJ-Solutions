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

const int MAXN = 1e2+5;
const int inf = 1 << 20;
int matrix[MAXN][MAXN];
int from[15], to[15];
int dp[1 << 13][105];

int solve(int mask, int prev, int p, int b){
    if(mask == ((1 << p) - 1))    return dp[mask][prev] = matrix[prev][b];
    if(dp[mask][prev] != -1)    return dp[mask][prev];
    int minn = INT_MAX;
    for(int i = 0;i < p; i++){
        if((mask & (1 << i)) == 0){
            int x = solve( (mask | (1 << i)), to[i], p, b) + matrix[prev][from[i]] + matrix[from[i]][to[i]];
            minn = min(minn, x);
        }
    }
    dp[mask][prev] = minn;
    return minn;
}

int main(){
    io;
    int t;
    cin >> t;
    while(t--){
        int n, m, b;
        cin >> n >> m >> b;
        for(int i = 1;i <= n; i++)
            for(int j = 1;j <= n; j++)
                matrix[i][j] = (i == j) ? 0 : inf;
        int u, v, w;
        for(int i = 0;i < m; i++){
            cin >> u >> v >> w;
            if(u != v){
                matrix[u][v] = min(matrix[u][v], w);
                matrix[v][u] = min(matrix[v][u], w);
            }
        }
        for(int k = 1; k <= n; k++){
            for(int i = 1; i <= n; i++){
                for(int j = 1;j <= n; j++)
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
        int q;
        cin >> q;
        int k = 0;
        for(int i = 0;i < q; i++){
            cin >> u >> v >> w;
            for(int j = 0; j < w; j++){
                from[k] = u;
                to[k] = v;
                k++;
            }
        }
        memset(dp, -1, sizeof dp);
        // dp[(1 << k) - 1][b]
        cout << solve(0, b, k, b) << endl;
    }
    return 0;
}