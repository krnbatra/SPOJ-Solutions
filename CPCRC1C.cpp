#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAXN = 1e5+5;

string a, b;
ll dp[12][105][2];
int n;

ll solve(string &s, int idx, ll sum, int isPrefixEqual){
	if(dp[idx][sum][isPrefixEqual] != -1)
		return dp[idx][sum][isPrefixEqual];
	ll res = 0;
	if(idx == n){
		return sum;
	}else{
		if(isPrefixEqual){
			for(int i = 0;i <= s[idx]-'0'; i++){
				if(s[idx]-'0' == i)
					res += solve(s, idx + 1, sum + i, 1);
				else
					res += solve(s, idx + 1, sum + i, 0);
			}
		}else{
			for(int i = 0;i <= 9; i++){
				res += solve(s, idx + 1, sum + i, 0);
			}
		}
	}
	dp[idx][sum][isPrefixEqual] = res;
	return res;
}

ll f(string &a){
	ll sum = 0;
	for(auto c : a){
		sum += c - '0';
	}
	return sum;
}

int main(){
	io;
	while(1){
		cin >> a >> b;
		if(a == "-1" && b == "-1")
			break;
		n = b.size();
		memset(dp, -1, sizeof dp);
		ll ansR = solve(b, 0, 0, 1);
		n = a.size();
		memset(dp, -1, sizeof dp);
		ll ansL = solve(a, 0, 0, 1);
		cout << ansR - ansL + f(a) << endl;
	}
	return 0;
}