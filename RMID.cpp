#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
	io;
	// if even numbers then lower one is median
	int n;
	priority_queue<int, vector<int>, less<int> > lowers;	// max pq
	priority_queue<int, vector<int>, greater<int> > uppers;	// min pq
	vector<int> ans;
	while(cin >> n){
		if(n == 0){
			for(int i = 0; i < ans.size(); i++)
				cout << ans[i] << endl;
			cout << endl;
			ans.clear();
			while(!lowers.empty())	lowers.pop();
			while(!uppers.empty())	uppers.pop();			
		}
		else if(n == -1){
			int median = lowers.top();
			ans.push_back(median);
			lowers.pop();
			if(lowers.size() < uppers.size()){
				lowers.push(uppers.top());
				uppers.pop();
			}				
		}else{
			int curr = n;
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
	return 0;
}