#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 10000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAXN = 1e5+5;

int n, r;

int dp[105][105];

int solve(int idx, int left){
	if(left < 0)	return 0;
	if(left == 0)	return 1;
	if(idx >= r)	return 0;
	if(dp[idx][left] != -1)	return dp[idx][left];
	int res = 0;
	for(int i = 0; i <= left; i++){
		res += solve(idx + 1, left - i);
		res %= MOD;
	}
	return dp[idx][left] = res;
}

int main(){
	io;
	memset(dp, -1, sizeof dp);
	cin >> n >> r;
	if(r > n)
		cout << -1 << endl;
	else{
		n -= r;
		cout << solve(0, n) << endl;
	}
	return 0;
}