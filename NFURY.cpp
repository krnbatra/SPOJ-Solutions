#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAXN = 1e5+5;

int dp[1005];

int main(){
	io;
	for(int i = 1;i <= 1000; i++)
		dp[i] = INT_MAX;
	dp[0] = 0;
	dp[1] = 1;
	for(int i = 2; i <= 1000; i++){
		for(int j = i;j >= 0; j--){
			if((i-(j*j)) >= 0)
			dp[i] = min(dp[i], 1 + dp[i - (j*j)]);
		}
	}
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout << dp[n] << endl;
	}
	return 0;
}