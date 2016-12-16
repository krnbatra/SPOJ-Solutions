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

int dp[10005][10005][3];

int f(int h, int a, int current){   //air represents 1, water 2, fire 3
    if(h <= 0 || a <= 0)
        return 0;
    if(dp[h][a][current] != -1)
        return dp[h][a][current];
    if(current == -1){
        int res = 1+f(h+3, a+2, 1);
        if(h > 5 && a > 10)
            res = max(res, 1+f(h-5, a-10, 2));
        if(h > 20)
            res = max(res, 1+f(h-20, a+5, 3));
        dp[h][a][current] = res;
        return res;
    }
    if(current == 1){
        int res = 0;
        if(h > 5 && a > 10)
            res = max(res, 1+f(h-5, a-10, 2));
        if(h > 20)
            res = max(res, 1+f(h-20, a+5, 3));
        dp[h][a][current] = res;
        return res;
    }
    else if(current == 2){
        int res = 1+f(h+3, a+2, 1);
        if(h > 20)
            res = max(res, 1+f(h-20, a+5, 3));
        dp[h][a][current] = res;
        return res;
    }
    else{
        int res = 1+f(h+3, a+2, 1);
        if(h > 5 && a > 10)
            res = max(res, 1+f(h-5, a-10, 2));
        dp[h][a][current] = res;
        return res;
    }
    return dp[h][a][current];
}
int main(){
    io;
    int t;
    cin >> t;
    while(t--){
        memset(dp, -1, sizeof(dp));
        int h, a;
        cin >> h >> a;
        cout << f(h, a, -1) << endl;
    }
    return 0;
}
