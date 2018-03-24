#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAXN = 3e5+5;

ll st[MAXN], dp[MAXN], cum[MAXN];

int main(){
	io;
	int t;
	cin >> t;
	while(t--){
		int n, l;
		cin >> n >> l;
		memset(dp, 0, sizeof dp);
		memset(cum, 0, sizeof cum);
		for(int i = 1;i <= n; i++)
			cin >> st[i];
		sort(st, st+n+1);
		int k = 1;
		ll ans = 0;
		for(int i = 1;i <= n; i++){
			while(k <= i && st[k] + l <= st[i])
				k++;
			dp[i] = (cum[k-1] + 1) % MOD;
			cum[i] = (cum[i-1] + dp[i]) % MOD;
			// cout << i << " " << cum[i] << " " << dp[i] << endl;
			ans = (ans + dp[i]) % MOD;
		}
		cout << ans << endl;
	}
	return 0;
}