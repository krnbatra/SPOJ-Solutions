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
const int MAXN = 1e2+5;
int p[MAXN];
int dp[MAXN][MAXN];
int MM(int start, int end){
    if(end <= start){
        return 0;
    }
    if(end-start == 1){
        return p[end]*p[start];
    }
    if(dp[start][end] != -1)
        return dp[start][end];
    int minn = INT_MAX;
    for(int i = start;i < end; i++){
        int sum1 = 0;
        for(int j = start; j <= i; j++){
            sum1+=p[j];
            sum1%=100;
        }
        int sum2 =0 ;
        for(int j = i+1;j <= end; j++){
            sum2+=p[j];
            sum2%=100;
        }
        minn = min(minn, MM(start, i)+MM(i+1, end) + sum1*sum2);
    }
    dp[start][end] = minn;
    return minn;
}
int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        memset(dp, -1, sizeof(dp));
        FOR(i,n)    cin >> p[i];
        if(n == 1){
            cout << 0 << endl;
        }else
            cout << MM(0,n-1) << endl;
    }
    return 0;
}
