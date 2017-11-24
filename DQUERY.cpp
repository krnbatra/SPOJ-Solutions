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

const int N = 3e4+5;
const int M = 2e5+5;
const int SQN = sqrt(N) + 1;

int n, q;

struct query{
	int l, r;
	int idx;
	int block;
	query(){}
	query(int _l, int _r, int _id){
		l = _l;
		r = _r;
		idx = _id;
		block = l/SQN;
	}
	bool operator < (const query &b) const{
		if(block != b.block){
			return block < b.block;
		}
		return r < b.r;
	}
};

int arr[N];
query Q[M];
int print[M];
int cnt[1000005];

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n; i++){
		scanf("%d", arr+i);
	}
	cin >> q;
	for(int i = 1;i <= q; i++){
		int l, r;
		scanf("%d%d", &l, &r);
		Q[i] = query(l, r, i);
	}
	sort(Q+1, Q+1+q);
	int curl = 1, curr = 0;
	ll ans = 0;
	for(int i = 1;i <= q; i++){
		int l = Q[i].l;
		int r = Q[i].r;
		int id = Q[i].idx;
		while(curr < r){
			++curr;
			cnt[arr[curr]]++;
			if(cnt[arr[curr]] == 1)
				ans++;
		}
		while(curl > l){
			--curl;
			cnt[arr[curl]]++;
			if(cnt[arr[curl]] == 1)
				ans++;
		}
		while(curr > r){
			cnt[arr[curr]]--;
			if(cnt[arr[curr]] == 0)
				ans--;
			--curr;
		}
		while(curl < l){
			cnt[arr[curl]]--;
			if(cnt[arr[curl]] == 0)
				ans--;
			++curl;
		}
		print[id] = ans;
	}
	for(int i = 1; i <= q; i++)
		printf("%d\n", print[i]);
	return 0;
}