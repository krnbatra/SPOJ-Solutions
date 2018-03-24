#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAXN = 1e5+5;


ll dp[11][2001];

ll solve(int n, int m){
	// cout << numbers << " " << curr << endl;
	if(n == 0)	return 1LL;
	if(m == 0)	return 0LL;
	if(dp[n][m] != -1)	return dp[n][m];
	ll res = 0;
	res += solve(n, m - 1);
	res += solve(n-1, m / 2);
	return dp[n][m] = res;
}

int main(){
	// io;
	int kase;
	scanf("%d", &kase);
	for(int i = 1; i <= kase; i++){
		int n, m;
		memset(dp, -1, sizeof dp);
		scanf("%d%d", &n, &m);
		printf("Data set %d: %d %d %lld\n", i, n, m, solve(n, m));
	}
	return 0;
}