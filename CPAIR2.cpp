#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);

const int N = 5e4+5;
const int M = 5e4+5;
const int SQN = sqrt(N) + 1;
ll BIT[100005];

void update(int idx, ll val){
	while(idx <= 100000){
		BIT[idx] += val;
		idx += idx&-idx;
	}
}

ll query_bit(int idx){
	ll sum = 0;
	while(idx > 0){
		sum += BIT[idx];
		idx -= idx&-idx;
	}
	return sum;
}

struct query{
	int l, r;
	int idx;
	int block;
	query(){}
	query(int _l, int _r, int _id){
		l = _l;
		r = _r;
		block = _l/SQN;
		idx = _id;
	}
	bool operator < (const query &b) const{
		if(block != b.block)
			return block < b.block;
		return r < b.r;
	}
};

query Q[M];
ll print[M];
int n, q, k;
int arr[N];

int main(){
	io;
	cin >> n >> q >> k;
	for(int i = 1;i <= n; i++)
		cin >> arr[i];
	for(int i = 1;i <= q; i++){
		int l, r;
		cin >> l >> r;
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
			ans += query_bit(arr[curr]-abs(k));
			if(arr[curr]+abs(k)-1 <= 100000)
				ans += (query_bit(100000) - query_bit(arr[curr]+abs(k)-1));
			update(arr[curr], 1LL);
		}
		while(curl > l){
			--curl;
			ans += query_bit(arr[curl]-abs(k));
			if(arr[curl]+abs(k)-1 <= 100000)
				ans += (query_bit(100000) - query_bit(arr[curl]+abs(k)-1));
			update(arr[curl], 1LL);
		}
		while(curr > r){
			ans -= query_bit(arr[curr]-abs(k));
			if(arr[curr]+abs(k)-1 <= 100000)
				ans -= (query_bit(100000) - query_bit(arr[curr]+abs(k)-1));
			update(arr[curr], -1LL);
			--curr;
		}
		while(curl < l){
			ans -= query_bit(arr[curl]-abs(k));
			if(arr[curl]+abs(k)-1 <= 100000)
				ans -= (query_bit(100000) - query_bit(arr[curl]+abs(k)-1));
			update(arr[curl], -1LL);
			++curl;
		}
		print[id] = ans;
	}
	for(int i = 1;i <= q; i++)
		cout << print[i] << endl;
	return 0;
}