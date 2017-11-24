#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

const int N = 1e4+5;
const int M = 1e4+5;
const int SQN = sqrt(N) + 1;

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
ll arr[N];

ll mean[M], median[M], mode[M], n, q;

set<pair<int, int>, greater<pair<int, int> > > occ;
unordered_map<int, int> mapped;
ordered_set<pair<int, int> > T;

int get_med(int size){
	if(size&1)	return T.find_by_order(size/2)->first;
	else	return (T.find_by_order(size/2)->first+T.find_by_order(size/2-1)->first)/2;
}

int main(){
	scanf("%lld", &n);
	for(int i = 0; i < n; i++)
		scanf("%lld", arr+i);
	scanf("%lld", &q);
	for(int i = 0; i < q; i++){
		int l, r;
		scanf("%d%d", &l, &r);
		Q[i] = query(l, r, i);
	}
	sort(Q, Q+q);
	int curl = 0, curr = -1;
	ll sum = 0;
	int iter = 0;
	for(int i = 0; i < q; i++){
		int l = Q[i].l;
		int r = Q[i].r;
		int id = Q[i].idx;
		while(curr < r){
			++curr;
			T.insert({arr[curr], iter++});
			sum += arr[curr];
			occ.erase({mapped[arr[curr]], arr[curr]});
			mapped[arr[curr]]++;
			occ.insert({mapped[arr[curr]], arr[curr]});
		}
		while(curl > l){
			--curl;
			T.insert({arr[curl], iter++});
			sum += arr[curl];
			occ.erase({mapped[arr[curl]], arr[curl]});
			mapped[arr[curl]]++;
			occ.insert({mapped[arr[curl]], arr[curl]});
		}
		while(curr > r){
			T.erase(T.find_by_order(T.order_of_key({arr[curr], -1})));
			sum -= arr[curr];
			occ.erase({mapped[arr[curr]], arr[curr]});
			mapped[arr[curr]]--;
			occ.insert({mapped[arr[curr]], arr[curr]});
			--curr;
		}
		while(curl < l){
			T.erase(T.find_by_order(T.order_of_key({arr[curl], -1})));
			sum -= arr[curl];
			occ.erase({mapped[arr[curl]], arr[curl]});
			mapped[arr[curl]]--;
			occ.insert({mapped[arr[curl]], arr[curl]});
			++curl;
		}
		mean[id] = sum/(r-l+1);
		median[id] = get_med(r-l+1);
		mode[id] = occ.begin()->second;
	}
	for(int i = 0;i < q; i++)
		printf("%lld %lld %lld\n", mean[i], median[i], mode[i]);
	return 0;
}