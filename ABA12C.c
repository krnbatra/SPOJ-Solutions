#include <bits/stdc++.h>
#include <string>
#define pb           push_back
#define Mod          1000000007
#define all(x)       x.begin(),x.end()
#define sz(x)        ((int)x.size())
#define gcd(a,b)     __gcd(a,b)
#define loop(i,n)    for((i)=0;(i)<(n);++(i))
#define loopr(i,a,b) for(i=(a);i<=(b);++i)
#define sf(n)        scanf("%d", &n)
#define sf2(a,b)     scanf("%d %d", &a, &b)
#define sl(n)        scanf("%lld",&n)
#define prl(n)       printf("%d\n",n)
#define prs(n)       printf("%d ",n)
#define prll(n)      printf("%lld\n",n)
#define prsl(n)      printf("%lld ",n)
#define ios          ios_base::sync_with_stdio(false)
#define fillu(arr,a) memset(arr,(a),sizeof(arr))
using namespace std;
typedef long long int ll;
ll power(ll x, ll y){ll t;if( y == 0)return 1;t=power(x,y/2);return (y%2==0)?t*t:x*t*t;}
ll powm(ll a, ll n, ll mod) {ll p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;}
typedef vector<int> vi;
typedef vector<ll> vl;
typedef map<int,int> mi;

int arr[105];
int dp[105][105][105];

int ans(int idx,int k,int n)
{
    if(idx<0&&k==0&&n>=-1)
        return 0;
    else if(idx<0||k<0||n<0)
        return INT_MAX/2;
    if(dp[idx][k][n]!=-1)
        return dp[idx][k][n];
    int fin;
    if(arr[idx]!=-1)
    fin = min(min(ans(idx-1,k,n),arr[idx]+ans(idx-1,k-idx-1,n-1)),arr[idx]+ans(idx,k-idx-1,n-1));
    else fin=ans(idx-1,k,n);
    dp[idx][k][n]=fin;
    return fin;
}

int main()
{
    int n,t,k,i,j,l;
    sf(t);
	while(t--)
    {
        sf2(n,k);
        fillu(dp,-1);
        loop(i,k)
        sf(arr[i]);
        if(ans(k-1,k,n)>=INT_MAX/2)
            printf("-1\n");
        else
        prl(ans(k-1,k,n));
    }
return 0;
}
