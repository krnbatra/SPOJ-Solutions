#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAXN = 2e2+5;

int n, m;
int A[MAXN], B[MAXN];
int dp[MAXN][MAXN];

ll solve(int idx, int left){
	if(left < 0)	return 0;
	if(idx == 0){
		if(left >= A[0] && left <= B[0])	return 1LL;
		else	return 0LL;
	}
	if(dp[idx][left] != -1)
		return dp[idx][left];
	ll res = 0;
	for(int i = A[idx]; i <= B[idx]; i++){
		res += solve(idx - 1, left - i);
		res %= MOD;
	}
	return dp[idx][left] = res;
}

int main(){
	io;
	int t;
	cin >> t;
	while(t--){
		memset(dp, -1, sizeof dp);
		cin >> n >> m;
		for(int i = 0; i < n; i++)
			cin >> A[i] >> B[i];
		cout << solve(n-1, m) << endl;
	}
	return 0;
}