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

const int MAXN = 1e3+5;
int last_idx[MAXN];

int main(){
	io;
	int n, m;
	cin >> n >> m;
	vector<int> arr[n];
	for(int i = 0;i < n; i++){
		for(int j = 0;j < m; j++){
			int foo;
			cin >> foo;
			arr[i].push_back(foo);
		}
	}
	for(int i = 0;i < n; i++)
		sort(arr[i].begin(), arr[i].end());
	int minn_diff = INT_MAX;
	while(1){
		int minn = INT_MAX;
		int maxx = INT_MIN;
		int idx = -1;
		for(int i = 0;i < n; i++){
			maxx = max(maxx, arr[i][last_idx[i]]);
			if(arr[i][last_idx[i]] < minn){
				minn = arr[i][last_idx[i]];
				idx = i;
			}
		}
		minn_diff = min(minn_diff, maxx-minn);
		last_idx[idx]++;
		if(last_idx[idx] == m)
			break;
	}
	cout << minn_diff << endl;
	return 0;
}