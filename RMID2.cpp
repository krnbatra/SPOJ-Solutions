#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
	io;
	// if even numbers then lower one is median
	ll n;
	priority_queue<ll, vector<ll>, less<ll> > lowers;	// max pq
	priority_queue<ll, vector<ll>, greater<ll> > uppers;	// min pq
	vector<ll> ans;
	int t;
	cin >> t;
	while(t--){
		while(cin >> n){
			if(n == 0){
				for(ll i = 0; i < ans.size(); i++)
					cout << ans[i] << endl;
				cout << endl;
				ans.clear();
				while(!lowers.empty())	lowers.pop();
				while(!uppers.empty())	uppers.pop();
				break;	
			}
			else if(n == -1){
				ll median = lowers.top();
				ans.push_back(median);
				lowers.pop();
				if(lowers.size() < uppers.size()){
					lowers.push(uppers.top());
					uppers.pop();
				}				
			}else{
				ll curr = n;
				if(lowers.size() == 0 && uppers.size() == 0){
					lowers.push(curr);
					continue;
				}
				if(uppers.size() < lowers.size()){
					if(curr < lowers.top()){
						// difference more than 1
						lowers.push(curr);
						uppers.push(lowers.top());
						lowers.pop();
					}else
						uppers.push(curr);
				}else{
					// 	uppers size greater or equal
					if(curr > uppers.top()){
						uppers.push(curr);
						lowers.push(uppers.top());
						uppers.pop();
					}else
						lowers.push(curr);
				}
			}
		}
		
	}
	return 0;
}