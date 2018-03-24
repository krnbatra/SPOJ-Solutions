#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAXN = 2e5+5;
map<ll, ll> compress;
ll cnt[MAXN];
pair<ll, ll> segments[MAXN], queries[MAXN];
ll tree[4*MAXN];

void build(int node, int start, int end){
	if(start > end)
		return;
	if(start == end){
		tree[node] = cnt[start];
		return;
	}
	int left = node << 1, right = left + 1;
	int mid = (start + end) >> 1;
	build(left, start, mid);
	build(right, mid + 1, end);
	tree[node] = max(tree[left], tree[right]);
}

ll query(int node, int start, int end, int l, int r){
	if(start > end || start > r || end < l)
		return -(ll)9e18;
	if(start >= l && end <= r)
		return tree[node];
	int left = node << 1, right = left + 1;
	int mid = (start + end) >> 1;
	return max(query(left, start, mid, l, r), query(right, mid + 1, end, l, r));
}

int main(){
	int n, q;
	scanf("%d", &n);
	for(int i = 0;i < n; i++){
		ll l, r;
		scanf("%lld%lld", &l, &r);
		segments[i].first = l;
		segments[i].second = r;
		compress[l] = compress[r] = 1LL;
	}
	scanf("%d", &q);
	for(int i = 0;i < q; i++){
		ll l, r;
		scanf("%lld%lld", &l, &r);
		queries[i].first = l;
		queries[i].second = r;
		compress[l] = compress[r] = 1LL;
	}
	int val = 1;
	for(auto &x :  compress){
		x.second = val++;
	}
	for(int i = 0;i < n; i++){
		cnt[compress[segments[i].first]]+=1;
		cnt[compress[segments[i].second]+1]-=1;
	}
	for(int i = 1;i < MAXN; i++)
		cnt[i] += cnt[i-1];
	build(1, 0, MAXN);
	for(int i = 0;i < q; i++){
		printf("%lld\n", query(1, 0, MAXN-1, compress[queries[i].first], compress[queries[i].second]));
	}
	return 0;
}