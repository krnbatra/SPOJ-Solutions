#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAXN = 1e5+5;

string a, b;
int n;
ll dp[55][55][55][55][2];

ll solve(string &s, int index, int count3, int count6, int count9, int isPrefixEqual){
	if(dp[index][count3][count6][count9][isPrefixEqual] != -1)
		return dp[index][count3][count6][count9][isPrefixEqual];
	ll res = 0;
	if(index == n){
		if(count3 >= 1 && count3 == count6 && count6 == count9){
			// cout << index << " " << count3 << " " << count6 << " " << count9 << " " << isPrefixEqual << endl;
			// cout << count3 << " " << count6 << " " << count9 << endl;
			return 1LL;
		}
	}else{
		if(isPrefixEqual){
			for(int i = 0; i <= s[index]-'0'; i++){
				if(s[index]-'0' == i){
					res += solve(s, index + 1, (i == 3) ? count3 + 1 : count3, (i == 6) ? count6 + 1 : count6, (i == 9) ? count9 + 1 : count9, 1);
					res %= MOD;
				}else{
					res += solve(s, index + 1, (i == 3) ? count3 + 1 : count3, (i == 6) ? count6 + 1 : count6, (i == 9) ? count9 + 1 : count9, 0);
					res %= MOD;
				}
			}
		}else{
			for(int i = 0;i <= 9; i++){
				res += solve(s, index + 1, (i == 3) ? count3 + 1 : count3, (i == 6) ? count6 + 1 : count6, (i == 9) ? count9 + 1 : count9, 0);
				res %= MOD;
			}
		}
	}
	dp[index][count3][count6][count9][isPrefixEqual] = res;
	return res;
}

ll f(string &s){
	int count3 = 0, count6 = 0, count9 = 0;
	for(auto c : s){
		if(c == '3')		count3++;
		else if(c == '6')	count6++;
		else if(c == '9')	count9++;
	}
	return (count3 >= 1 && count3 == count6 && count6 == count9);
}


int main(){
	io;
	int t;
	cin >> t;
	while(t--){
		cin >> a >> b;
		memset(dp, -1, sizeof dp);
		n = b.size();
		ll ansR = solve(b,  0, 0, 0, 0, 1);
		memset(dp, -1, sizeof dp);
		n = a.size();
		ll ansL = solve(a, 0, 0, 0, 0, 1);
		ll ans = (ansR - ansL + f(a)) % MOD;
		ans = (ans + MOD) % MOD;
		cout << ans << endl;
	}
	return 0;
}