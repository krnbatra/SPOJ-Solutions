/*My First Template :D*/
#include <bits/stdc++.h>
#include <limits.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
 
#define MOD (ll)1000000007
#define pb   push_back
#define EPS 1e-9
#define FOR(i,n)  for(int i = 0;i < n; i++)
#define FORE(i,a,b) for(int i = a;i <= b; i++)
#define pi(a)   printf("%d\n", a)
#define all(c)  c.begin(), c.end()
#define tr(container, it)   for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define gc getchar_unlocked
#define sdi(a, b)   si(a);si(b)
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
#define F first
#define S second

template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}

void si(int &x){
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

ll matrix[100005][3];
ll dp[100005][3];
int n;
const int INF = 1e6+5;
ll solve(int row, int col){
    if(row == 0 && (col == 0))
        return INF;
    if(row == 0 && col == 1)
        return matrix[0][1];
    if(row == 0 && col == 2){
        return matrix[0][1] + matrix[0][2];
    }
    if(dp[row][col] != -1)
        return dp[row][col];
    
    ll res;
    if(col == 1){
        res = matrix[row][col]+min(solve(row, 0), min(solve(row-1, 0), min(solve(row-1, 1) , solve(row-1, 2))));   
    }
    else if(col == 0){
        res = matrix[row][col]+min(solve(row-1, 0), solve(row-1, 1));
    }else{
        res = matrix[row][col]+min(solve(row, 1), min(solve(row-1, 1), solve(row-1, 2)));
    }
    dp[row][col] = res;
    return res;
}



int main(){
    io;
    int kase = 1;
    while(1){
        memset(dp, -1, sizeof(dp));
        memset(matrix, 0, sizeof(matrix));
        cin >> n;
        if(n == 0)
            break;
        for(int i = 0;i < n; i++){
            for(int j = 0;j < 3; j++){
                cin >> matrix[i][j];
            }
        }
        ll ans = solve(n-1, 1);
        cout << kase << ". " << ans << endl;
        kase++;
    }
    return 0;
}
