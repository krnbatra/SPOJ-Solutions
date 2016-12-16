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

char matrix[205][205];
int dp[2][205][205];

int rows, cols;
bool isValid(int x, int y){
    return (x >= 0 && x < rows && y >= 0 && y < cols);
}
int f(int x, int y, int dir){
    if(dp[dir][x][y] != -1)
        return dp[dir][x][y];
    int ans = 0;
    if(matrix[x][y] == 'T')
        ans+=1;
    if(dir == 1){
        int res = 0;
        if(isValid(x,y+1) && matrix[x][y+1] != '#'){
            res = max(res, f(x, y+1, 1));
        }
        if(isValid(x+1, y) && matrix[x+1][y] != '#'){
            res = max(res, f(x+1, y, 0));
        }
        ans += res;
    }else{
        int res = 0;
        if(isValid(x,y-1) && matrix[x][y-1] != '#'){
            res = max(res, f(x, y-1, 0));
        }
        if(isValid(x+1, y) && matrix[x+1][y] != '#'){
            res = max(res, f(x+1, y, 1));
        }
        ans += res;
    }
    dp[dir][x][y] = ans;
    return ans;
}

int main(){
    io;
    int t;
    cin >> t;
    while(t--){
        memset(dp, -1, sizeof(dp));
        cin >> rows >> cols;
        for(int i = 0;i < rows; i++){
            for(int j = 0;j < cols; j++){
                cin >> matrix[i][j];
            }
        }
        if(matrix[0][0] == '#')
            cout << 0 << endl;
        else
        cout <<  f(0, 0, 1) << endl;
    }
    return 0;
}
