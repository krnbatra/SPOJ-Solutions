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

const int MAXN = 2e4+5;
int BIT[MAXN];

void update(int idx, int val){
	while(idx <= 20000){
		BIT[idx] += val;
		idx += idx&-idx;
	}
}

int query(int idx){
	int sum = 0;
	while(idx > 0){
		sum += BIT[idx];
		idx -= idx&-idx;
	}
	return sum;
}

int main(){
    io;
    int t;
    cin >> t;
    while(t--){
    	int n;
    	cin >> n;
    	for(int i = 1;i <= n; i++)
    		update(i, 1);

    	int remaining = n;
    	int ahead = 1;
    	vector<int> ans(n+1);
    	for(int i = 1;i <= n; i++){
    		ahead = (ahead+i)%remaining;
    		if(ahead == 0)
    			ahead = remaining;
    		remaining--;
    		int lo = 0, hi = n;
    		while(hi-lo > 1){
    			int mid = (lo+hi) >> 1;
    			if(query(mid) >= ahead)
    				hi = mid;
    			else
    				lo = mid;
    		}
    		ans[hi] = i;
    		update(hi, -1);
    	}
    	for(int i = 1;i < ans.size(); i++)
    		cout << ans[i] << " ";
    	cout << endl;
    }
    return 0;
}