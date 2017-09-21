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
# define M_PI   3.14159265358979323846

template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}

const int MAXN = 16;
int n;


bool bit(int i, int mask){
	// ith bit is present in mask
	return (mask&(1<<i));
}

int countsetbits(int mask){
	return __builtin_popcount(mask);
}

int dp[(1 << MAXN)][MAXN];
int dp2[(1 << MAXN)][MAXN];
// dp2[mask][i] number of ways to get maximum perimeter for dp[mask][i]
int arr[MAXN];
int vis[MAXN];
int res = 0;

void dfs(int rect, int count1,int mask){
	// cout << arr[rect] << sp << count1 << sp << mask << endl;
	if(count1 <= 1){
		// cout << "HE" << endl;
		res++;
		return;
	}
	for(int i = 0;i < n; i++){
		if(!vis[i] && rect != i && dp[mask][rect] == dp[mask^(1<<rect)][i] + 2*(arr[rect]+1)-2*min(arr[i], arr[rect])){
			// cout << arr[rect] << sp <<  arr[i] << sp;
			// cout << (1<<count1)-1 << sp << (mask^(1<<rect)) << endl;
			vis[i] = true;
			dfs(i, count1-1, (mask^(1<<rect)));
			vis[i] = false;
		}
	}
}

int main(){
    io;
    while(1){
    	memset(vis, false, sizeof vis);
    	res = 0;
	    cin >> n;
	    if(n == 0)
	    	break;
	    FOR(i, n)	cin >> arr[i];
	    // dp[mask][i] be the max perimeter of figure formed from the subset of rectangles present in mask, having last rectangle as  arr[i]
	    for(int mask = 0;mask < (1 << n); mask++){
	    	for(int i = 0;i < n; i++){
	    		dp[mask][i] = -1;
	    		dp2[mask][i] = 0;
	    	}
	    }
	    for(int mask = 0;mask < (1 << n); mask++){
	    	for(int i = 0;i < n; i++){
	    		// if ith bit is present in mask and number of set bits in mask is 1 then dp[mask][i] = 1
	    		if(bit(i, mask) && countsetbits(mask) == 1){
	    			dp[mask][i] = 2*(arr[i]+1);
	    			dp2[mask][i] = 1;
	    		}
	    		if(countsetbits(mask) > 1 && bit(i, mask)){
	    			int maxidx = -1;
	    			vector<int> v;
	    			for(int j = 0; j < n; j++){
	    				if(bit(j, mask) && j!= i){
	    					if(dp[mask^(1<<i)][j] + 2*(arr[i]+1)-2*min(arr[i], arr[j]) > dp[mask][i]){
	    						maxidx = j;
	    						v.clear();
	    						v.pb(j);
	    					}else if(dp[mask^(1<<i)][j] + 2*(arr[i]+1)-2*min(arr[i], arr[j]) == dp[mask][i]){
	    						v.pb(j);
	    					}
	    					dp[mask][i] = max(dp[mask][i], dp[mask^(1<<i)][j] + 2*(arr[i]+1)-2*min(arr[i], arr[j]));
	    				}
	    			}
	    			for(auto k : v){
	    				dp2[mask][i] += dp2[mask^(1<<i)][k];
	    			}
	    		}
	    	}
	    }
	    // for(int mask = 0;mask < (1 << n); ++mask){
	    // 	for(int i = 0;i < n; i++){
	    // 		cout << dp[mask][i] << sp;
	    // 	}
	    // 	cout << endl;
	    // }
	    // cout << endl;
	    // for(int mask = 0;mask < (1 << n); ++mask){
	    // 	for(int i = 0;i < n; i++){
	    // 		cout << dp2[mask][i] << sp;
	    // 	}
	    // 	cout << endl;
	    // }
	    // cout << endl;
	    int ans = INT_MIN;
	    FOR(i, n){
	    	ans = max(ans, dp[(1<<n)-1][i]);
	    }
	    cout << ans << sp;
	    int res = 0;
	    FOR(i, n){
	    	if(dp[(1<<n)-1][i] == ans)
	    		res += dp2[(1<<n)-1][i]; 
	    }
	    cout << res << endl;
	    // finding number of permutations
	 //    int count = n;
	 //    vector<int> lastRectangles;
	 //    for(int i = 0;i < n; i++){
	 //    	if(dp[(1<<n)-1][i] == ans){
	 //    		lastRectangles.pb(i);
	 //    	}
	 //    }
	 //    for(auto rect : lastRectangles){
	 //    	vis[rect] = 1;
	 //    	dfs(rect, n, (1<<n)-1);
	 //    	memset(vis, false, sizeof vis);
		// }
		// cout << res << endl;
	}
    return 0;
}