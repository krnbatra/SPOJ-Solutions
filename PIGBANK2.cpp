#include <bits/stdc++.h>
#include <string>
#define pb           push_back
#define Mod          1000000007
#define all(x)       x.begin(),x.end()
#define sz(x)        ((int)x.size())
#define gcd(a,b)     __gcd(a,b)
#define loop(i,n)    for((i)=0;(i)<(n);(i)++)
#define loopr(i,a,b) for(i=(a);i<=(b);i++)
#define sf(n)        scanf("%d", &n)
#define sf2(a,b)     scanf("%d %d", &a, &b)
#define sl(n)        scanf("%lld",&n)
#define prl(n)       printf("%d\n",n)
#define prs(n)       printf("%d ",n)
#define prll(n)      printf("%lld\n",n)
#define prsl(n)      printf("%lld ",n)
#define ios          ios_base::sync_with_stdio(false)
using namespace std;
typedef long long int ll;
ll power(ll x, ll y){ll t;if( y == 0)return 1;t=power(x,y/2);return (y%2==0)?t*t:x*t*t;}
ll powm(ll a, ll n, ll mod) {ll p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;}
typedef vector<int> vi;
typedef vector<ll> vl;
typedef map<int,int> mi;
ll coin[502];
ll val[502];
ll dp[502][10002];

ll findans(ll idx,ll wt)
{
   /* if(dp[idx][wt]!=-1)
        return dp[idx][wt];*/
    if(wt==0)
        return /*dp[idx][wt] = */0;
    else if(wt<0||idx<0)
        {
            /*dp[idx][wt] = 10000000000000000LL;
            return dp[idx][wt];*/
            return 10000000000000000;
        }
    else
    {
        if(dp[idx][wt]==-1)
        dp[idx][wt] =min(findans(idx-1,wt),findans(idx,wt-coin[idx])+val[idx]);
        return dp[idx][wt];
    }
}


int main()
{
    int i,j,k,W,w,n,a,b;
    int t;
    sf(t);
    while(t--)
    {
        int e,f;
        sf2(e,f);
        sf(n);
        loop(i,n)
        {
            sl(val[i]);sl(coin[i]);
        }

        ll wt=f-e;
        if(wt==0)
        {
            printf("The minimum amount of money in the piggy-bank is 0.\n");
            continue;
        }
        loop(i,502) loop(j,10002) dp[i][j]=-1;
        ll ans=0;ans=findans(n-1,wt);
       /* loop(i,n+1)
        {
            loop(j,wt+1)
            {
                prsl(dp[i][j]);
            }printf("\n");
        }*/
        if(ans<10000000000000000)
           printf("The minimum amount of money in the piggy-bank is %lld.\n",ans);
        else printf("This is impossible.\n");
        //cout<<ans<<endl;
    }


    return 0;
}

