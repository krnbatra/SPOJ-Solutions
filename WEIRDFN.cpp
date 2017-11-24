/*Let's get high :D*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define M_PI                3.14159265358979323846

template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}

const int MAXN = 1e5+5;

int main(){
	io;
	int t;
	cin >> t;
	while(t--){
		ll a, b, c, n;
		cin >> a >> b >> c >> n;
		priority_queue<int, vector<int>, less<int> > lowers;	// max pq
		priority_queue<int, vector<int>, greater<int> > uppers;	// min pq
		lowers.push(1);
		ll f = 1;
		ll sum = 1;
		for(int i = 2;i <= n; i++){
			ll median = lowers.top();
			f = (a*median + b*i + c);
			if(f >= MOD)
				f %= MOD;
			sum += f;
			// rebalancing
			if(uppers.size() < lowers.size()){
				if(f < lowers.top()){
					lowers.push(f);
					// difference more than 1
					uppers.push(lowers.top());
					lowers.pop();
				}else
					uppers.push(f);
			}else{
				// 	uppers size greater or equal
				if(f > uppers.top()){
					uppers.push(f);
					// remove min from uppers
					lowers.push(uppers.top());
					uppers.pop();
				}else
					lowers.push(f);
			}
		}
		cout << sum << endl;
	}
	return 0;
}