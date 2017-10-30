/*input
1
5 60
5
3 36 120
10 25 129
5 50 250
1 45 130
4 20 119
*/
#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0);cin.tie(0)	
#define FOR(i, a, b) for(long long i = a;i < b; i++)		
#define rev(i, a, b) for(long long i = a;i > b; i--)		
#define si(a)   scanf("%d", &a) 					
#define pi(a)   printf("%d\n", a)					
typedef long long ll;
#define dbl long double		
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int,int> 
#define pll pair< ll , ll >
#define vpll vector< pll >		
#define all(v) v.begin(),v.end()				
#define pb push_back									//^
#define ff first										//^
#define ss second										//^
#define MOD (ll)1000000007								//^
#define M_PI 3.14159265358979323846
#define ednl endl
#define N 1000005
#define MAX 100005
#define EPS 1e-12
template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}

using namespace std;

ll OO, NN, n;
vector<ll> oxy(MAX, 0);
vector<ll> nit(MAX, 0);
vector<ll> wt(MAX, 0);


ll dp[22][80][1001];

ll go(ll OO, ll NN, ll m)
{
	if(m<0)
		return 0;
	if(OO<=0 && NN<=0)
		return 0;
	if(m>0)
	{
		ll a1 = wt[m] + go(OO-oxy[m], NN-nit[m], m-1);
		ll a2 = go(OO, NN, m-1);
		return min(a1, a2);
	}
	else
	{
		if(OO<=oxy[m] && NN<=nit[m])
			return wt[m];
		else
			return MAX;
	}

}

int main()
{
	fio;
	ll t;
	cin>>t;
	while(t--)
	{
		cin>>OO>>NN;
		cin>>n;
		memset(dp, MAX, sizeof(dp));
		FOR(i,0,n)
			cin>>oxy[i]>>nit[i]>>wt[i];

		FOR(i,0,OO+1)
		{
			FOR(j,0,NN+1)
			{
				dp[i][j][0] = MAX;
				if(i<=oxy[0] && j<=nit[0])
					dp[i][j][1] = wt[0];
				else
					dp[i][j][1] = MAX;
			}
		}
		
		FOR(i,0,n+1)
			dp[0][0][i] = 0;

		FOR(i,0,OO+1)
		{
			FOR(j,0,NN+1)
			{
				FOR(k,1,n+1)
				{
					ll a1 = wt[k-1] + dp[max((ll)0, i-oxy[k-1])][max((ll)0, j-nit[k-1])][k-1];
					ll a2 = dp[i][j][k-1];
					// if(i-oxy[k-1]>=0 && j-nit[k-1]>=0)
					// 	a1 += wt[k-1] + dp[i-oxy[k-1]][j-nit[k-1]][k-1];
					
					dp[i][j][k] =  min(a1, a2);
				}
			}
		}
		cout<<dp[OO][NN][n]<<endl;
		// cout<<go(OO, NN, n-1)<<endl;

	}

	return 0;
}
