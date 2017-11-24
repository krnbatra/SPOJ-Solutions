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
vector<pair<int, pair<int, int> > > table;
int BIT[MAXN];

void update(int idx, int val){
	while(idx <= 100000){
		BIT[idx] = min(BIT[idx], val);
		idx += idx&-idx;
	}
}

int query(int idx){
	int minn = 1 << 30;;
	while(idx > 0){
		minn = min(minn, BIT[idx]);
		idx -= idx&-idx;
	}
	return minn;
}

int main(){
    io;
    int t;
    cin >> t;
    while(t--){
    	int n;
    	cin >> n;
    	table.clear();
    	for(int i = 1;i <= 100000; i++)
    		BIT[i] = 1 << 30;;
    	for(int i = 0;i < n; i++){
    		int a, b, c;
    		cin >> a >> b >> c;
    		table.push_back({a,{b,c}});
    	}
    	sort(table.begin(), table.end());
    	int ans = 0;
    	for(int i = 0;i < n; i++){
    		int key = table[i].second.first;
    		int value = table[i].second.second;
    		int queryAns = query(key);
    		if(value < queryAns)
    			ans++;
    		update(key, value);
    	}
    	cout << ans << endl;
    }
    return 0;
}