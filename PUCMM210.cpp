#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000003LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAXN = 1e6+5;

ll f[MAXN];
ll pre[MAXN];

int main(){
	io;
	f[1] = 1;
	for(ll i = 2;i <= 1000000; i++){
		f[i] = (f[i - 1] + (i*i*i*1LL) % MOD) % MOD;
	}
	pre[1] = 1;
	for(ll i = 2;i <= 1000000; i++)
		pre[i] = (pre[i-1] + f[i]) % MOD;
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout << pre[n] << endl;
	}
	return 0;
}