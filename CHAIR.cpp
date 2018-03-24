#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000003LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAXN = 1e5+5;

int N, K;

int dp[2][1001][501];

ll solve(int fi, int n, int k){
	if(k == K)	return 1;
	if(n > N)	return 0;
	if(n == N && fi)	return 0;
	if(dp[fi][n][k] != -1)	return dp[fi][n][k];
	ll res = 0;
	if(n == 1)	res += solve(1, n + 2, k + 1);
	else	res += solve(fi, n + 2, k + 1);
	res += solve(fi, n + 1, k);
	res %= MOD;
	return dp[fi][n][k] = res;
}

int main(){
	// io;
	// cin >> N >> K;
	memset(dp, -1, sizeof dp);
	scanf("%d %d", &N, &K);
	if(K > N/2){
		printf("0\n");
		// cout << 0 << endl;
	}
	else{
		int res = solve(0, 1, 0);
		// cout << res << endl;
		printf("%d\n", res);
	}
	return 0;
}