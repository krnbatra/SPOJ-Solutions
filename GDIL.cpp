#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAXN = 1e5+5;

int main(){
	io;
	int t;
	cin >> t;
	while(t--){
		ll n, a, b, c;
		cin >> n >> a >> b >> c;
		ll res = 0;
		for(int i = 0;i <= a; i++){
			for(int j = 0;j <= b; j++){
				ll tot = i + j;
				if(tot <= n)
					res += min(c, n - tot) + 1;
			}
		}
		cout << res << endl;
	}
	return 0;
}