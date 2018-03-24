#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAXN = 1e6+5;

int dp[MAXN];

int main(){
	io;
	dp[2] = 1;
	dp[3] = 1;
	for(int i = 4;i <= 1000000; i++)
		dp[i] = (dp[i-2] + dp[i-3]) % MOD;
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout << dp[n] << endl;
	}
	return 0;
}